#!/usr/bin/env python3
import sys
import os
import re
import glob

def fix_content(content):
    lines = content.split('\n')
    changed = False

    for idx, line in enumerate(lines):
        if '空間複雜度' not in line:
            continue
        pos_design = line.find('設計思路')
        pos_solution = line.find('解法思路')
        if pos_design == -1 and pos_solution == -1:
            continue

        if pos_design != -1 and (pos_solution == -1 or pos_design < pos_solution):
            label = '設計思路'
            label_pos = pos_design
        else:
            label = '解法思路'
            label_pos = pos_solution

        before = line[:label_pos].rstrip()
        after = line[label_pos + len(label):].lstrip('：: ')

        sentences = [s.strip() for s in re.split(r'。\s*', after) if s.strip()]

        new_lines = [before, ' *', f' * {label}：']
        for i, s in enumerate(sentences, 1):
            new_lines.append(f' * {i}. {s}。')

        lines[idx:idx + 1] = new_lines
        changed = True
        break

    return '\n'.join(lines), changed

def main():
    solution_dir = sys.argv[1] if len(sys.argv) > 1 else 'solution'
    fixed = []

    for fpath in sorted(glob.glob(os.path.join(solution_dir, '*.cpp'))):
        with open(fpath, 'r', encoding='utf-8', errors='replace') as f:
            content = f.read()
        new_content, changed = fix_content(content)
        if changed:
            with open(fpath, 'w', encoding='utf-8') as f:
                f.write(new_content)
            fixed.append(os.path.basename(fpath))

    print(f"✓ 修復了 {len(fixed)} 個檔案：")
    for f in fixed:
        print(f"  {f}")

if __name__ == '__main__':
    main()
