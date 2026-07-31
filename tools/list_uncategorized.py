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
            topics = to_list(sol.get('topics'))
            if 'uncategorized' in topics:
                results.append({
                    'number': data.get('number'),
                    'title': data.get('title'),
                    'file': sol.get('file', ''),
                    'difficulty': sol.get('difficulty', ''),
                    'tags': ', '.join(to_list(sol.get('tags'))),
                })

    results.sort(key=lambda r: r['number'])

    print(f"共 {len(results)} 筆 uncategorized：\n")
    for r in results:
        print(f"{r['number']:>5} | {r['title']:<55} | {r['difficulty']} | {r['tags']}")

if __name__ == '__main__':
    main()
