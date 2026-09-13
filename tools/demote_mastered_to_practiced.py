#!/usr/bin/env python3
"""
demote_mastered_to_practiced.py

一次性操作：把所有 familiarity == '熟練' 的解法，改成 '練習過'。
用來重新校準「熟練」這個標籤的公信力——舊的熟練標記可能已經過時
（標記當下真的很熟，但現在說不定已經生疏了），統一降一級，之後要
重新升回「熟練」，用 promote_to_mastered.py 走正式流程並記錄時間。

用法：
    python3 demote_mastered_to_practiced.py [metadata_dir]        # dry-run
    python3 demote_mastered_to_practiced.py [metadata_dir] --yes   # 真的套用
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
    files_changed = 0

    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, encoding='utf-8') as f:
            data = yaml.safe_load(f)
        if not data:
            continue

        title = data.get('title', '')
        number = data.get('number', '?')
        file_changed = False

        for sol in data.get('solutions', []) or []:
            if sol.get('familiarity') == '熟練':
                print(f"  {number:>5} {title:<45} [{sol.get('file','?')}] 熟練 → 練習過")
                sol['familiarity'] = '練習過'
                # 舊的熟練時間戳記如果有，一併清掉，避免留著誤導
                sol.pop('mastered_date', None)
                total_changes += 1
                file_changed = True

        if file_changed:
            files_changed += 1
            if do_apply:
                with open(fpath, 'w', encoding='utf-8') as f:
                    yaml.dump(data, f, allow_unicode=True, sort_keys=False)

    print(f"\n{'=' * 60}")
    if do_apply:
        print(f"完成：{files_changed} 個檔案、{total_changes} 題已從熟練降級成練習過。")
    else:
        print(f"這是 dry-run（{files_changed} 個檔案、{total_changes} 題會被異動），"
              f"還沒有真的寫入。確認沒問題後加 --yes 再跑一次：")
        print(f"  python3 {os.path.basename(__file__)} {meta_dir} --yes")


if __name__ == '__main__':
    main()
