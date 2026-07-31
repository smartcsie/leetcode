#!/usr/bin/env python3
import sys

OLD_LOAD_NOTE_FUNC = '''def load_note(notes_dir, number):
    path = os.path.join(notes_dir, f"{number:04d}.md")
    if not os.path.exists(path):
        return {}
    with open(path, encoding='utf-8', errors='replace') as f:
        text = f.read()
    parts = re.split(r'^### 解法（([^）]*)）\\s*$', text, flags=re.MULTILINE)
    notes_by_label = {}
    for i in range(1, len(parts), 2):
        label = parts[i]
        body = parts[i + 1] if i + 1 < len(parts) else ''
        body = re.sub(r'\\n-{3,}\\s*$', '', body).strip()
        notes_by_label[label] = body
    return notes_by_label

'''

OLD_SIGNATURE = 'def build_problem_page(problem, solution_dir, notes_dir):'
NEW_SIGNATURE = 'def build_problem_page(problem, solution_dir):'

OLD_LOAD_CALL = "    notes_by_label = load_note(notes_dir, number)\n"

OLD_NOTE_BODY_LINE = "        note_body = notes_by_label.get(label_key)"
NEW_NOTE_BODY_LINE = "        note_body = sol.get('note')"

OLD_MAIN_USAGE = '''    if len(sys.argv) != 5:
        print("Usage: python3 generate_site.py <metadata_dir> <notes_dir> <solution_dir> <docs_dir>")
        sys.exit(1)

    meta_dir, notes_dir, solution_dir, docs_dir = sys.argv[1:5]'''
NEW_MAIN_USAGE = '''    if len(sys.argv) != 4:
        print("Usage: python3 generate_site.py <metadata_dir> <solution_dir> <docs_dir>")
        sys.exit(1)

    meta_dir, solution_dir, docs_dir = sys.argv[1:4]'''

OLD_BUILD_CALL = "content, missing = build_problem_page(problem, solution_dir, notes_dir)"
NEW_BUILD_CALL = "content, missing = build_problem_page(problem, solution_dir)"

def apply_patch(content, old, new, label):
    if old not in content:
        print(f"❌ 找不到錨點，無法套用「{label}」，請手動處理")
        return content, False
    return content.replace(old, new, 1), True

def main():
    path = sys.argv[1] if len(sys.argv) > 1 else 'generate_site.py'
    with open(path, 'r', encoding='utf-8') as f:
        content = f.read()

    if OLD_LOAD_NOTE_FUNC in content:
        content = content.replace(OLD_LOAD_NOTE_FUNC, '', 1)
        print("✓ 已移除 load_note() 函式")
    else:
        print("（load_note 函式看起來已經移除過，跳過）")

    content, ok1 = apply_patch(content, OLD_SIGNATURE, NEW_SIGNATURE, 'build_problem_page 移除 notes_dir 參數')

    if OLD_LOAD_CALL in content:
        content = content.replace(OLD_LOAD_CALL, '', 1)
        print("✓ 已移除 notes_by_label = load_note(...) 呼叫")
        ok2 = True
    else:
        print("（load_note 呼叫看起來已經移除過，跳過）")
        ok2 = True

    content, ok3 = apply_patch(content, OLD_NOTE_BODY_LINE, NEW_NOTE_BODY_LINE, 'note_body 改讀 metadata')
    content, ok4 = apply_patch(content, OLD_MAIN_USAGE, NEW_MAIN_USAGE, 'main() 參數簽名（移除 notes_dir）')
    content, ok5 = apply_patch(content, OLD_BUILD_CALL, NEW_BUILD_CALL, 'main() 呼叫 build_problem_page')

    ok_all = ok1 and ok2 and ok3 and ok4 and ok5

    with open(path, 'w', encoding='utf-8') as f:
        f.write(content)

    print("\n✅ 全部套用完成" if ok_all else "\n⚠️ 有部分無法自動套用，請照上方訊息手動處理")

if __name__ == '__main__':
    main()
