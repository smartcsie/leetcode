#!/usr/bin/env python3
"""
move_sorting_topics.py

針對特定題號，把某個 topic slug 換成另一個 slug，用來修正 sorting
分類裡個別題目分錯/分太粗的問題。跟 rename_topic.py 不同：
rename_topic.py 是整批改名（所有用到這個 slug 的題目都改），這支只
動「清單裡列出的特定題號」，其他題目完全不受影響。

164. Maximum Gap 先不處理（桶排序版還是基數排序版需要你確認），
確認後可以自己在下面 MOVES 加一行，或跟我說要加哪個。

用法：
    python3 move_sorting_topics.py [metadata_dir]        # dry-run，只列出
    python3 move_sorting_topics.py [metadata_dir] --yes   # 真的套用

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

# (題號, 舊 topic, 新 topic)
MOVES = [
    # 移到 sorting-custom-comparator（需要自訂比較規則）
    (179, 'sorting', 'sorting-custom-comparator'),
    (524, 'sorting', 'sorting-custom-comparator'),
    (1356, 'sorting', 'sorting-custom-comparator'),
    (1481, 'sorting', 'sorting-custom-comparator'),
    (1636, 'sorting', 'sorting-custom-comparator'),
    (2164, 'sorting', 'sorting-custom-comparator'),
    (2191, 'sorting', 'sorting-custom-comparator'),
    (2418, 'sorting', 'sorting-custom-comparator'),
    (2545, 'sorting', 'sorting-custom-comparator'),
    (3769, 'sorting', 'sorting-custom-comparator'),
    (3913, 'sorting', 'sorting-custom-comparator'),

    # 移到 sorting-counting-sort（值域已知且不大，用計數桶取代比較排序）
    (451, 'sorting', 'sorting-counting-sort'),
    (1051, 'sorting', 'sorting-counting-sort'),
    (1122, 'sorting', 'sorting-counting-sort'),
    (3016, 'sorting', 'sorting-counting-sort'),
    (3517, 'sorting', 'sorting-counting-sort'),

    # 移到 sorting-implementation（手刻排序演算法本身）
    (148, 'sorting', 'sorting-implementation'),
    (912, 'sorting', 'sorting-implementation'),

    # 移到 greedy-sorting-decision（排序後用貪心邏輯決定分組/選擇）
    (945, 'sorting', 'greedy-sorting-decision'),
    (2966, 'sorting', 'greedy-sorting-decision'),
    (3684, 'sorting', 'greedy-sorting-decision'),
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
    print("\n提醒：164 Maximum Gap 沒有處理，先確認你寫的是桶排序還是基數排序版本，"
          "再自己補一行 MOVES 或跟我說。")


if __name__ == '__main__':
    main()
