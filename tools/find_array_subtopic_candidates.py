#!/usr/bin/env python3
"""
find_array_subtopic_candidates.py — 掃描 metadata/*.yml，找出可能該標成
array-min-max 或 array-negative-marking 的候選題目，讓你確認後手動改標籤。

不會自動修改任何檔案，純粹列出建議清單。

用法（在 repo 根目錄執行）：
    python3 tools/find_array_subtopic_candidates.py
"""
import glob
import os
import re
import sys

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

META_DIR = "metadata"

MIN_MAX_KEYWORDS = re.compile(
    r'\b(min|max|minimum|maximum|largest|smallest|greatest|least)\b', re.IGNORECASE
)
NEGATIVE_MARK_KEYWORDS = re.compile(
    r'負數標記|標記為負|negative.?mark|in-?place.*negat|存在性標記|原地標記',
    re.IGNORECASE
)


def load_all(meta_dir):
    problems = []
    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, encoding='utf-8') as f:
            data = yaml.safe_load(f)
        if data:
            problems.append(data)
    return problems


def to_list(v):
    if v is None:
        return []
    if isinstance(v, str):
        return [v]
    return list(v)


def main():
    problems = load_all(META_DIR)

    min_max_candidates = []
    neg_mark_candidates = []

    for p in problems:
        number = p.get('number')
        title = p.get('title', '')
        for sol in p.get('solutions', []) or []:
            topics = to_list(sol.get('topics'))
            if 'array' not in topics:
                continue  # 只看目前掛在泛用 array 底下的解法，其他子分類已經分好了

            note = sol.get('note') or ''
            tags = ' '.join(to_list(sol.get('tags')))
            haystack = f"{title} {tags} {note}"

            if MIN_MAX_KEYWORDS.search(haystack):
                min_max_candidates.append((number, title, sol.get('file', '')))

            if NEGATIVE_MARK_KEYWORDS.search(haystack):
                neg_mark_candidates.append((number, title, sol.get('file', '')))

    def dedup(rows):
        seen = set()
        out = []
        for r in rows:
            key = (r[0], r[2])
            if key not in seen:
                seen.add(key)
                out.append(r)
        return out

    min_max_candidates = dedup(min_max_candidates)
    neg_mark_candidates = dedup(neg_mark_candidates)

    print(f"=== array-min-max 候選（{len(min_max_candidates)} 筆，目前 topic=array，title/tags/note 含 min/max 關鍵字）===")
    for number, title, file in sorted(min_max_candidates):
        print(f"  {number:04d}  {title}  ({file})")

    print()
    print(f"=== array-negative-marking 候選（{len(neg_mark_candidates)} 筆，note 含負數標記相關關鍵字）===")
    for number, title, file in sorted(neg_mark_candidates):
        print(f"  {number:04d}  {title}  ({file})")

    print()
    print("⚠️ 這只是關鍵字比對出來的建議清單，不是自動判斷正確答案，")
    print("   請逐一打開題目確認解法邏輯是否真的符合，再到 solution-generator.html 手動改 topic。")


if __name__ == '__main__':
    main()
