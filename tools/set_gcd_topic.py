#!/usr/bin/env python3
import sys
import os

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml")
    sys.exit(1)

TARGET_TOPIC = 'math-gcd'
PROBLEMS = [365, 914, 1071, 1979, 2427, 2807, 3867]

def main():
    meta_dir = sys.argv[1] if len(sys.argv) > 1 else 'metadata'
    found = []
    missing = []

    for num in PROBLEMS:
        path = os.path.join(meta_dir, f"{num:04d}.yml")
        if not os.path.exists(path):
            missing.append(num)
            continue

        with open(path, 'r', encoding='utf-8') as f:
            data = yaml.safe_load(f)

        old_topics_report = []
        for sol in data.get('solutions', []):
            old_topics_report.append(sol.get('topics'))
            sol['topics'] = [TARGET_TOPIC]

        with open(path, 'w', encoding='utf-8') as f:
            yaml.dump(data, f, allow_unicode=True, sort_keys=False)

        found.append((num, old_topics_report))

    print(f"已更新 {len(found)} 題（原本的 topics -> ['{TARGET_TOPIC}']）：")
    for num, old in found:
        print(f"  {num:04d}: {old} -> ['{TARGET_TOPIC}']")

    if missing:
        print(f"\n⚠️ 找不到 metadata 檔案的題目（尚未存檔，共 {len(missing)} 題）：")
        for num in missing:
            print(f"  {num:04d}")

if __name__ == '__main__':
    main()
