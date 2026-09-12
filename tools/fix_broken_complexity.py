#!/usr/bin/env python3
"""
fix_broken_complexity.py

修正 metadata/*.yml 裡被截斷（缺右括號）的 time/space 欄位。
跟 fix_metadata_complexity.py 不同：那支是「砍掉多餘的說明文字」，
這支是「把整個遺失的內容補回去」——補回去的值是根據對話歷史裡曾經
明確給過的正確複雜度，不是憑空猜測。

⚠️ 208 Implement Trie 這題的 space 欄位沒有被收進這份清單，因為這題
在對話裡沒有討論過正確複雜度，需要你自己確認後手動填。

用法：
    python3 fix_broken_complexity.py [metadata_dir]        # dry-run
    python3 fix_broken_complexity.py [metadata_dir] --yes   # 真的套用
"""
import sys
import os
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

# (題號, 欄位, 正確值)
FIXES = [
    (85, 'time', 'O(M*N)'),
    (85, 'space', 'O(N)'),
    (95, 'time', 'O(Catalan(N) * N)'),
    (95, 'space', 'O(Catalan(N) * N)'),
    (188, 'time', 'O(N*K)'),
    (188, 'space', 'O(K)'),
    (221, 'time', 'O(M*N)'),
    (221, 'space', 'O(M*N)'),
    (464, 'time', 'O(2^N * N)'),
    (698, 'time', 'O(2^N * N)'),
    (787, 'time', 'O(K * E)'),
    (847, 'time', 'O(N² * 2^N)'),
    (847, 'space', 'O(N * 2^N)'),
    (902, 'time', 'O(len(N) * len(digits))'),
    (943, 'time', 'O(N² * 2^N)'),
    (943, 'space', 'O(N * 2^N)'),
    (1061, 'time', 'O(N + M * α(26))'),
    (1092, 'time', 'O(N*M)'),
    (1092, 'space', 'O(N*M)'),
    (1125, 'time', 'O(2^M * N)'),
    (1434, 'time', 'O(40 * 2^N * 平均每頂帽子對應的人數)'),
    (1434, 'space', 'O(40 * 2^N)'),
    (1510, 'time', 'O(N * √N)'),
    (1531, 'time', 'O(N² * K)'),
    (1531, 'space', 'O(N * K)'),
    (1631, 'time', 'O(M*N log(M*N))'),
    (1631, 'space', 'O(M*N)'),
    (2035, 'time', 'O(N * 2^(N/2))'),

    # 688 Knight Probability in Chessboard 沒有列進來：
    # 我對這題原本的正確值不夠有把握，麻煩你自己確認後手動填。
]


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    meta_dir = args[0] if args else 'metadata'
    do_apply = '--yes' in sys.argv

    if not os.path.isdir(meta_dir):
        print(f"❌ 找不到資料夾: {meta_dir}")
        sys.exit(1)

    fixes_by_number = {}
    for number, field, value in FIXES:
        fixes_by_number.setdefault(number, []).append((field, value))

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
        if number not in fixes_by_number:
            continue

        title = data.get('title', '')
        file_changed = False

        for sol in data.get('solutions', []):
            for field, correct_value in fixes_by_number[number]:
                old_value = sol.get(field)
                if old_value == correct_value:
                    continue
                print(f"  {number:>5} {title:<45} [{sol.get('file','?')}] "
                      f"{field}: {old_value!r} → {correct_value!r}")
                sol[field] = correct_value
                total_changes += 1
                file_changed = True

        if file_changed:
            files_changed += 1
            if do_apply:
                with open(fpath, 'w', encoding='utf-8') as f:
                    yaml.dump(data, f, allow_unicode=True, sort_keys=False)

    print(f"\n{'=' * 60}")
    if do_apply:
        print(f"完成：{files_changed} 個檔案、{total_changes} 處複雜度欄位已修正。")
    else:
        print(f"這是 dry-run（{files_changed} 個檔案、{total_changes} 處會被異動），"
              f"還沒有真的寫入。確認沒問題後加 --yes 再跑一次：")
        print(f"  python3 {os.path.basename(__file__)} {meta_dir} --yes")
    print("\n提醒：208 Implement Trie 的 space 欄位、688 Knight Probability "
          "的 time 欄位沒有收進這份清單（沒把握原本的正確值），麻煩自己"
          "確認後手動填。")


if __name__ == '__main__':
    main()
