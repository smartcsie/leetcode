#!/usr/bin/env python3
"""
move_binary_search_topics.py

針對特定題號，把某個 topic slug 換成另一個 slug，用來修正
binary-search 分類裡個別題目分錯/分太粗的問題。跟 rename_topic.py
不同：rename_topic.py 是整批改名，這支只動「清單裡列出的特定題號」。

⚠️ 這支已經套用了之前 move_greedy_topics.py / move_dp_topics.py
踩過的兩個 bug 教訓：
  1. topics 若是「無中括號的純字串」（例如 topics: sorting），
     不能用 list(x or []) 轉換（會被拆成一個一個字元），要用 to_list()。
  2. number 欄位若是「帶引號的字串」（例如 number: '278'），
     要用 int() 正規化後再比對，不能直接用 == 比較。

用法：
    python3 move_binary_search_topics.py [metadata_dir]        # dry-run
    python3 move_binary_search_topics.py [metadata_dir] --yes   # 真的套用

    metadata_dir  預設 'metadata'

⚠️ 這三題目前還留在籠統的 binary-search，還沒討論過該怎麼分類，
這支腳本不會動它們：1608、2195、2529。之後想清楚了要不要細分，
可以再補進 MOVES 清單。
"""
import sys
import os
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

# (題號, 舊 topic, 新 topic)
MOVES = [
    # 移到 binary-search-find-left-bound
    (153, 'binary-search', 'binary-search-find-left-bound'),
    (154, 'binary-search', 'binary-search-find-left-bound'),
    (162, 'binary-search', 'binary-search-find-left-bound'),
    (278, 'binary-search', 'binary-search-find-left-bound'),
    (540, 'binary-search', 'binary-search-find-left-bound'),
    (852, 'binary-search', 'binary-search-find-left-bound'),
    (1351, 'binary-search', 'binary-search-find-left-bound'),

    # 移到 binary-search-find-right-bound
    (34, 'binary-search', 'binary-search-find-right-bound'),
    (34, 'binary-search-build-in', 'binary-search-find-right-bound'),

    # 移到 binary-search-on-answer
    (69, 'binary-search', 'binary-search-on-answer'),
    (378, 'binary-search', 'binary-search-on-answer'),
    (1201, 'binary-search', 'binary-search-on-answer'),
    (441, 'binary-search', 'binary-search-on-answer'),  # 如果還沒收錄這題，這行不會有作用

    # 搬出 binary-search，歸到真正的技巧分類
    (300, 'binary-search', 'dp-lis'),
    (1930, 'binary-search', 'greedy'),
    (108, 'binary-search', 'tree-construction'),
    (4, 'binary-search', 'two-pointers-same'),

    # 704、33、74、81、374、367 維持在籠統的 binary-search（精確值搜尋），
    # 不用搬，這裡不列規則
]


def to_list(value):
    """把 None 或單一字串安全轉成清單，避免字串被逐字元拆解成 list(str)。"""
    if value is None:
        return []
    if isinstance(value, str):
        return [value]
    return list(value)


def apply_move(topics, old_topic, new_topic):
    """回傳 (新的 topics list, 是否有變動)"""
    if old_topic not in topics:
        return topics, False
    new_topics = []
    changed = False
    for t in topics:
        if t == old_topic:
            changed = True
            if new_topic is not None and new_topic not in new_topics and new_topic not in topics:
                new_topics.append(new_topic)
        else:
            new_topics.append(t)
    return new_topics, changed


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    meta_dir = args[0] if args else 'metadata'
    do_apply = '--yes' in sys.argv

    if not os.path.isdir(meta_dir):
        print(f"❌ 找不到資料夾: {meta_dir}")
        sys.exit(1)

    moves_by_number = {}
    for number, old_topic, new_topic in MOVES:
        moves_by_number.setdefault(number, []).append((old_topic, new_topic))

    total_changes = 0
    files_changed = 0

    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, encoding='utf-8') as f:
            data = yaml.safe_load(f)
        if not data:
            continue
        try:
            number = int(data.get('number'))
        except (TypeError, ValueError):
            continue
        if number not in moves_by_number:
            continue

        title = data.get('title', '')
        file_changed = False

        for sol in data.get('solutions', []):
            topics = to_list(sol.get('topics'))
            for old_topic, new_topic in moves_by_number[number]:
                topics, changed = apply_move(topics, old_topic, new_topic)
                if changed:
                    action = f"{old_topic} → {new_topic}" if new_topic else f"移除 {old_topic}"
                    print(f"  {number:>5} {title:<45} [{sol.get('file','?')}] {action}")
                    total_changes += 1
                    file_changed = True
            sol['topics'] = topics

        if file_changed:
            files_changed += 1
            if do_apply:
                with open(fpath, 'w', encoding='utf-8') as f:
                    yaml.dump(data, f, allow_unicode=True, sort_keys=False)

    print(f"\n{'=' * 60}")
    if do_apply:
        print(f"完成：{files_changed} 個檔案、{total_changes} 處分類異動已套用。")
    else:
        print(f"這是 dry-run（{files_changed} 個檔案、{total_changes} 處會被異動），"
              f"還沒有真的寫入。確認沒問題後加 --yes 再跑一次：")
        print(f"  python3 {os.path.basename(__file__)} {meta_dir} --yes")
    print("\n提醒：1608、2195、2529 還留在籠統的 binary-search，還沒討論過怎麼分類，"
          "這支腳本沒有動它們。")


if __name__ == '__main__':
    main()
