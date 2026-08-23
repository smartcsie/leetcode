#!/usr/bin/env python3
"""
move_dp_topics.py

針對特定題號，把某個 topic slug 換成另一個 slug（或直接移除），用來
修正 DP 分類裡個別題目分錯的問題。跟 rename_topic.py 不同：
rename_topic.py 是整批改名（所有用到這個 slug 的題目都改），這支只
動「清單裡列出的特定題號」，其他題目完全不受影響。

用法：
    python3 move_dp_topics.py [metadata_dir]        # dry-run，只列出
    python3 move_dp_topics.py [metadata_dir] --yes   # 真的套用

    metadata_dir  預設 'metadata'
"""
import sys
import os
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

# (題號, 舊 topic, 新 topic)，新 topic 是 None 代表直接移除、不替換成別的
MOVES = [
    # 刪除重複分類：53 同時掛在 dp-kadane 跟籠統的 dynamic-programming，
    # 只保留 dp-kadane（這題就是 Kadane's Algorithm 的原型題）
    (53, 'dynamic-programming', None),

    # 刪除重複分類：674 同時掛在 dp 這邊的 dynamic-programming 跟
    # greedy 那邊，技巧上更接近單純掃描，只保留 greedy 那份
    (674, 'dynamic-programming', None),

    # 移出 dp-kadane（形狀完全對不上，不是「維護目前子陣列最大和」）
    (118, 'dp-kadane', 'dynamic-programming'),
    (1641, 'dp-kadane', 'dynamic-programming'),

    # 修正到 dp-bitmask（技能/帽子分配用 bitmask 解，跟數位 DP 無關）
    (1125, 'dp-digit', 'dp-bitmask'),
    (1434, 'dp-digit', 'dp-bitmask'),

    # 移到更貼切的既有分類
    (96, 'dynamic-programming', 'dp-interval'),      # 跟 95 同一個 Catalan number 結構
    (337, 'dynamic-programming', 'dp-tree'),         # 跟 968/1373/2246 同一組 Tree DP
    (2707, 'dynamic-programming', 'dp-knapsack'),    # 跟 139 Word Break 同一種轉移結構
]


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
        if not data or data.get('number') not in moves_by_number:
            continue

        number = data['number']
        title = data.get('title', '')
        file_changed = False

        for sol in data.get('solutions', []):
            topics = list(sol.get('topics') or [])
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


if __name__ == '__main__':
    main()
