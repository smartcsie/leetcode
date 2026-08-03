#!/usr/bin/env python3
"""
掃描 metadata/*.yml，找出缺少（或空白）url 的題目，
用題目標題自動組出 LeetCode 網址並補上。

用法:
  python3 fix_missing_urls.py [metadata_dir]

預設 metadata_dir = 'metadata'
"""
import sys
import os
import re
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)


def slugify(title):
    """把題目標題轉成 LeetCode 網址常用的 slug 格式。"""
    s = title.strip().lower()
    s = s.replace("'", "")
    s = s.replace('"', "")
    s = re.sub(r'[^a-z0-9]+', '-', s)
    s = s.strip('-')
    return s


def main():
    meta_dir = sys.argv[1] if len(sys.argv) > 1 else 'metadata'
    yml_files = sorted(glob.glob(os.path.join(meta_dir, '*.yml')))

    if not yml_files:
        print(f"❌ 在 {meta_dir} 找不到任何 .yml 檔案")
        sys.exit(1)

    fixed = []
    skipped_has_url = 0
    uncertain = []

    for fpath in yml_files:
        with open(fpath, 'r', encoding='utf-8') as f:
            data = yaml.safe_load(f)

        url = (data.get('url') or '').strip()
        if url:
            skipped_has_url += 1
            continue

        title = data.get('title', '')
        number = data.get('number', '?')
        if not title:
            uncertain.append((number, fpath, '沒有 title，無法自動產生連結'))
            continue

        slug = slugify(title)
        new_url = f"https://leetcode.com/problems/{slug}/"
        data['url'] = new_url

        with open(fpath, 'w', encoding='utf-8') as f:
            yaml.dump(data, f, allow_unicode=True, sort_keys=False)

        fixed.append((number, title, new_url, fpath))

    print(f"✓ 已有 url 的題目：{skipped_has_url} 題（略過，沒有動）")
    print(f"✓ 補上 url 的題目：{len(fixed)} 題\n")
    for number, title, new_url, fpath in fixed:
        print(f"  {number}: {title}\n    -> {new_url}")

    if uncertain:
        print(f"\n⚠️ 有 {len(uncertain)} 題無法自動處理，需要手動檢查：")
        for number, fpath, reason in uncertain:
            print(f"  {fpath}: {reason}")

    if fixed:
        print("\n⚠️ 注意：這是用標題自動猜測網址（slug 格式），"
              "少數題目（標題含特殊符號、羅馬數字、跟正式網址對不上等）可能會猜錯，"
              "建議跑完後挑幾個連結點開確認一下，尤其是這次被補上的題目。")


if __name__ == '__main__':
    main()
