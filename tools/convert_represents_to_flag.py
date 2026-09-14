#!/usr/bin/env python3
"""
convert_represents_to_flag.py

一次性轉換：把舊版的 represents（清單，含 group/label/show_in_index/
self_assessment）轉換成新版簡化的 is_representative: true。只要
represents 清單裡有任何一筆，就視為這題曾經被標記過代表題身份，
轉成 is_representative: true，並移除舊的 represents 欄位。

用法：
    python3 convert_represents_to_flag.py [metadata_dir]        # dry-run
    python3 convert_represents_to_flag.py [metadata_dir] --yes   # 真的套用
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

        old_represents = data.get('represents')
        if not old_represents:
            continue  # 沒有舊的 represents 欄位，跳過

        number = data.get('number', '?')
        title = data.get('title', '')
        labels = ', '.join(r.get('label', '') for r in old_represents if isinstance(r, dict))
        print(f"  {number:>5} {title:<45} represents（{labels}）→ is_representative: true")

        data['is_representative'] = True
        del data['represents']
        total_changes += 1

        if do_apply:
            with open(fpath, 'w', encoding='utf-8') as f:
                yaml.dump(data, f, allow_unicode=True, sort_keys=False)

    print(f"\n{'=' * 60}")
    if do_apply:
        print(f"完成：{total_changes} 題已從 represents 轉換成 is_representative: true。")
    else:
        print(f"這是 dry-run（{total_changes} 題會被異動），還沒有真的寫入。"
              f"確認沒問題後加 --yes 再跑一次：")
        print(f"  python3 {os.path.basename(__file__)} {meta_dir} --yes")


if __name__ == '__main__':
    main()
