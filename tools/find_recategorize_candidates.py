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

    design_candidates = []
    game_candidates = []
    geo_candidates = []

    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, 'r', encoding='utf-8') as f:
            data = yaml.safe_load(f)

        number = data.get('number')
        title = data.get('title', '')
        for sol in data.get('solutions', []):
            tags = [t.lower() for t in to_list(sol.get('tags'))]
            topics = to_list(sol.get('topics'))
            current = ' / '.join(topics)

            tag_str = ' '.join(tags)
            title_lower = title.lower()

            if 'design' in tag_str:
                design_candidates.append((number, title, current))
            if 'game theory' in tag_str or 'game' in title_lower:
                game_candidates.append((number, title, current))
            if 'geometry' in tag_str:
                geo_candidates.append((number, title, current))

    def dump(label, items):
        print(f"\n===== {label}（共 {len(items)} 筆）=====")
        for num, title, current in items:
            print(f"  {num:>5} | {title:<50} | 目前分類: {current}")

    dump("design 候選", design_candidates)
    dump("math-game-theory 候選", game_candidates)
    dump("math-geometry 候選", geo_candidates)

if __name__ == '__main__':
    main()
