#!/usr/bin/env python3
"""
move_greedy_topics.py

針對特定題號，把某個 topic slug 換成另一個 slug（或直接移除），
用來修正 greedy 分類裡個別題目分錯的問題。跟 rename_topic.py 不同：
rename_topic.py 是整批改名（所有用到這個 slug 的題目都改），這支只
動「清單裡列出的特定題號」，其他題目完全不受影響。

用法：
    python3 move_greedy_topics.py [metadata_dir]        # dry-run，只列出
    python3 move_greedy_topics.py [metadata_dir] --yes   # 真的套用

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
    # 移到 greedy-digit-construction
    (670, 'greedy', 'greedy-digit-construction'),
    (1323, 'greedy', 'greedy-digit-construction'),
    (1881, 'greedy', 'greedy-digit-construction'),
    (2231, 'greedy', 'greedy-digit-construction'),
    (2259, 'greedy', 'greedy-digit-construction'),
    (2578, 'greedy', 'greedy-digit-construction'),
    (3114, 'greedy', 'greedy-digit-construction'),

    # 移到 greedy-string-construction
    (984, 'greedy', 'greedy-string-construction'),
    (1576, 'greedy', 'greedy-string-construction'),
    (2182, 'greedy', 'greedy-string-construction'),
    (2864, 'greedy', 'greedy-string-construction'),
    (3216, 'greedy', 'greedy-string-construction'),

    # 移到 greedy-frequency-merging
    (409, 'greedy', 'greedy-frequency-merging'),
    (3014, 'greedy', 'greedy-frequency-merging'),

    # 移到 greedy-parity-contribution
    (453, 'greedy', 'greedy-parity-contribution'),
    (1005, 'greedy', 'greedy-parity-contribution'),
    (1247, 'greedy', 'greedy-parity-contribution'),
    (2745, 'greedy', 'greedy-parity-contribution'),

    # 移到 greedy-prefix-suffix
    (55, 'greedy', 'greedy-prefix-suffix'),
    (624, 'greedy', 'greedy-prefix-suffix'),
    (1529, 'greedy', 'greedy-prefix-suffix'),

    # 移到 greedy-coin-change（真正的找零錢題）
    (860, 'greedy', 'greedy-coin-change'),

    # 移到 greedy-selection-constraints
    (2554, 'greedy', 'greedy-selection-constraints'),

    # 移到 greedy-sorting-decision
    (3011, 'greedy', 'greedy-sorting-decision'),

    # 移出 greedy-coin-change，退回籠統的 greedy（技巧跟找零錢關聯薄弱）
    (1210, 'greedy-coin-change', 'greedy'),
    (1551, 'greedy-coin-change', 'greedy'),

    # 移到新分類 greedy-validity-repair（合法性檢查/修復類）
    (678, 'greedy', 'greedy-validity-repair'),
    (921, 'greedy', 'greedy-validity-repair'),
    (2116, 'greedy', 'greedy-validity-repair'),
    (2645, 'greedy', 'greedy-validity-repair'),

    # 移除重複分類：1405 同時掛在 greedy-exchange-argument 跟
    # greedy-string-construction，只保留後者
    (1405, 'greedy-exchange-argument', None),
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
            # new_topic 是 None，或已經存在於清單裡，就不重複加
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

    # 依題號建立索引，方便查檔案
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
