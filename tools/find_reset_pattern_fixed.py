#!/usr/bin/env python3
"""
find_reset_pattern_fixed.py

搜尋 LeetCode C++ 解答中「更新最佳值 + tie 處理」的 pattern，例如：

    if (count > mx) {
        mx = count;
        ans = {x};
    } else if (count == mx) {
        ans.push_back(x);
    }

以及：

    if (freq > best) {
        best = freq;
        res = x;
    }
    if (freq == best && x < res) {
        res = x;
    }

也支援反向的 minimum pattern：

    if (cur < best) { ... }
    else if (cur == best) { ... }

用法：
    python3 find_reset_pattern_fixed.py
    python3 find_reset_pattern_fixed.py --base /path/to/solution
    python3 find_reset_pattern_fixed.py --mode max
    python3 find_reset_pattern_fixed.py --mode min
    python3 find_reset_pattern_fixed.py --show
"""

import argparse
import os
import re
from dataclasses import dataclass

DEFAULT_BASE = "/home/laurence/leetcode-docs/repo/solution"


@dataclass
class IfCond:
    start: int
    end: int
    condition: str


def strip_comments(text: str) -> str:
    """移除 C/C++ comments，但保留換行，方便輸出行號。"""
    def repl_block(m):
        return "\n" * m.group(0).count("\n")

    text = re.sub(r"/\*.*?\*/", repl_block, text, flags=re.S)
    text = re.sub(r"//[^\n]*", "", text)
    return text


def extract_if_conditions(text: str):
    """用括號平衡方式抓 if (...)，比單純 [^)] regex 更耐 function call。"""
    result = []
    for m in re.finditer(r"\bif\s*\(", text):
        open_pos = text.find("(", m.start())
        depth = 0
        i = open_pos
        while i < len(text):
            ch = text[i]
            if ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
                if depth == 0:
                    result.append(
                        IfCond(
                            start=m.start(),
                            end=i + 1,
                            condition=text[open_pos + 1:i].strip(),
                        )
                    )
                    break
            i += 1
    return result


def normalize(expr: str) -> str:
    """忽略空白與多餘外層括號。"""
    expr = re.sub(r"\s+", "", expr)
    changed = True
    while changed and len(expr) >= 2 and expr[0] == "(" and expr[-1] == ")":
        depth = 0
        changed = False
        for i, ch in enumerate(expr):
            if ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
                if depth == 0 and i != len(expr) - 1:
                    break
        else:
            expr = expr[1:-1]
            changed = True
    return expr


def split_top_level_logic(cond: str):
    """把 top-level && / || 切開；2404 的 `freq == best && num < res` 可取出第一段。"""
    parts = []
    start = 0
    depth_paren = depth_bracket = 0
    i = 0
    while i < len(cond) - 1:
        ch = cond[i]
        if ch == "(":
            depth_paren += 1
        elif ch == ")":
            depth_paren -= 1
        elif ch == "[":
            depth_bracket += 1
        elif ch == "]":
            depth_bracket -= 1

        if depth_paren == 0 and depth_bracket == 0 and cond[i:i+2] in ("&&", "||"):
            parts.append(cond[start:i].strip())
            i += 2
            start = i
            continue
        i += 1
    parts.append(cond[start:].strip())
    return [p for p in parts if p]


def parse_comparison(expr: str):
    """解析一個簡單 comparison，回傳 (lhs, op, rhs)。"""
    # 排除 >= <= !=，優先抓 == 再抓 > / <
    m = re.match(r"^\s*(.+?)\s*(==|>|<)\s*(.+?)\s*$", expr)
    if not m:
        return None
    lhs, op, rhs = m.groups()
    return normalize(lhs), op, normalize(rhs)


def comparisons_in_condition(cond: str):
    result = []
    for part in split_top_level_logic(cond):
        parsed = parse_comparison(part)
        if parsed:
            result.append(parsed)
    return result


