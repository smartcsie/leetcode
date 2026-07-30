#!/usr/bin/env python3
import sys
import re

NEW_GROUPS_BLOCK = """GROUPS = [
    (r'^math', '🔢 Math'),
    (r'^prime', '🔢 Math'),
    (r'^bit-bitmask-subset-enumeration$', '📊 Bit Manipulation'),
    (r'^bit-manipulation', '📊 Bit Manipulation'),
    (r'^hamming-distance', '📊 Bit Manipulation'),
    (r'^string', '🔗 String'),
    (r'^interval$', '🍱 Array'),
    (r'^prefix-sum$', '🍱 Array'),
    (r'^array', '🍱 Array'),
    (r'^2d-array', '🍱 Array'),
    (r'^binary-search-tree$', '🌳 Tree'),
    (r'^binary-search', '🔍 Binary Search'),
    (r'^linked-list', '⛓️ Linked List'),
    (r'^fast-slow-pointers$', '👥 Pointers'),
    (r'^two-pointers', '👥 Pointers'),
    (r'^hash-table', '🔑 Hash Table'),
    (r'^stack$', '📚 Stack'),
    (r'^monotonic-stack$', '📚 Stack'),
    (r'^monotonic-queue$', '📚 Stack'),
    (r'^priority-queue$', '📚 Priority Queue'),
    (r'^quick-select$', '📚 Quick Select'),
    (r'^tree', '🌳 Tree'),
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
]"""

def main():
    path = sys.argv[1] if len(sys.argv) > 1 else 'generate_site.py'
    with open(path, 'r', encoding='utf-8') as f:
        content = f.read()

    pattern = re.compile(r'GROUPS = \[.*?\n\]', re.DOTALL)
    m = pattern.search(content)
    if not m:
        print("❌ 找不到 GROUPS = [ ... ] 區塊，請確認檔案內容")
        sys.exit(1)

    new_content = content[:m.start()] + NEW_GROUPS_BLOCK + content[m.end():]
    with open(path, 'w', encoding='utf-8') as f:
        f.write(new_content)
    print(f"✓ 已更新 {path} 裡的 GROUPS 對照表")

if __name__ == '__main__':
    main()
