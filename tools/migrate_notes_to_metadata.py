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

def load_note_sections(notes_path):
    with open(notes_path, 'r', encoding='utf-8', errors='replace') as f:
        text = f.read()
    parts = re.split(r'^### 解法（([^）]*)）\s*$', text, flags=re.MULTILINE)
    sections = {}
    for i in range(1, len(parts), 2):
        label = parts[i]
        body = parts[i + 1] if i + 1 < len(parts) else ''
        body = re.sub(r'\n-{3,}\s*$', '', body).strip()
        if body:
            sections[label] = body
    return sections

def main():
    meta_dir = sys.argv[1] if len(sys.argv) > 1 else 'metadata'
    notes_dir = sys.argv[2] if len(sys.argv) > 2 else 'notes'

    migrated = []
    unmatched = []

    for note_path in sorted(glob.glob(os.path.join(notes_dir, '*.md'))):
        base = os.path.basename(note_path).replace('.md', '')
        meta_path = os.path.join(meta_dir, f'{base}.yml')

        if not os.path.exists(meta_path):
            unmatched.append((base, '找不到對應的 metadata 檔案'))
            continue

        sections = load_note_sections(note_path)
        if not sections:
            continue

        with open(meta_path, 'r', encoding='utf-8') as f:
            data = yaml.safe_load(f)

        solutions = data.get('solutions', [])
        changed = False

        if len(solutions) == 1:
            combined = '\n\n---\n\n'.join(sections.values())
            solutions[0]['note'] = combined
            changed = True
            migrated.append((base, '單一解法，直接附加'))
        else:
            matched_labels = set()
            for sol in solutions:
                label_key = ' / '.join(sol.get('topics') or [])
                if label_key in sections:
                    sol['note'] = sections[label_key]
                    changed = True
                    matched_labels.add(label_key)
                    migrated.append((base, f'比對成功「{label_key}」'))

            leftover = set(sections.keys()) - matched_labels
            for label in leftover:
                unmatched.append((base, f'筆記標籤「{label}」比對不到任何解法（可能分類已改名）'))

        if changed:
            with open(meta_path, 'w', encoding='utf-8') as f:
                yaml.dump(data, f, allow_unicode=True, sort_keys=False)

    print(f"✓ 已遷移 {len(migrated)} 筆：")
    for base, reason in migrated:
        print(f"  {base}: {reason}")

    if unmatched:
        print(f"\n⚠️ 有 {len(unmatched)} 筆無法自動比對，需要手動處理：")
        for base, reason in unmatched:
            print(f"  {base}: {reason}")

if __name__ == '__main__':
    main()
