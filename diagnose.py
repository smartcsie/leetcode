import glob, os, re

# 抓出所有 solution 檔名
all_files = set(os.path.basename(f) for f in glob.glob('solution/*.cpp'))
print(f"solution/ 裡總共有 {len(all_files)} 個 .cpp 檔案")

# 抓出所有在 docs/*.md 表格裡出現過的 Solution_XXXX.cpp 檔名
referenced = set()
CODE_FILE_RE = re.compile(r'(Solution_[A-Za-z0-9_]+)\.(?:cpp|md)')
for fpath in glob.glob('docs/*.md'):
    with open(fpath, encoding='utf-8', errors='replace') as f:
        text = f.read()
    for m in CODE_FILE_RE.finditer(text):
        referenced.add(m.group(1) + '.cpp')

print(f"表格裡有引用到的檔案數: {len(referenced)}")

missing = all_files - referenced
print(f"\n從未被任何表格引用的檔案數: {len(missing)}")
print("前 20 個範例：")
for f in sorted(missing)[:20]:
    print(" ", f)
