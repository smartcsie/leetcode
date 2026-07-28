#!/usr/bin/env python3
import sys
import os
import re
import shutil

CODE_FILE_RE = re.compile(r'Solution_[A-Za-z0-9_]+\.(cpp|md|sql|py|java)')
SKIP_NAMES = {'index.md'}
SKIP_DIRS = {'problems', 'topics', 'solution-pages', 'solution'}

def is_old_topic_file(fpath):
    with open(fpath, 'r', encoding='utf-8', errors='replace') as f:
        text = f.read()
    for line in text.splitlines():
        line = line.strip()
        if not line.startswith('|'):
            continue
        if CODE_FILE_RE.search(line):
            return True
    return False

def main():
    if len(sys.argv) != 3:
        print("Usage: python3 cleanup_old_docs.py <docs_dir> <backup_dir>")
        sys.exit(1)

    docs_dir, backup_dir = sys.argv[1], sys.argv[2]
    os.makedirs(backup_dir, exist_ok=True)

    moved = []
    kept = []

    for fname in sorted(os.listdir(docs_dir)):
        fpath = os.path.join(docs_dir, fname)
        if os.path.isdir(fpath):
            continue
        if not fname.endswith('.md'):
            continue
        if fname in SKIP_NAMES:
            kept.append(fname)
            continue

        if is_old_topic_file(fpath):
            shutil.move(fpath, os.path.join(backup_dir, fname))
            moved.append(fname)
        else:
            kept.append(fname)

    print(f"搬移到 {backup_dir}/ 的舊主題表格檔案 ({len(moved)} 個)：")
    for f in moved:
        print(f"  {f}")

    print(f"\n保留在 docs/ 的檔案 ({len(kept)} 個)：")
    for f in kept:
        print(f"  {f}")

if __name__ == '__main__':
    main()
