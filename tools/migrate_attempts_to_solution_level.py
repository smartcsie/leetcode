#!/usr/bin/env python3
"""
migrate_attempts_to_solution_level.py

一次性遷移：把舊版存在「題目層級」（跟 number/title/url 同一層）的
attempts、is_representative、representative_tag 三個欄位，搬進
「解法層級」（solutions[i] 底下）。

搬到哪一個解法？優先順序：
    1. 標記 is_best 的那個解法
    2. 沒有的話，用第一個解法

因為舊資料是「整個題目共用一份」，這裡只能挑一個解法當歸屬，沒辦法
自動判斷「你當初其實是針對哪個解法在記錄練習歷程」，遷移完建議自己
檢查一下歸屬對不對，需要的話手動搬到別的解法變體。

用法：
    python3 migrate_attempts_to_solution_level.py [metadata_dir]        # dry-run
    python3 migrate_attempts_to_solution_level.py [metadata_dir] --yes   # 真的套用
"""
import sys
import os
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    meta_dir = args[0] if args else 'metadata'
    do_apply = '--yes' in sys.argv

    if not os.path.isdir(meta_dir):
        print(f"❌ 找不到資料夾: {meta_dir}")
        sys.exit(1)

    total_changes = 0

    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, encoding='utf-8') as f:
            data = yaml.safe_load(f)
        if not data:
            continue

        old_attempts = data.get('attempts')
        old_is_representative = data.get('is_representative')
        old_representative_tag = data.get('representative_tag')

        if not (old_attempts or old_is_representative or old_representative_tag):
            continue  # 這題完全沒有舊的題目層級資料，跳過

        solutions = data.get('solutions') or []
        if not solutions:
            continue  # 沒有任何解法可以搬過去，跳過（理論上不該發生）

        # 挑目標解法：優先 is_best，沒有就用第一個
        target = next((s for s in solutions if s.get('is_best')), solutions[0])

        number = data.get('number', '?')
        title = data.get('title', '')
        target_file = target.get('file', '?')

        moved = []
        if old_attempts:
            target['attempts'] = old_attempts
            moved.append('attempts')
        if old_is_representative:
            target['is_representative'] = True
            moved.append('is_representative')
        if old_representative_tag:
            target['representative_tag'] = old_representative_tag
            moved.append('representative_tag')

        print(f"  {number:>5} {title:<45} [{target_file}] 搬移：{', '.join(moved)}")

        for key in ('attempts', 'is_representative', 'representative_tag'):
            data.pop(key, None)

        total_changes += 1

        if do_apply:
            with open(fpath, 'w', encoding='utf-8') as f:
                yaml.dump(data, f, allow_unicode=True, sort_keys=False)

    print(f"\n{'=' * 60}")
    if do_apply:
        print(f"完成：{total_changes} 題已把題目層級資料搬進解法層級。")
        print("建議重新用 solution-generator.html 檢查一下歸屬到哪個解法變體是否正確。")
    else:
        print(f"這是 dry-run（{total_changes} 題會被異動），還沒有真的寫入。"
              f"確認沒問題後加 --yes 再跑一次：")
        print(f"  python3 {os.path.basename(__file__)} {meta_dir} --yes")


if __name__ == '__main__':
    main()
