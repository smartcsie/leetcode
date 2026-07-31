#!/usr/bin/env python3
import sys
import os
import re
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

FILE_NUM_RE = re.compile(r'^Solution_0*(\d+)(_\d+)?\.cpp$', re.IGNORECASE)

def index_solution_dir(solution_dir):
    index = {}
    for fpath in glob.glob(os.path.join(solution_dir, '*.cpp')):
        fname = os.path.basename(fpath)
        m = FILE_NUM_RE.match(fname)
        if not m:
            continue
        num = int(m.group(1))
        suffix = m.group(2)
        index.setdefault(num, []).append((fname, suffix))
    return index

def find_correct_filename(true_number, recorded_file, candidates):
    if not candidates:
        return None, '資料夾裡完全找不到這個題號的任何 .cpp 檔案'

    m = FILE_NUM_RE.match(recorded_file or '')
    recorded_suffix = m.group(2) if m else None

    exact_suffix_matches = [f for f, suf in candidates if suf == recorded_suffix]
    if len(exact_suffix_matches) == 1:
        return exact_suffix_matches[0], '依題號 + 相同變體後綴比對成功'

    if len(candidates) == 1:
        return candidates[0][0], '依題號比對，資料夾內該題號只有一個檔案'

    return None, f'該題號有多個候選檔案 {[c[0] for c in candidates]}，無法自動判斷是哪一個變體'

def main():
    meta_dir = sys.argv[1] if len(sys.argv) > 1 else 'metadata'
    solution_dir = sys.argv[2] if len(sys.argv) > 2 else 'solution'

    sol_index = index_solution_dir(solution_dir)
    fixed = []
    unresolved = []

    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        base = os.path.basename(fpath).replace('.yml', '')
        try:
            true_number = int(base)
        except ValueError:
            continue

        with open(fpath, 'r', encoding='utf-8') as f:
            data = yaml.safe_load(f)

        file_changed = False
        for sol in data.get('solutions', []):
            recorded = sol.get('file', '')
            actual_path = os.path.join(solution_dir, recorded) if recorded else ''
            if recorded and os.path.exists(actual_path):
                continue

            candidates = sol_index.get(true_number, [])
            suggestion, reason = find_correct_filename(true_number, recorded, candidates)

            if suggestion:
                fixed.append((base, recorded, suggestion, reason))
                sol['file'] = suggestion
                file_changed = True
            else:
                unresolved.append((base, recorded, reason))

        if file_changed:
            with open(fpath, 'w', encoding='utf-8') as f:
                yaml.dump(data, f, allow_unicode=True, sort_keys=False)

    print(f"✓ 自動修正了 {len(fixed)} 筆：")
    for base, old, new, reason in fixed:
        print(f"  {base}.yml: '{old}' -> '{new}'  ({reason})")

    if unresolved:
        print(f"\n⚠️ 有 {len(unresolved)} 筆無法自動判斷，需要手動處理：")
        for base, old, reason in unresolved:
            print(f"  {base}.yml: '{old}'  -> {reason}")

if __name__ == '__main__':
    main()
