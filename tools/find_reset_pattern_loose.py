#!/usr/bin/env python3
"""
find_reset_pattern_loose.py

寬鬆搜尋 LeetCode C++ 解答中的：
    1) 先用 > / < 更新某個最佳狀態
    2) 後面再用 == 處理 tie / 相等情況

設計原則：寧可多抓，再人工篩選。

命中等級：
  EXACT  : >/< 與 == 比較的是完全相同的一對 expression
           例：count > mx  ... count == mx
  LOOSE  : >/< 與 == 至少共享一個 expression
           例：score > best ... best == otherScore

預設使用 loose 模式。

用法：
  python3 tools/find_reset_pattern_loose.py --mode max --show
  python3 tools/find_reset_pattern_loose.py --mode max --match exact --show
  python3 tools/find_reset_pattern_loose.py --mode max --match loose --gap 1600 --show
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
    """移除 C/C++ comments，但保留換行，方便行號對齊。"""
    def repl_block(m):
        return "\n" * m.group(0).count("\n")

    text = re.sub(r"/\*.*?\*/", repl_block, text, flags=re.S)
    text = re.sub(r"//[^\n]*", "", text)
    return text


def extract_if_conditions(text: str):
    """用括號平衡抓出所有 if (...)。"""
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
    """移除空白和可安全剝掉的最外層括號。"""
    expr = re.sub(r"\s+", "", expr)

    changed = True
    while changed and len(expr) >= 2 and expr[0] == "(" and expr[-1] == ")":
        depth = 0
        changed = False
        valid_outer = True
        for i, ch in enumerate(expr):
            if ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
                if depth == 0 and i != len(expr) - 1:
                    valid_outer = False
                    break
        if valid_outer:
            expr = expr[1:-1]
            changed = True

    return expr


def split_top_level_logic(cond: str):
    """切 top-level && / ||，保留括號、[]、{} 內部內容。"""
    parts = []
    start = 0
    dp = db = dc = 0
    i = 0

    while i < len(cond) - 1:
        ch = cond[i]
        if ch == "(": dp += 1
        elif ch == ")": dp -= 1
        elif ch == "[": db += 1
        elif ch == "]": db -= 1
        elif ch == "{": dc += 1
        elif ch == "}": dc -= 1

        if dp == 0 and db == 0 and dc == 0 and cond[i:i+2] in ("&&", "||"):
            parts.append(cond[start:i].strip())
            i += 2
            start = i
            continue
        i += 1

    parts.append(cond[start:].strip())
    return [p for p in parts if p]


def parse_comparison(expr: str):
    """解析簡單的 == / > / < comparison。"""
    # 避免把 >= <= != 誤判成 > < ==
    if ">=" in expr or "<=" in expr or "!=" in expr:
        return None

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


def exact_pair(lhs1, rhs1, lhs2, rhs2):
    return (
        (lhs1 == lhs2 and rhs1 == rhs2)
        or (lhs1 == rhs2 and rhs1 == lhs2)
    )


def shared_expression(lhs1, rhs1, lhs2, rhs2):
    """寬鬆模式：四個 side 只要有任一 normalized expression 相同就算共享。"""
    a = {lhs1, rhs1}
    b = {lhs2, rhs2}
    return bool(a & b)


def classify_match(lhs1, rhs1, lhs2, rhs2):
    if exact_pair(lhs1, rhs1, lhs2, rhs2):
        return "EXACT"
    if shared_expression(lhs1, rhs1, lhs2, rhs2):
        return "LOOSE"
    return None


def find_patterns(content: str, mode="both", match_mode="loose", max_gap=1400,
                  max_ties_per_if=3):
    clean = strip_comments(content)
    ifs = extract_if_conditions(clean)
    hits = []

    wanted_ops = {">"} if mode == "max" else {"<"} if mode == "min" else {">", "<"}

    for i, first in enumerate(ifs):
        first_cmps = comparisons_in_condition(first.condition)
        primary_cmps = [c for c in first_cmps if c[1] in wanted_ops]
        if not primary_cmps:
            continue

        tie_count = 0

        for second in ifs[i + 1:]:
            if second.start - first.end > max_gap:
                break

            second_cmps = comparisons_in_condition(second.condition)
            eq_cmps = [c for c in second_cmps if c[1] == "=="]
            if not eq_cmps:
                continue

            best_hit = None

            for lhs1, op1, rhs1 in primary_cmps:
                for lhs2, _, rhs2 in eq_cmps:
                    level = classify_match(lhs1, rhs1, lhs2, rhs2)
                    if level is None:
                        continue
                    if match_mode == "exact" and level != "EXACT":
                        continue

                    candidate = {
                        "start": first.start,
                        "end": second.end,
                        "op": op1,
                        "lhs1": lhs1,
                        "rhs1": rhs1,
                        "lhs2": lhs2,
                        "rhs2": rhs2,
                        "cond1": first.condition,
                        "cond2": second.condition,
                        "level": level,
                        "gap": second.start - first.end,
                    }

                    # 同一對 if 有 EXACT 時優先，不再被 LOOSE 蓋掉
                    if best_hit is None or (best_hit["level"] == "LOOSE" and level == "EXACT"):
                        best_hit = candidate

            if best_hit:
                hits.append(best_hit)
                tie_count += 1

                # loose 模式故意允許同一個 primary if 對到多個 tie if，
                # 但限制數量避免輸出爆炸。
                if tie_count >= max_ties_per_if:
                    break

                # exact 模式通常最近的一個就夠了
                if match_mode == "exact":
                    break

    # 去除完全重複 hit
    uniq = []
    seen = set()
    for h in hits:
        key = (h["start"], h["end"], h["op"], h["lhs1"], h["rhs1"],
               h["lhs2"], h["rhs2"], h["level"])
        if key not in seen:
            seen.add(key)
            uniq.append(h)

    return uniq


def line_number(text: str, pos: int) -> int:
    return text.count("\n", 0, pos) + 1


def make_snippet(text: str, start: int, end: int, context_lines=2, tail_lines=8):
    lines = text.splitlines()
    s = line_number(text, start)
    e = line_number(text, end)
    lo = max(1, s - context_lines)
    hi = min(len(lines), e + tail_lines)

    return "\n".join(
        f"{no:4d}: {lines[no - 1]}"
        for no in range(lo, hi + 1)
    )


def main():
    parser = argparse.ArgumentParser(
        description="Loosely find best-update + tie-handling patterns in C++ solutions"
    )
    parser.add_argument("--base", default=DEFAULT_BASE, help="solution directory")
    parser.add_argument(
        "--mode", choices=["max", "min", "both"], default="both",
        help="max: > then ==, min: < then ==, both: search both"
    )
    parser.add_argument(
        "--match", choices=["exact", "loose"], default="loose",
        help="exact: same pair only; loose: at least one expression shared (default)"
    )
    parser.add_argument(
        "--gap", type=int, default=1400,
        help="maximum chars between primary if and equality if (default: 1400)"
    )
    parser.add_argument(
        "--ties", type=int, default=3,
        help="max equality matches kept per primary if in loose mode (default: 3)"
    )
    parser.add_argument("--show", action="store_true", help="show source snippets")
    parser.add_argument(
        "--exact-only-output", action="store_true",
        help="搜尋仍用 loose，但最後只印 EXACT；方便比較結果"
    )
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

        hits = find_patterns(
            content,
            mode=args.mode,
            match_mode=args.match,
            max_gap=args.gap,
            max_ties_per_if=max(1, args.ties),
        )

        if args.exact_only_output:
            hits = [h for h in hits if h["level"] == "EXACT"]

        if hits:
            matched.append((filename, content, hits))

    exact_files = sum(any(h["level"] == "EXACT" for h in hits) for _, _, hits in matched)
    loose_files = sum(any(h["level"] == "LOOSE" for h in hits) for _, _, hits in matched)

    print(f"\n找到 {len(matched)} 個候選檔案")
    print(f"  含 EXACT: {exact_files}")
    print(f"  含 LOOSE: {loose_files}")
    print(f"  mode={args.mode}, match={args.match}, gap={args.gap}\n")

    for filename, content, hits in matched:
        num = filename.replace("Solution_", "").replace(".cpp", "")
        kinds = sorted(set("MAX" if h["op"] == ">" else "MIN" for h in hits))
        levels = sorted(set(h["level"] for h in hits), key=lambda x: 0 if x == "EXACT" else 1)
        print(f"  {num:>4}  ->  {filename}   [{'/'.join(kinds)}] [{'/'.join(levels)}]")

        if args.show:
            for n, h in enumerate(hits, 1):
                print(f"       hit {n}: [{h['level']}] if ({h['cond1']})")
                print(f"              tie ({h['cond2']})   gap={h['gap']}")
                print(f"              primary: {h['lhs1']} {h['op']} {h['rhs1']}")
                print(f"              equality: {h['lhs2']} == {h['rhs2']}")
                print(make_snippet(content, h["start"], h["end"]))
                print("       " + "-" * 74)

    print("\n建議：先用寬鬆模式挖候選：")
    print("  python3 tools/find_reset_pattern_loose.py --mode max --match loose --show")
    print("\n想再多抓一些：")
    print("  python3 tools/find_reset_pattern_loose.py --mode max --match loose --gap 2200 --ties 5 --show")
    print("\n想回頭只看高可信結果：")
    print("  python3 tools/find_reset_pattern_loose.py --mode max --match exact --show")


if __name__ == "__main__":
    main()
