#!/usr/bin/env python3
"""
list_binary_search_topics.py

列出目前 metadata/*.yml 裡，'binary-search' 或 'binary-search-*' 開頭
分類主題底下實際收錄的題目，方便確認哪幾題是同一種手法（例如「找左
邊界」）。

用法：
    python3 list_binary_search_topics.py [metadata_dir]

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


def to_list(value):
    if value is None:
        return []
    if isinstance(value, str):
        return [value]
    return list(value)


def main():
    meta_dir = sys.argv[1] if len(sys.argv) > 1 else 'metadata'
    if not os.path.isdir(meta_dir):
        print(f"❌ 找不到資料夾: {meta_dir}")
        sys.exit(1)

    by_topic = {}
    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, encoding='utf-8') as f:
            data = yaml.safe_load(f)
        if not data:
            continue
        number = data.get('number')
        title = data.get('title', '')
        seen_topics = set()
        for sol in data.get('solutions', []):
            for topic in to_list(sol.get('topics')):
                if not (topic == 'binary-search' or topic.startswith('binary-search-')):
                    continue
                if topic in seen_topics:
                    continue
                seen_topics.add(topic)
                by_topic.setdefault(topic, []).append((number, title))

    if not by_topic:
        print("沒有找到任何 binary-search / binary-search-* 分類的題目。")
        return

    for topic in sorted(by_topic):
        rows = sorted(by_topic[topic], key=lambda r: r[0])
        print(f"\n=== {topic}（{len(rows)} 題）===")
        for number, title in rows:
            print(f"   {number:>5}  {title}")


if __name__ == '__main__':
    main()
