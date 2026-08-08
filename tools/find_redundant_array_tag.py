#!/usr/bin/env python3
"""
find_redundant_array_tag.py — 掃描 metadata/*.yml，找出「同時掛了泛用 array
標籤 + 更具體的 array-xxx 子分類標籤」的解法。

因為 array-xxx 子分類的題目會自動匯總進 array.md（見 generate_site.py 的
AGGREGATE_PARENT_TOPICS 邏輯），所以不需要再額外掛 array 這個泛用標籤，
掛了反而是多餘、容易讓人誤以為是「兩個不同分類」。

這支腳本只列出建議，不會自動修改 metadata。

用法（在 repo 根目錄執行）：
    python3 tools/find_redundant_array_tag.py
"""
import glob
import os
import sys

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

META_DIR = "metadata"


def to_list(v):
    if v is None:
        return []
    if isinstance(v, str):
        return [v]
    return list(v)


def main():
    found = []
    for fpath in sorted(glob.glob(os.path.join(META_DIR, '*.yml'))):
        with open(fpath, encoding='utf-8') as f:
            data = yaml.safe_load(f)
        if not data:
            continue
        number = data.get('number')
        title = data.get('title', '')
        for sol in data.get('solutions', []) or []:
            topics = to_list(sol.get('topics'))
            if 'array' not in topics:
                continue
            children = [t for t in topics if t != 'array' and t.startswith('array-')]
            if children:
                found.append((number, title, sol.get('file', ''), children))

    print(f"=== 同時掛了 array + array-xxx 子分類的解法（{len(found)} 筆）===\n")
    for number, title, file, children in found:
        print(f"  {number:04d}  {title}  ({file})  多餘的子分類: {', '.join(children)}")

    print()
    print("建議：到 solution-generator.html 把這些解法的 topics 裡，")
    print("把泛用的「array」拿掉，只留 array-xxx 這個更具體的子分類就好，")
    print("array.md 頁面還是會自動顯示這些題目，不用擔心看不到。")


if __name__ == '__main__':
    main()
