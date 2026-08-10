#!/usr/bin/env python3
"""
check_topic_classification.py — 粗篩每一題的「分類主題」跟「程式碼實際邏輯」
是否明顯對不上，列出候選讓你逐一確認，不會自動修改任何 metadata。

原理：
  1. 用 generate_site.py 裡現成的 GROUPS 規則，把目前掛的 topic
     換算成「應該屬於哪個大分類」（例如 array-min-max -> 🍱 Array）。
  2. 用一組關鍵字/程式碼結構特徵（見 SIGNALS），偵測 .cpp 程式碼裡
     有沒有「強烈暗示屬於某個大分類」的線索（例如出現 priority_queue
     -> 暗示 📚 Priority Queue；出現 TreeNode* -> 暗示 🌳 Tree）。
  3. 如果程式碼暗示的大分類，跟 topic 換算出來的大分類「完全兜不起來」，
     就列為候選，讓你自己判斷是不是分類錯了、還是這只是次要用到的技巧
     （例如 DP 解法裡也用了 sort 排序，不代表這題該歸類到 Sorting）。

⚠️ 這只是粗篩，SIGNALS 命中不代表分類一定錯，只代表「值得你看一眼」。
   請逐一打開題目確認解法邏輯後再決定要不要改分類。

用法（在 repo 根目錄執行，這支腳本要跟 generate_site.py 放在同一個
tools/ 資料夾底下，因為它會直接 import generate_site 來重用 GROUPS 規則）：
    python3 tools/check_topic_classification.py
"""
import glob
import os
import re
import sys

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
try:
    import generate_site as gs
except ImportError:
    print("找不到 generate_site.py，請確認這支腳本跟 generate_site.py 放在同一層")
    sys.exit(1)

META_DIR = "metadata"
SOLUTION_DIR = "solution"

# (regex, 暗示的大分類, 說明)
# 只放「一出現幾乎可以確定屬於某分類」的強訊號，避免太多雜訊。
SIGNALS = [
    (r'\bpriority_queue\s*<', '📚 Priority Queue', 'priority_queue'),
    (r'\bTreeNode\s*\*', '🌳 Tree', 'TreeNode*'),
    (r'\bListNode\s*\*', '⛓️ Linked List', 'ListNode*'),
    (r'\bUnionFind\b|unionByRank|\bunion\s*\(.*\)\s*{', '🕸️ Graph', 'UnionFind / union-by-rank'),
    (r'\bdp\s*\[|memo\s*\[|vector<vector<int>>\s*dp\b', '🧩 Dynamic Programming', 'dp[]/memo[]'),
    (r'lower_bound|upper_bound|\bbinary_search\s*\(', '🔍 Binary Search', 'lower_bound/upper_bound/binary_search'),
    (r'\bbacktrack\s*\(|\.pop_back\(\)\s*;\s*//.*回溯|回溯', '🔢 Backtracking', 'backtrack() / 回溯'),
    (r'\bmonotonic|單調(棧|堆疊|佇列)', '📚 Stack', '單調棧/單調佇列'),
    (r'std::sort\s*\(|ranges::sort\s*\(|\bsort\s*\(\s*\w+\.begin', '📊 Sorting', 'sort()'),
    (r'\bgraph\s*\[|adjacency|鄰接(串列|矩陣)', '🕸️ Graph', '鄰接串列/矩陣'),
]


def to_list(v):
    if v is None:
        return []
    if isinstance(v, str):
        return [v]
    return list(v)


def load_code(fname):
    if not fname:
        return ''
    path = os.path.join(SOLUTION_DIR, fname)
    if not os.path.exists(path):
        return ''
    with open(path, encoding='utf-8', errors='replace') as f:
        return f.read()


def main():
    findings = []
    for fpath in sorted(glob.glob(os.path.join(META_DIR, '*.yml'))):
        with open(fpath, encoding='utf-8') as f:
            data = yaml.safe_load(f)
        if not data:
            continue
        number = data.get('number')
        title = data.get('title', '')
        for sol in data.get('solutions', []) or []:
            topics = to_list(sol.get('topics'))
            if not topics:
                continue
            assigned_groups = {gs.group_for(t) for t in topics}

            code = load_code(sol.get('file'))
            if not code:
                continue

            hinted_groups = set()
            matched_signals = []
            for pattern, hinted_group, label in SIGNALS:
                if re.search(pattern, code):
                    hinted_groups.add(hinted_group)
                    matched_signals.append(label)

            # 只挑「程式碼有強訊號、但完全不在目前分類的大分類集合裡」的情況
            mismatched = hinted_groups - assigned_groups
            if mismatched:
                findings.append({
                    'number': number,
                    'title': title,
                    'file': sol.get('file', ''),
                    'topics': topics,
                    'assigned_groups': assigned_groups,
                    'hinted_groups': mismatched,
                    'signals': matched_signals,
                })

    print(f"=== 分類可能對不上的候選（{len(findings)} 筆）===\n")
    for f in findings:
        print(f"  {f['number']:04d}  {f['title']}  ({f['file']})")
        print(f"        目前 topics: {', '.join(f['topics'])}  -> 大分類: {', '.join(f['assigned_groups'])}")
        print(f"        程式碼疑似屬於: {', '.join(f['hinted_groups'])}（偵測到: {', '.join(f['signals'])}）")
        print()

    print(f"共 {len(findings)} 筆，這只是粗篩結果，不代表一定分類錯誤，")
    print("常見「誤報」情況：主要解法是 A 技巧，但程式碼裡也用到了 sort() 或其他次要技巧，")
    print("請逐一打開確認解法的『核心邏輯』是什麼，再決定要不要調整分類。")


if __name__ == '__main__':
    main()
