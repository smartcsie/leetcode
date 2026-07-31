#!/usr/bin/env python3
import sys
import os
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

def to_list(value):
    if value is None:
        return []
    if isinstance(value, str):
        return [value]
    return list(value)

def main():
    meta_dir = sys.argv[1] if len(sys.argv) > 1 else 'metadata'
    results = []

    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, 'r', encoding='utf-8') as f:
            data = yaml.safe_load(f)

        for sol in data.get('solutions', []):
            difficulty = sol.get('difficulty', '')
            tags = to_list(sol.get('tags'))

            issues = []
            if difficulty == '待補充' or not difficulty:
                issues.append(f'難度異常({difficulty!r})')
            if not tags:
                issues.append('標籤為空')
            if difficulty and not any(e in difficulty for e in ('🟢', '🟡', '🔴')):
                issues.append(f'難度格式不一致({difficulty!r})')

            if issues:
                results.append({
                    'number': data.get('number'),
                    'title': data.get('title'),
                    'file': sol.get('file', ''),
                    'issues': ', '.join(issues),
                })

    print(f"共 {len(results)} 筆有問題：\n")
    for r in results:
        print(f"{r['number']:>5} | {r['title']:<55} | {r['issues']}")

if __name__ == '__main__':
    main()
