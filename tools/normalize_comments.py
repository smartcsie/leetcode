#!/usr/bin/env python3
import re
import os
import argparse

FIELD_LABELS = ['題目', '難度', '描述', '時間複雜度', '空間複雜度', '解法思路']

ALIASES = {
    'time complexity': '時間複雜度',
    'space complexity': '空間複雜度',
    '解題思路': '解法思路',
    '優化思路': '解法思路',
    '思路': '解法思路',
}

ALL_LABEL_KEYS = FIELD_LABELS + list(ALIASES.keys())
LABEL_RE = re.compile(
    r'^(' + '|'.join(re.escape(k) for k in ALL_LABEL_KEYS) + r')[:：]?\s*(.*)$',
    flags=re.IGNORECASE
)
LEADING_STARS_RE = re.compile(r'^\s*(\*\s*)+')
PLACEHOLDER = '待補充'

def normalize_label(raw_label):
    key = raw_label.lower()
    if raw_label in FIELD_LABELS:
        return raw_label
    if key in ALIASES:
        return ALIASES[key]
    return raw_label

def extract_comment_block(text):
    m = re.search(r'/\*\*(.*?)\*/', text, flags=re.DOTALL)
    if not m:
        return None
    before = text[:m.start()]
    after = text[m.end():]
    inner = m.group(1)
    raw_lines = inner.split('\n')
    return before, raw_lines, after

def parse_fields(raw_lines):
    fields = {label: [] for label in FIELD_LABELS}
    current = None
    for line in raw_lines:
        cleaned = LEADING_STARS_RE.sub('', line).rstrip()
        if cleaned == '':
            continue
        m = LABEL_RE.match(cleaned)
        if m:
            label = normalize_label(m.group(1))
            if label in fields:
                current = label
                rest = m.group(2).strip()
                if rest:
                    fields[current].append(rest)
                continue
        if current:
            fields[current].append(cleaned.strip())
    return fields

def rebuild_comment(fields):
    lines = ['/**']
    title = fields['題目'][0] if fields['題目'] else PLACEHOLDER
    lines.append(f' * 題目：{title}')

    difficulty = fields['難度'][0] if fields['難度'] else PLACEHOLDER
    lines.append(f' * 難度：{difficulty}')

    if fields['描述']:
        lines.append(' * 描述：' + fields['描述'][0])
        for extra in fields['描述'][1:]:
            lines.append(' * ' + extra)
    else:
        lines.append(f' * 描述：{PLACEHOLDER}')

    lines.append(' *')
    time_c = ' '.join(fields['時間複雜度']) if fields['時間複雜度'] else PLACEHOLDER
    space_c = ' '.join(fields['空間複雜度']) if fields['空間複雜度'] else PLACEHOLDER
    lines.append(f' * 時間複雜度：{time_c}')
    lines.append(f' * 空間複雜度：{space_c}')

    if fields['解法思路']:
        lines.append(' *')
        lines.append(' * 解法思路：')
        for item in fields['解法思路']:
            lines.append(' * ' + item)

    lines.append(' */')
    return '\n'.join(lines)

def insert_skeleton(text):
    skeleton = "/**\n * 註解：待補充\n */\n"
    return skeleton + text

def process_file(path, apply_changes):
    with open(path, 'r', encoding='utf-8', errors='replace') as f:
        text = f.read()

    result = extract_comment_block(text)
    if result is None:
        if apply_changes:
            new_text = insert_skeleton(text)
            with open(path, 'w', encoding='utf-8') as f:
                f.write(new_text)
        return 'SKELETON_INSERTED' if apply_changes else 'WOULD_INSERT_SKELETON'

    before, raw_lines, after = result
    fields = parse_fields(raw_lines)
    new_comment = rebuild_comment(fields)
    new_text = before + new_comment + after

    if apply_changes:
        with open(path, 'w', encoding='utf-8') as f:
            f.write(new_text)
    return 'OK'

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('solution_dir')
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('--dry-run', action='store_true')
    args = ap.parse_args()
    apply_changes = args.apply

    counts = {}
    for fname in sorted(os.listdir(args.solution_dir)):
        if not fname.endswith('.cpp'):
            continue
        path = os.path.join(args.solution_dir, fname)
        status = process_file(path, apply_changes)
        counts[status] = counts.get(status, 0) + 1

    mode = "APPLIED" if apply_changes else "DRY RUN (no files changed)"
    print(f"\n=== {mode} ===")
    for status, n in counts.items():
        print(f"{status}: {n}")

if __name__ == '__main__':
    main()
