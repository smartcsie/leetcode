#!/usr/bin/env python3
"""
set_representative_tags.py

批次把指定題號設定成代表題（is_representative: true），並填上對應的
representative_tag 標籤。543、455 各自身兼兩個概念，這裡只能選一個
標籤（已在下面註解說明選擇理由），如果之後想更精確區分，需要另外
調整設計。

用法：
    python3 set_representative_tags.py [metadata_dir]        # dry-run
    python3 set_representative_tags.py [metadata_dir] --yes   # 真的套用
"""
import sys
import os
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

# (題號, 代表題標籤)
ENTRIES = [
    (1, 'unordered_map'),
    (217, 'unordered_set'),
    (20, 'stack'),
    (739, 'monotonic stack'),
    (239, 'monotonic queue'),
    (215, 'priority_queue max heap'),
    (23, 'priority_queue min heap'),
    (208, 'trie'),
    (136, 'XOR 消除'),
    (2317, 'accumulate XOR'),
    (191, 'Brian Kernighan'),
    (461, '__builtin_popcount'),
    (78, 'Bitmask Subset Enumeration'),
    (231, 'n & (n-1)'),
    (53, 'Kadane'),
    (70, 'Fibonacci'),
    (416, '0/1 Knapsack'),
    (322, 'Unbounded Knapsack'),
    (1143, 'LCS'),
    (300, 'LIS'),
    (543, 'DP on Tree'),  # 身兼 DP on Tree / DFS Global，選較具代表性的
    (62, 'DP on Grid'),
    (121, 'State Machine'),
    (1130, 'Interval DP'),
    (847, 'Bitmask DP'),
    (94, 'Inorder'),
    (144, 'Preorder'),
    (145, 'Postorder'),
    (102, 'BFS Level Order'),
    (112, 'DFS Path'),
    (113, 'DFS Backtracking'),
    (700, 'BST'),
    (105, 'Construction'),
    (200, 'DFS'),
    (994, 'BFS'),
    (207, 'Topological Sort'),
    (743, 'Dijkstra'),
    (547, 'Union Find'),
    (1584, 'MST'),
    (3512, 'accumulate sum'),
    (1979, 'GCD'),
    (1281, 'Digit Decomposition'),
    (204, 'Prime / Sieve'),
    (455, 'Sorting Decision'),  # 身兼 Sorting Decision / Fractional Knapsack，選較具代表性的
    (435, 'Interval Scheduling'),
    (2208, 'Priority Queue'),
]


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    meta_dir = args[0] if args else 'metadata'
    do_apply = '--yes' in sys.argv

    if not os.path.isdir(meta_dir):
        print(f"❌ 找不到資料夾: {meta_dir}")
        sys.exit(1)

    total_changes = 0
    missing_files = []

    for number, tag in ENTRIES:
        meta_path = os.path.join(meta_dir, f"{number:04d}.yml")
        if not os.path.exists(meta_path):
            missing_files.append(number)
            continue

        with open(meta_path, encoding='utf-8') as f:
            data = yaml.safe_load(f) or {}

        already_correct = (
            data.get('is_representative') is True
            and data.get('representative_tag') == tag
        )
        if already_correct:
            continue

        old_tag = data.get('representative_tag')
        print(f"  {number:>5} {data.get('title',''):<45} "
              f"is_representative -> true, representative_tag: {old_tag!r} -> {tag!r}")
        data['is_representative'] = True
        data['representative_tag'] = tag
        total_changes += 1

        if do_apply:
            with open(meta_path, 'w', encoding='utf-8') as f:
                yaml.dump(data, f, allow_unicode=True, sort_keys=False)

    print(f"\n{'=' * 60}")
    if missing_files:
        print(f"⚠️ 找不到 metadata 的題號（可能還沒收錄，跳過）：{missing_files}")
    if do_apply:
        print(f"完成：{total_changes} 題已設定代表題標籤。")
    else:
        print(f"這是 dry-run（{total_changes} 題會被異動），還沒有真的寫入。"
              f"確認沒問題後加 --yes 再跑一次：")
        print(f"  python3 {os.path.basename(__file__)} {meta_dir} --yes")


if __name__ == '__main__':
    main()
