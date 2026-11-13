#!/usr/bin/env python3
"""把 metadata/*.yml 裡「每個解法」的 familiarity 一次改成指定值（預設：生疏）。

用法：
    python3 set_familiarity.py                      # 處理 ./metadata，全部改成 生疏
    python3 set_familiarity.py path/to/metadata     # 指定資料夾
    python3 set_familiarity.py --dry-run            # 只顯示會改什麼，不寫檔
    python3 set_familiarity.py --backup             # 改檔前先存 .yml.bak
    python3 set_familiarity.py --only-unset         # 只補上「還沒標記」的，不蓋掉已標記的

只用標準函式庫，不需要安裝 PyYAML；逐行處理，所以其他欄位與排版不會被動到。
"""
import argparse
import re
import shutil
import sys
from collections import Counter
from pathlib import Path

# 熟練 需要同時記錄 mastered_date，這個腳本不處理，請用產生器標記
CHOICES = ["生疏", "再練習", "練習過", "易忘"]

ITEM_RE = re.compile(r"^- file:")                  # 每個解法的開頭
FAM_RE = re.compile(r"^  familiarity:\s*(.*?)\s*$")
MASTERED_RE = re.compile(r"^  mastered_date:")     # 只有 熟練 才會有


def split_items(lines):
    """把檔案拆成 (開頭幾行, [每個解法的行, ...])。"""
    header, items = [], []
    for ln in lines:
        if ITEM_RE.match(ln):
            items.append([ln])
        elif items:
            items[-1].append(ln)
        else:
            header.append(ln)
    return header, items


def update_item(item, value, only_unset):
    """更新單一解法。回傳 (新的行, 舊值或 None)。"""
    new_line = f"  familiarity: {value}"
    old = None

    for i, ln in enumerate(item):
        m = FAM_RE.match(ln)
        if m:
            old = m.group(1).strip("'\"") or None
            if only_unset and old:
                return item, old
            item[i] = new_line
            break
    else:
        # 沒有 familiarity：依產生器的欄位順序，放在 space（其次 time）後面
        pos = None
        for key in ("space", "time"):
            for i, ln in enumerate(item):
                if ln.startswith(f"  {key}:"):
                    pos = i + 1
                    break
            if pos is not None:
                break
        item.insert(pos if pos is not None else 1, new_line)

    # 只有 熟練 才有 mastered_date，改成其他值時要一併拿掉
    item = [ln for ln in item if not MASTERED_RE.match(ln)]
    return item, old


def process_file(path, value, only_unset, dry_run, backup):
    text = path.read_text(encoding="utf-8")
    eol = "\r\n" if "\r\n" in text else "\n"
    header, items = split_items(text.splitlines())

    if not items:
        return None  # 沒有 solutions 區塊

    olds = []
    new_items = []
    for item in items:
        item, old = update_item(item, value, only_unset)
        new_items.append(item)
        olds.append(old)

    lines = header + [ln for item in new_items for ln in item]
    new_text = eol.join(lines) + eol

    if new_text != text and not dry_run:
        if backup:
            shutil.copy2(path, path.with_suffix(path.suffix + ".bak"))
        path.write_text(new_text, encoding="utf-8", newline="")
    return olds, new_text != text


def main():
    ap = argparse.ArgumentParser(description="批次設定 metadata/*.yml 的 familiarity")
    ap.add_argument("dir", nargs="?", default="metadata", help="metadata 資料夾（預設 ./metadata）")
    ap.add_argument("--value", choices=CHOICES, default="生疏", help="要設定的熟悉度（預設 生疏）")
    ap.add_argument("--dry-run", action="store_true", help="只顯示結果，不寫檔")
    ap.add_argument("--backup", action="store_true", help="改檔前先備份成 .yml.bak")
    ap.add_argument("--only-unset", action="store_true", help="只補上尚未標記的解法")
    args = ap.parse_args()

    folder = Path(args.dir)
    files = sorted(folder.glob("*.yml"))
    if not files:
        sys.exit(f"找不到任何 .yml：{folder.resolve()}")

    before = Counter()
    changed_files = skipped = 0
    for f in files:
        result = process_file(f, args.value, args.only_unset, args.dry_run, args.backup)
        if result is None:
            skipped += 1
            print(f"略過（沒有 solutions）：{f.name}")
            continue
        olds, changed = result
        before.update(o or "未標記" for o in olds)
        changed_files += changed

    total = sum(before.values())
    print(f"\n{'[dry-run] ' if args.dry_run else ''}處理 {len(files) - skipped} 個檔案、{total} 個解法，"
          f"其中 {changed_files} 個檔案有變動（其餘本來就是『{args.value}』或被 --only-unset 保留）。")
    print("改之前的熟悉度分布：")
    for k, v in before.most_common():
        print(f"  {k}: {v}")


if __name__ == "__main__":
    main()
