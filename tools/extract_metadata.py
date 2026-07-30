#!/usr/bin/env python3
import sys
import os
import re
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml")
    sys.exit(1)

SEP_RE = re.compile(r'^[\s:|-]+$')
LINK_RE = re.compile(r'\[([^\]]+)\]\(([^)]+)\)')
CODE_FILE_RE = re.compile(r'(Solution_[A-Za-z0-9_]+)\.(cpp|md|sql|py|java)')
NOTE_HEADING_RE = re.compile(r'^###\s+(\d+)(?:-(\d+))?[\.\s]*(.*)$')

def slug_of_filename(fname):
    return os.path.splitext(fname)[0]

def split_row(line):
    line = line.rstrip('\n').rstrip()
    if not line.startswith('|'):
        return None
    inner = line[1:]
    if inner.endswith('|'):
        inner = inner[:-1]
    return [c.strip() for c in inner.split('|')]

def parse_table_rows(lines, topic_slug):
    rows = []
    for line in lines:
        cells = split_row(line)
        if cells is None or len(cells) < 7:
            continue
        if len(cells) == 7:
            cells = cells + ['']
        if cells[0] in ('#',) or SEP_RE.match(cells[0]):
            continue
        num_text = cells[0].replace('*', '').strip()
        num_match = re.search(r'\d+', num_text)
        if not num_match:
            continue
        number = int(num_match.group())

        title, url = '', ''
        lm = LINK_RE.search(cells[1])
        if lm:
            title, url = lm.group(1), lm.group(2)
        else:
            title = cells[1]

        difficulty = cells[2].replace('&nbsp;', ' ').strip()
        tags = [t.strip() for t in re.split(r'<br\s*/?>', cells[3]) if t.strip()]

        code_file = None
        cm = CODE_FILE_RE.search(cells[4])
        if cm:
            code_file = f"{cm.group(1)}.{cm.group(2) if cm.group(2) == 'sql' else 'cpp'}"

        time_c = cells[5]
        space_c = cells[6]

        note_anchor = None
        nm = LINK_RE.search(cells[7])
        if nm:
            note_anchor = nm.group(2).lstrip('#')

        rows.append({
            'number': number, 'title': title, 'url': url,
            'difficulty': difficulty, 'tags': tags, 'code_file': code_file,
            'time': time_c, 'space': space_c, 'note_anchor': note_anchor,
            'topic': topic_slug,
        })
    return rows

def parse_notes(lines):
    notes = {}
    current_number = None
    current_lines = []

    def flush():
        if current_number is not None:
            text = '\n'.join(current_lines).strip()
            if text:
                notes[current_number] = text

    for line in lines:
        m = NOTE_HEADING_RE.match(line.rstrip())
        if m:
            flush()
            current_number = int(m.group(1))
            current_lines = []
            continue
        if line.strip() == '---':
            continue
        if current_number is not None:
            current_lines.append(line.rstrip('\n'))
    flush()
    return notes

def main():
    if len(sys.argv) != 4:
        print("Usage: python3 extract_metadata.py <docs_dir> <metadata_out_dir> <notes_out_dir>")
        sys.exit(1)

    docs_dir, meta_dir, notes_dir = sys.argv[1], sys.argv[2], sys.argv[3]
    os.makedirs(meta_dir, exist_ok=True)
    os.makedirs(notes_dir, exist_ok=True)

    problems = {}
    md_files = sorted(glob.glob(os.path.join(docs_dir, '*.md')))
    for fpath in md_files:
        fname = os.path.basename(fpath)
        if fname in ('index.md',):
            continue
        topic_slug = slug_of_filename(fname)
        with open(fpath, 'r', encoding='utf-8', errors='replace') as f:
            lines = f.readlines()

        rows = parse_table_rows(lines, topic_slug)
        notes = parse_notes(lines)

        for row in rows:
            number = row['number']
            note_text = notes.get(number)

            problems.setdefault(number, [])
            existing = None
            for sol in problems[number]:
                if sol.get('file') == row['code_file']:
                    existing = sol
                    break

            if existing:
                if topic_slug not in existing['topics']:
                    existing['topics'].append(topic_slug)
                for t in row['tags']:
                    if t not in existing['tags']:
                        existing['tags'].append(t)
                if not existing.get('note') and note_text:
                    existing['note'] = note_text
            else:
                problems[number].append({
                    'file': row['code_file'], 'difficulty': row['difficulty'],
                    'tags': row['tags'], 'topics': [topic_slug],
                    'time': row['time'], 'space': row['space'],
                    'title': row['title'], 'url': row['url'], 'note': note_text,
                })

    written_meta = 0
    written_notes = 0
    for number, solutions in sorted(problems.items()):
        title = solutions[0]['title']
        url = solutions[0]['url']
        meta = {'number': number, 'title': title, 'url': url, 'solutions': []}
        note_parts = []
        for sol in solutions:
            meta['solutions'].append({
                'file': sol['file'], 'difficulty': sol['difficulty'],
                'tags': sol['tags'], 'topics': sol['topics'],
                'time': sol['time'], 'space': sol['space'],
            })
            if sol.get('note'):
                label = ' / '.join(sol['topics'])
                note_parts.append(f"### 解法（{label}）\n\n{sol['note']}")

        meta_path = os.path.join(meta_dir, f"{number:04d}.yml")
        with open(meta_path, 'w', encoding='utf-8') as f:
            yaml.dump(meta, f, allow_unicode=True, sort_keys=False)
        written_meta += 1

        if note_parts:
            note_path = os.path.join(notes_dir, f"{number:04d}.md")
            with open(note_path, 'w', encoding='utf-8') as f:
                f.write('\n\n---\n\n'.join(note_parts) + '\n')
            written_notes += 1

    print(f"共處理 {len(problems)} 題")
    print(f"寫入 metadata: {written_meta} 個檔案 -> {meta_dir}/")
    print(f"寫入 notes: {written_notes} 個檔案 -> {notes_dir}/")

if __name__ == '__main__':
    main()
