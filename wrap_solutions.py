#!/usr/bin/env python3
import sys
import os
import re

LANG_MAP = {
    '.cpp': 'cpp',
    '.sql': 'sql',
    '.py': 'python',
    '.java': 'java',
}

def wrap_solutions(solution_dir):
    wrapped = 0
    for fname in sorted(os.listdir(solution_dir)):
        base, ext = os.path.splitext(fname)
        if ext not in LANG_MAP:
            continue
        src_path = os.path.join(solution_dir, fname)
        md_path = src_path + '.md'
        with open(src_path, 'r', encoding='utf-8', errors='replace') as f:
            code = f.read()
        lang = LANG_MAP[ext]
        content = f"# {base}\n\n```{lang}\n{code}\n```\n"
        with open(md_path, 'w', encoding='utf-8') as f:
            f.write(content)
        wrapped += 1
    print(f"Wrapped {wrapped} solution files into .md pages in {solution_dir}")

def rewrite_links(docs_dir, solution_folder_name='solution'):
    pattern = re.compile(
        r'(\(\.?/?' + re.escape(solution_folder_name) + r'/[^)\s]+?\.(?:cpp|sql|py|java))\)'
    )
    changed_files = 0
    total_replacements = 0
    for root, _, files in os.walk(docs_dir):
        for fname in files:
            if not fname.endswith('.md'):
                continue
            fpath = os.path.join(root, fname)
            if os.sep + solution_folder_name + os.sep in fpath or fpath.endswith(solution_folder_name):
                continue
            with open(fpath, 'r', encoding='utf-8', errors='replace') as f:
                text = f.read()

            def repl(m):
                return m.group(1) + '.md)'

            new_text, n = pattern.subn(repl, text)
            if n > 0:
                with open(fpath, 'w', encoding='utf-8') as f:
                    f.write(new_text)
                changed_files += 1
                total_replacements += n
                print(f"  {fname}: {n} link(s) updated")

    print(f"\nUpdated {total_replacements} links across {changed_files} files")

def main():
    if len(sys.argv) != 3:
        print("Usage: python3 wrap_solutions.py <solution_dir> <docs_dir>")
        sys.exit(1)
    solution_dir = sys.argv[1]
    docs_dir = sys.argv[2]
    wrap_solutions(solution_dir)
    rewrite_links(docs_dir)

if __name__ == '__main__':
    main()
