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

LINK_RE = re.compile(
    r'\[([^\]]*)\]\(\./solution-pages/Solution_0*(\d+)(?:_\d+)?\.md\)'
)

def fix_note(note):
    def repl(m):
        text, number = m.group(1), int(m.group(2))
        return f'[{text}](../problems/{number:04d}.md)'
    return LINK_RE.sub(repl, note)

def main():
    meta_dir = sys.argv[1] if len(sys.argv) > 1 else 'metadata'
    fixed = []

    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, 'r', encoding='utf-8') as f:
            data = yaml.safe_load(f)

        changed = False
        for sol in data.get('solutions', []):
            note = sol.get('note')
            if note and LINK_RE.search(note):
                new_note = fix_note(note)
                sol['note'] = new_note
                changed = True
                fixed.append((data.get('number'), sol.get('file', '')))

        if changed:
            with open(fpath, 'w', encoding='utf-8') as f:
                yaml.dump(data, f, allow_unicode=True, sort_keys=False)

    print(f"✓ 修正了 {len(fixed)} 筆解法的筆記連結：")
    for num, file in fixed:
        print(f"  {num}: {file}")

if __name__ == '__main__':
    main()
