#!/usr/bin/env python3
import sys
import os
import re
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml")
    sys.exit(1)

FIELD_RE = {
    '題目': re.compile(r'^\s*\*\s*題目[:：]\s*(.+)$'),
    '難度': re.compile(r'^\s*\*\s*難度[:：]\s*(.+)$'),
    '時間複雜度': re.compile(r'^\s*\*\s*時間複雜度[:：]\s*(.+)$'),
    '空間複雜度': re.compile(r'^\s*\*\s*空間複雜度[:：]\s*(.+)$'),
}

def parse_header(text):
    m = re.search(r'/\*\*(.*?)\*/', text, flags=re.DOTALL)
    if not m:
        return None
    block = m.group(1)
    fields = {}
    for line in block.splitlines():
        for key, pattern in FIELD_RE.items():
            fm = pattern.match(line)
            if fm:
                fields[key] = fm.group(1).strip()
    return fields

def slugify_title(title_en):
    slug = title_en.strip().lower()
    slug = re.sub(r"[^a-z0-9]+", '-', slug)
    slug = slug.strip('-')
    return slug

def split_title(raw_title, number):
    title = raw_title
    prefix = f"{number}."
    if title.startswith(prefix):
        title = title[len(prefix):].strip()
    elif title.startswith(str(number)):
        title = title[len(str(number)):].lstrip('. ').strip()
    en_part = re.split(r'\s*[（(]', title)[0].strip()
    return en_part

def main():
    if len(sys.argv) != 3:
        print("Usage: python3 add_new_solutions.py <solution_dir> <metadata_dir>")
        sys.exit(1)

    solution_dir, meta_dir = sys.argv[1], sys.argv[2]
    os.makedirs(meta_dir, exist_ok=True)

    existing_numbers = set()
    for fname in os.listdir(meta_dir):
        if fname.endswith('.yml'):
            existing_numbers.add(int(fname.replace('.yml', '')))

    created = []
    skipped = []

    for fpath in sorted(glob.glob(os.path.join(solution_dir, '*.cpp'))):
        fname = os.path.basename(fpath)
        m = re.match(r'Solution_0*(\d+)', fname)
        if not m:
            continue
        number = int(m.group(1))
        if number in existing_numbers:
            continue

        with open(fpath, 'r', encoding='utf-8', errors='replace') as f:
            text = f.read()
        fields = parse_header(text)
        if not fields or '題目' not in fields:
            skipped.append(fname)
            continue

        title_en = split_title(fields['題目'], number)
        url = f"https://leetcode.com/problems/{slugify_title(title_en)}/"

        meta = {
            'number': number,
            'title': title_en,
            'url': url,
            'solutions': [{
                'file': fname,
                'difficulty': fields.get('難度', ''),
                'tags': [],
                'topics': ['uncategorized'],
                'time': fields.get('時間複雜度', ''),
                'space': fields.get('空間複雜度', ''),
            }],
        }

        meta_path = os.path.join(meta_dir, f"{number:04d}.yml")
        with open(meta_path, 'w', encoding='utf-8') as f:
            yaml.dump(meta, f, allow_unicode=True, sort_keys=False)
        created.append(fname)
        existing_numbers.add(number)

    print(f"新建立 metadata: {len(created)} 個")
    for f in created:
        print(f"  {f}")
    if skipped:
        print(f"\n⚠️ 解析失敗，需要手動處理 ({len(skipped)} 個)：")
        for f in skipped:
            print(f"  {f}")

if __name__ == '__main__':
    main()
