#!/usr/bin/env python3
"""
migrate_topic_index_to_metadata.py

一次性遷移：把目前 topic_index.md 手動維護的「主題 -> 代表題」對照表，
轉換成寫進 metadata/{題號}.yml 的 represents 欄位（題目層級，跟
attempts 同一層），之後 topic_index.md 就能完全由 generate_site.py
自動產生，不用再手動編輯。

用法：
    python3 migrate_topic_index_to_metadata.py [metadata_dir]        # dry-run
    python3 migrate_topic_index_to_metadata.py [metadata_dir] --yes   # 真的套用
"""
import sys
import os

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

# (group, label, 題號) —— 從目前的 topic_index.md 內容整理出來
ENTRIES = [
    # 資料結構 Data Structures
    ('資料結構 Data Structures', 'unordered_map', 1),
    ('資料結構 Data Structures', 'unordered_set', 217),
    ('資料結構 Data Structures', 'stack', 20),
    ('資料結構 Data Structures', 'monotonic stack', 739),
    ('資料結構 Data Structures', 'monotonic queue', 239),
    ('資料結構 Data Structures', 'priority_queue max heap', 215),
    ('資料結構 Data Structures', 'priority_queue min heap', 23),
    ('資料結構 Data Structures', 'trie', 208),
    ('資料結構 Data Structures', 'union find', 547),

    # 演算法 Algorithms
    ('演算法 Algorithms', 'Binary Search', 704),
    ('演算法 Algorithms', 'Binary Search Find Left Bound', 278),
    ('演算法 Algorithms', 'Binary Search Find Right Bound', 69),
    ('演算法 Algorithms', 'Binary Search on Answer', 1201),
    ('演算法 Algorithms', 'lower_bound / upper_bound', 34),
    ('演算法 Algorithms', 'Sieve of Eratosthenes', 204),
    ('演算法 Algorithms', 'KMP', 28),

    # Two Pointers
    ('Two Pointers', '對撞指針', 167),
    ('Two Pointers', '快慢指針', 141),
    ('Two Pointers', '滑動視窗（固定）', 219),
    ('Two Pointers', '滑動視窗（可變）', 3),

    # Bit Manipulation
    ('Bit Manipulation', 'XOR 消除', 136),
    ('Bit Manipulation', 'accumulate XOR', 2317),
    ('Bit Manipulation', 'Brian Kernighan', 191),
    ('Bit Manipulation', '__builtin_popcount', 461),
    ('Bit Manipulation', 'Bitmask Subset Enumeration', 78),
    ('Bit Manipulation', 'n & (n-1)', 231),

    # Dynamic Programming
    ('Dynamic Programming', 'Kadane', 53),
    ('Dynamic Programming', 'Fibonacci', 70),
    ('Dynamic Programming', '0/1 Knapsack', 416),
    ('Dynamic Programming', 'Unbounded Knapsack', 322),
    ('Dynamic Programming', 'LCS', 1143),
    ('Dynamic Programming', 'LIS', 300),
    ('Dynamic Programming', 'DP on Tree', 543),
    ('Dynamic Programming', 'DP on Grid', 62),
    ('Dynamic Programming', 'State Machine', 121),
    ('Dynamic Programming', 'Interval DP', 1130),
    ('Dynamic Programming', 'Bitmask DP', 847),

    # Tree
    ('Tree', 'Inorder', 94),
    ('Tree', 'Preorder', 144),
    ('Tree', 'Postorder', 145),
    ('Tree', 'BFS Level Order', 102),
    ('Tree', 'DFS Path', 112),
    ('Tree', 'DFS Global', 543),
    ('Tree', 'DFS Backtracking', 113),
    ('Tree', 'BST', 700),
    ('Tree', 'Construction', 105),

    # Graph
    ('Graph', 'DFS', 200),
    ('Graph', 'BFS', 994),
    ('Graph', 'Topological Sort', 207),
    ('Graph', 'Dijkstra', 743),
    ('Graph', 'Union Find', 547),
    ('Graph', 'MST', 1584),

    # Math
    ('Math', 'accumulate sum', 3512),
    ('Math', 'accumulate XOR', 136),
    ('Math', 'unique', 217),
    ('Math', 'GCD', 1979),
    ('Math', 'Digit Decomposition', 1281),
    ('Math', 'Prime / Sieve', 204),

    # Greedy
    ('Greedy', 'Sorting Decision', 455),
    ('Greedy', 'Interval Scheduling', 435),
    ('Greedy', 'Priority Queue', 2208),
    ('Greedy', 'Fractional Knapsack', 455),
]


def main():
    meta_dir = sys.argv[1] if len(sys.argv) > 1 and not sys.argv[1].startswith('--') else 'metadata'
    do_apply = '--yes' in sys.argv

    if not os.path.isdir(meta_dir):
        print(f"❌ 找不到資料夾: {meta_dir}")
        sys.exit(1)

    # 依題號分組，一次處理同一題底下的多個 represents 項目
    by_number = {}
    for group, label, number in ENTRIES:
        by_number.setdefault(number, []).append({'group': group, 'label': label})

    total_changes = 0
    missing_files = []

    for number, new_represents in sorted(by_number.items()):
        meta_path = os.path.join(meta_dir, f"{number:04d}.yml")
        if not os.path.exists(meta_path):
            missing_files.append(number)
            continue

        with open(meta_path, encoding='utf-8') as f:
            data = yaml.safe_load(f) or {}

        existing_represents = data.get('represents') or []
        existing_keys = {(r.get('group'), r.get('label')) for r in existing_represents}

        added = []
        for r in new_represents:
            key = (r['group'], r['label'])
            if key in existing_keys:
                continue
            r_with_flag = dict(r)
            r_with_flag['show_in_index'] = True  # 對應「加入主題索引」checkbox，遷移的舊資料一律打勾
            existing_represents.append(r_with_flag)
            added.append(r_with_flag)

        if not added:
            continue

        for r in added:
            print(f"  {number:>5} {data.get('title',''):<45} + represents: "
                  f"[{r['group']}] {r['label']}")
        total_changes += len(added)

        data['represents'] = existing_represents
        if do_apply:
            with open(meta_path, 'w', encoding='utf-8') as f:
                yaml.dump(data, f, allow_unicode=True, sort_keys=False)

    print(f"\n{'=' * 60}")
    if missing_files:
        print(f"⚠️ 找不到 metadata 的題號（可能還沒收錄，跳過）：{missing_files}")
    if do_apply:
        print(f"完成：{total_changes} 筆 represents 已寫入。")
    else:
        print(f"這是 dry-run（{total_changes} 筆會被異動），還沒有真的寫入。"
              f"確認沒問題後加 --yes 再跑一次：")
        print(f"  python3 {os.path.basename(__file__)} {meta_dir} --yes")


if __name__ == '__main__':
    main()
