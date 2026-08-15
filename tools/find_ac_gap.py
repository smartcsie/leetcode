#!/usr/bin/env python3
"""
找出「已收錄在 metadata/ 的題目」跟「LeetCode 網站實際 AC 清單」之間的差異。

用法：
    cd ~/leetcode-docs/repo
    python3 find_ac_gap.py

需要：
    ./metadata/*.yml          （你的解法 metadata）
    ./leetcode_ac_cache.json  （tools/fetch_leetcode_ac.py 產生的快取）
"""
import os
import sys
import glob
import json

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml")
    sys.exit(1)


def load_collected_numbers(meta_dir='metadata'):
    """讀 metadata/*.yml，回傳 {題號: 題目資訊} 的 dict。"""
    collected = {}
    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, encoding='utf-8') as f:
            data = yaml.safe_load(f)
        if not data:
            continue
        number = data.get('number') or data.get('id') or data.get('frontend_id')
        title = data.get('title', '')
        slug = data.get('slug', '')
        if number is None:
            print(f"⚠️  無法從 {fpath} 讀到題號，跳過")
            continue
        try:
            number = int(number)
        except (TypeError, ValueError):
            print(f"⚠️  {fpath} 的題號格式異常: {number!r}，跳過")
            continue
        collected[number] = {'title': title, 'slug': slug, 'file': fpath}
    return collected


def try_extract_solved_numbers(cache):
    """
    嘗試從 leetcode_ac_cache.json 抓出「已 AC 的題號清單」。
    不同版本的 fetch_leetcode_ac.py 可能用不同欄位名稱存清單，
    這裡盡量兼容常見命名；抓不到就回傳 None。
    """
    candidate_keys = [
        'solved_problems', 'solved_list', 'solved', 'solved_slugs',
        'solved_ids', 'problems', 'questions', 'ac_list', 'ac_problems',
        'accepted', 'accepted_problems', 'submissions',
    ]

    for key in candidate_keys:
        val = cache.get(key)
        if not val:
            continue
        if not isinstance(val, list):
            continue

        numbers = set()
        for item in val:
            if isinstance(item, (int, str)):
                # 可能直接是題號或 slug 字串
                try:
                    numbers.add(int(item))
                    continue
                except (TypeError, ValueError):
                    pass
            elif isinstance(item, dict):
                for num_key in ('number', 'id', 'frontend_id', 'questionFrontendId', 'question_id'):
                    if num_key in item:
                        try:
                            numbers.add(int(item[num_key]))
                            break
                        except (TypeError, ValueError):
                            continue

        if numbers:
            return key, numbers

    return None, None


def main():
    meta_dir = 'metadata'
    cache_path = 'leetcode_ac_cache.json'

    if not os.path.isdir(meta_dir):
        print(f"❌ 找不到 {meta_dir}/ 目錄，請在 repo 根目錄下執行本腳本")
        sys.exit(1)

    if not os.path.exists(cache_path):
        print(f"❌ 找不到 {cache_path}，請先執行 python3 tools/fetch_leetcode_ac.py")
        sys.exit(1)

    collected = load_collected_numbers(meta_dir)
    print(f"📦 metadata/ 收錄題目數：{len(collected)}")

    with open(cache_path, encoding='utf-8') as f:
        cache = json.load(f)

    num_solved = cache.get('num_solved')
    num_total = cache.get('num_total')
    print(f"🌐 LeetCode 網站 AC 總數：{num_solved} / {num_total}")
    print()

    key, solved_numbers = try_extract_solved_numbers(cache)

    if solved_numbers is None:
        print("⚠️  在 leetcode_ac_cache.json 裡找不到「逐題 AC 清單」的欄位，")
        print("   目前的快取似乎只存了總數 (num_solved / num_total)，沒有存明細。")
        print()
        print("   這裡是快取檔的所有頂層欄位，方便確認實際格式：")
        for k, v in cache.items():
            preview = v if not isinstance(v, (list, dict)) else f"({type(v).__name__}, len={len(v)})"
            print(f"     - {k}: {preview}")
        print()
        print("   若要精確找出差異，需要修改 tools/fetch_leetcode_ac.py，")
        print("   讓它額外把每一題的題號（或 slug）也存進快取。")
        print("   我可以幫你改 fetch_leetcode_ac.py，把清單也存下來 —— 需要的話請把該檔案內容貼給我。")
        sys.exit(0)

    print(f"✅ 從快取欄位 '{key}' 讀到 {len(solved_numbers)} 個已 AC 題號")
    print()

    collected_numbers = set(collected.keys())

    # 收錄了，但 LeetCode 網站上還沒 AC
    not_yet_ac = sorted(collected_numbers - solved_numbers)
    # LeetCode 已 AC，但還沒收錄進 metadata
    not_collected = sorted(solved_numbers - collected_numbers)

    print(f"🔴 已收錄但 LeetCode 網站尚未 AC（{len(not_yet_ac)} 題）：")
    if not_yet_ac:
        for num in not_yet_ac:
            info = collected[num]
            print(f"   - {num}. {info['title']}  ({info['file']})")
    else:
        print("   （無）")
    print()

    print(f"🟡 LeetCode 已 AC 但尚未收錄進 metadata（{len(not_collected)} 題）：")
    if not_collected:
        for num in not_collected:
            print(f"   - {num}")
    else:
        print("   （無）")


if __name__ == '__main__':
    main()