def same_pair(a_lhs, a_rhs, b_lhs, b_rhs):
    """接受 `x > best` + `x == best`，也接受 equality 寫成 `best == x`。"""
    return (
        (a_lhs == b_lhs and a_rhs == b_rhs)
        or (a_lhs == b_rhs and a_rhs == b_lhs)
    )


def find_patterns(content: str, mode="both", max_gap=800):
    clean = strip_comments(content)
    ifs = extract_if_conditions(clean)
    hits = []

    wanted_ops = {">"} if mode == "max" else {"<"} if mode == "min" else {">", "<"}

    for i, first in enumerate(ifs):
        first_cmps = comparisons_in_condition(first.condition)
        best_cmps = [c for c in first_cmps if c[1] in wanted_ops]
        if not best_cmps:
            continue

        for second in ifs[i + 1:]:
            if second.start - first.end > max_gap:
                break

            second_cmps = comparisons_in_condition(second.condition)
            eq_cmps = [c for c in second_cmps if c[1] == "=="]
            if not eq_cmps:
                continue

            matched = False
            for lhs1, op1, rhs1 in best_cmps:
                for lhs2, _, rhs2 in eq_cmps:
                    if same_pair(lhs1, rhs1, lhs2, rhs2):
                        hits.append({
                            "start": first.start,
                            "end": second.end,
                            "op": op1,
                            "lhs": lhs1,
                            "rhs": rhs1,
                            "cond1": first.condition,
                            "cond2": second.condition,
                        })
                        matched = True
                        break
                if matched:
                    break
            if matched:
                # 一個 first if 只列最近的 matching tie if，避免同檔重複爆量
                break

    return hits


def line_number(text: str, pos: int) -> int:
    return text.count("\n", 0, pos) + 1


def make_snippet(text: str, start: int, end: int, context_lines=2):
    lines = text.splitlines()
    s = line_number(text, start)
    e = line_number(text, end)
    lo = max(1, s - context_lines)
    hi = min(len(lines), e + context_lines + 6)  # 多帶幾行 body 方便人工看 reset/tie
    out = []
    for no in range(lo, hi + 1):
        out.append(f"{no:4d}: {lines[no - 1]}")
    return "\n".join(out)


def main():
    parser = argparse.ArgumentParser(description="Find best-update + tie-handling patterns in C++ solutions")
    parser.add_argument("--base", default=DEFAULT_BASE, help="solution directory")
    parser.add_argument("--mode", choices=["max", "min", "both"], default="both",
                        help="max: > then ==, min: < then ==, both: search both")
    parser.add_argument("--gap", type=int, default=800,
                        help="maximum chars between first if and tie if (default: 800)")
    parser.add_argument("--show", action="store_true",
                        help="show matched conditions and source snippets")
    args = parser.parse_args()

    if not os.path.isdir(args.base):
        raise SystemExit(f"找不到目錄: {args.base}")

    matched = []

    for filename in sorted(os.listdir(args.base)):
        if not filename.endswith(".cpp"):
            continue

        filepath = os.path.join(args.base, filename)
        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()

        hits = find_patterns(content, mode=args.mode, max_gap=args.gap)
        if hits:
            matched.append((filename, content, hits))

    print(f"\n找到 {len(matched)} 個符合『更新最佳值 + tie 處理』pattern 的檔案：\n")

    for filename, content, hits in matched:
        num = filename.replace("Solution_", "").replace(".cpp", "")
        kinds = sorted(set("MAX" if h["op"] == ">" else "MIN" for h in hits))
        print(f"  {num:>4}  ->  {filename}   [{'/'.join(kinds)}]")

        if args.show:
            for n, h in enumerate(hits, 1):
                print(f"       hit {n}: if ({h['cond1']})")
                print(f"              tie ({h['cond2']})")
                print(make_snippet(content, h["start"], h["end"]))
                print("       " + "-" * 70)

    print("\n建議先跑：")
    print("  python3 find_reset_pattern_fixed.py --mode max --show")
    print("\n若結果太多，可把 --gap 調小，例如 --gap 400。")


if __name__ == "__main__":
    main()
