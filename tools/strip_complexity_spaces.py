#!/usr/bin/env python3
"""
strip_complexity_spaces.py — 把 metadata/*.yml 的 time/space 欄位，以及
solution/*.cpp 註解裡的「時間複雜度：」「空間複雜度：」，
移除 O(...) 括號內的所有空格（括號外的文字完全不動）。

Usage:
    python3 strip_complexity_spaces.py metadata solution
"""
import sys
import os
import re
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

def strip_spaces_in_bigo(text):
    if text is None:
        return text
    result = []
    i, n = 0, len(text)
    while i < n:
        if text[i] == 'O' and i + 1 < n and text[i+1] == '(':
            depth = 1
            j = i + 2
            start_inner = j
            while j < n and depth > 0:
                if text[j] == '(':
                    depth += 1
                elif text[j] == ')':
                    depth -= 1
                j += 1
            inner_end = j - 1
            inner = text[start_inner:inner_end]
            result.append('O(' + inner.replace(' ', '') + ')')
            i = j
            continue
        result.append(text[i])
        i += 1
    return ''.join(result)

def fix_metadata(meta_dir):
    changed = 0
    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, 'r', encoding='utf-8') as f:
            data = yaml.safe_load(f)
        file_changed = False
        for sol in data.get('solutions', []):
            for field in ('time', 'space'):
                old = sol.get(field, '')
                new = strip_spaces_in_bigo(old) if old else old
                if new != old:
                    sol[field] = new
                    file_changed = True
        if file_changed:
            with open(fpath, 'w', encoding='utf-8') as f:
                yaml.dump(data, f, allow_unicode=True, sort_keys=False)
            changed += 1
            print(f"  metadata: {os.path.basename(fpath)}")
    print(f"metadata 修改了 {changed} 個檔案")

def fix_solution_comments(solution_dir):
    changed = 0
    pattern = re.compile(r'^(\s*\*\s*(?:時間複雜度|空間複雜度)[:：]\s*)(.+)$', re.MULTILINE)

    def repl(m):
        prefix, rest = m.group(1), m.group(2)
        return prefix + strip_spaces_in_bigo(rest)

    for fpath in sorted(glob.glob(os.path.join(solution_dir, '*.cpp'))):
        with open(fpath, 'r', encoding='utf-8', errors='replace') as f:
            content = f.read()
        new_content = pattern.sub(repl, content)
        if new_content != content:
            with open(fpath, 'w', encoding='utf-8') as f:
                f.write(new_content)
            changed += 1
            print(f"  solution: {os.path.basename(fpath)}")
    print(f"solution 修改了 {changed} 個檔案")

def main():
    meta_dir = sys.argv[1] if len(sys.argv) > 1 else 'metadata'
    solution_dir = sys.argv[2] if len(sys.argv) > 2 else 'solution'
    fix_metadata(meta_dir)
    fix_solution_comments(solution_dir)

if __name__ == '__main__':
    main()
