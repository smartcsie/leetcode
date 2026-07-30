#!/usr/bin/env python3
import re
import sys
import os
from collections import OrderedDict

def slugify(text):
    text = re.sub(r'<[^>]+>', '', text)
    text = re.sub(r'[^\w\s-]', '', text, flags=re.UNICODE)
    text = text.strip().lower()
    text = re.sub(r'[\s_]+', '-', text)
    return text or 'section'

GROUPS = [
    (r'^math', '🔢 Math'),
    (r'^prime', '🔢 Math'),
    (r'^bit-manipulation', '📊 Bit Manipulation'),
    (r'^hamming-distance', '📊 Bit Manipulation'),
    (r'^string', '🔗 String'),
    (r'^array', '🍱 Array'),
    (r'^2d-array', '🍱 Array'),
    (r'^binary-search', '🔍 Binary Search'),
    (r'^interval$', '🗓️ Interval'),
    (r'^prefix-sum$', '🔍 Prefix Sum'),
    (r'^linked-list', '⛓️ Linked List'),
    (r'^fast-slow-pointers$', '👥 Pointers'),
    (r'^two-pointers', '👥 Pointers'),
    (r'^hash-table', '🔑 Hash Table'),
    (r'^stack$', '📚 Stack'),
    (r'^monotonic-stack$', '📚 Stack'),
    (r'^monotonic-queue$', '📚 Stack'),
    (r'^priority-queue$', '📚 Stack'),
    (r'^quick-select$', '📚 Stack'),
    (r'^tree', '🌳 Tree'),
    (r'^binary-search-tree$', '🌳 Tree'),
    (r'^trie$', '🌳 Tree'),
    (r'^dfs-bfs$', '🌳 Tree'),
    (r'^sorting', '📊 Sorting'),
    (r'^dynamic-programming', '🧩 Dynamic Programming'),
    (r'^knapsack-problem', '🧩 Dynamic Programming'),
    (r'^greedy$', '🧩 Greedy'),
    (r'^backtracking', '🔢 Backtracking'),
    (r'^negative-marking$', '🔢 Backtracking'),
    (r'sliding-window$', '🔢 Sliding Window'),
    (r'^sql$', '🔢 SQL'),
]

def group_for(slug):
    for pattern, title in GROUPS:
        if re.search(pattern, slug):
            return title
    return '📄 Other'

def main():
    if len(sys.argv) != 3:
        print("Usage: python3 split_docs.py <input.md> <output_docs_dir>")
        sys.exit(1)

    src_path = sys.argv[1]
    out_dir = sys.argv[2]
    os.makedirs(out_dir, exist_ok=True)

    with open(src_path, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    heading_re = re.compile(r'^##\s+(.*)$')
    heading_positions = []
    for i, line in enumerate(lines):
        m = heading_re.match(line)
        if m and not line.startswith('###'):
            heading_positions.append((i, m.group(1)))

    if not heading_positions:
        print("No '##' headings found.")
        sys.exit(1)

    preamble = lines[:heading_positions[0][0]]
    with open(os.path.join(out_dir, 'index.md'), 'w', encoding='utf-8') as f:
        f.writelines(preamble)
    print(f"Wrote index.md ({len(preamble)} lines)")

    used_slugs = {}
    nav_entries = OrderedDict()

    for idx, (start, heading_text) in enumerate(heading_positions):
        end = heading_positions[idx + 1][0] if idx + 1 < len(heading_positions) else len(lines)
        section_lines = lines[start:end]

        anchor_match = re.search(r'<a name="([^"]+)">', heading_text)
        if anchor_match:
            slug = slugify(anchor_match.group(1))
        else:
            slug = slugify(heading_text)

        if slug in used_slugs:
            used_slugs[slug] += 1
            slug = f"{slug}-{used_slugs[slug]}"
        else:
            used_slugs[slug] = 1

        filename = f"{slug}.md"
        with open(os.path.join(out_dir, filename), 'w', encoding='utf-8') as f:
            f.writelines(section_lines)

        clean_heading = re.sub(r'<[^>]+>', '', heading_text).strip()
        group_title = group_for(slug)
        nav_entries.setdefault(group_title, []).append((clean_heading, filename))
        print(f"Wrote {filename}  <-  {clean_heading}")

    print("\n\n----- Paste this into mkdocs.yml under `nav:` -----\n")
    print("nav:")
    print("  - 首頁: index.md")
    for group_title, items in nav_entries.items():
        print(f"  - {group_title}:")
        for heading, filename in items:
            safe_heading = heading.replace(':', ' -')
            print(f"      - {safe_heading}: {filename}")

if __name__ == '__main__':
    main()
