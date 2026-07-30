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

def wrap_solutions(source_dir, output_dir):
    os.makedirs(output_dir, exist_ok=True)
    # 清空舊的產出，避免殘留已刪除的題解
    for fname in os.listdir(output_dir):
        os.remove(os.path.join(output_dir, fname))

    wrapped = 0
    for fname in sorted(os.listdir(source_dir)):
        base, ext = os.path.splitext(fname)
        if ext not in LANG_MAP:
            continue
        src_path = os.path.join(source_dir, fname)
        md_path = os.path.join(output_dir, base + '.md')
        with open(src_path, 'r', encoding='utf-8', errors='replace') as f:
            code = f.read()
        lang = LANG_MAP[ext]
        content = f"# {base}\n\n```{lang}\n{code}\n```\n"
        with open(md_path, 'w', encoding='utf-8') as f:
            f.write(content)
        wrapped += 1
    print(f"Wrapped {wrapped} files from {source_dir} into {output_dir}")

def rewrite_links(docs_dir, output_folder_name='solution-pages'):
    # 抓取任何指向 ./solution/XXX.cpp 或 ./solution/XXX.cpp.md 的連結
    pattern = re.compile(
        r'\(\.?/?solution/([^)\s./]+)\.(?:cpp|sql|py|java)(?:\.md)?\)'
    )
    changed_files = 0
    total_replacements = 0
    for root, _, files in os.walk(docs_dir):
        for fname in files:
            if not fname.endswith('.md'):
                continue
            fpath = os.path.join(root, fname)
            if f'{os.sep}{output_folder_name}{os.sep}' in fpath:
                continue
            with open(fpath, 'r', encoding='utf-8', errors='replace') as f:
                text = f.read()

            def repl(m):
                return f'(./{output_folder_name}/{m.group(1)}.md)'

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
        print("Usage: python3 wrap_solutions.py <source_solution_dir> <docs_dir>")
        sys.exit(1)
    source_dir = sys.argv[1]
    docs_dir = sys.argv[2]
    output_dir = os.path.join(docs_dir, 'solution-pages')
    wrap_solutions(source_dir, output_dir)
    rewrite_links(docs_dir)

if __name__ == '__main__':
    main()
