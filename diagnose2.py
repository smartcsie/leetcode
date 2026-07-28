import glob, os, re

CODE_FILE_RE = re.compile(r'(Solution_[A-Za-z0-9_]+)\.(?:cpp|md)')

# 用簡單規則抓出「應該存在」的所有 code file
referenced = set()
file_locations = {}  # code_file -> (docfile, line_no, raw_line)
for fpath in sorted(glob.glob('docs/*.md')):
    with open(fpath, encoding='utf-8', errors='replace') as f:
        lines = f.readlines()
    for i, line in enumerate(lines, 1):
        for m in CODE_FILE_RE.finditer(line):
            fname = m.group(1) + '.cpp'
            referenced.add(fname)
            if fname not in file_locations:
                file_locations[fname] = (fpath, i, line.rstrip())

# 用跟 extract_metadata.py 一樣的方式解析表格列，統計哪些 code_file 有真的被抓到
parsed_files = set()
SEP_RE = re.compile(r'^[\s:|-]+$')

def split_row(line):
    line = line.rstrip('\n').rstrip()
    if not line.startswith('|'):
        return None
    inner = line[1:]
    if inner.endswith('|'):
        inner = inner[:-1]
    return [c.strip() for c in inner.split('|')]

for fpath in sorted(glob.glob('docs/*.md')):
    with open(fpath, encoding='utf-8', errors='replace') as f:
        lines = f.readlines()
    for line in lines:
        cells = split_row(line)
        if cells is None or len(cells) < 8:
            continue
        if cells[0] in ('#',) or SEP_RE.match(cells[0]):
            continue
        num_text = cells[0].replace('*', '').strip()
        if not re.search(r'\d+', num_text):
            continue
        cm = CODE_FILE_RE.search(cells[4]) if len(cells) > 4 else None
        if cm:
            parsed_files.add(cm.group(1) + '.cpp')

missing = referenced - parsed_files
print(f"規則式掃到的檔名數: {len(referenced)}")
print(f"表格解析成功抓到的檔名數: {len(parsed_files)}")
print(f"\n漏掉的檔案數: {len(missing)}")
print("漏掉的前 15 筆，附上原始那一行內容：\n")
for fname in sorted(missing)[:15]:
    docfile, lineno, raw = file_locations[fname]
    print(f"[{fname}] 出現在 {docfile}:{lineno}")
    print(f"  原始內容: {raw}")
    cells = split_row(raw)
    print(f"  split_row 結果欄位數: {len(cells) if cells else 'None (不是表格列)'}")
    print()
