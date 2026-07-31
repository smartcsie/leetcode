#!/usr/bin/env python3
import sys
import re

REVIEW_PAGE_FUNC = '''
def build_review_page(problems, docs_dir):
    """列出所有標記為「生疏」的解法，寫成 docs/review.md 複習清單"""
    rows = []
    for problem in problems:
        for sol in problem['solutions']:
            if sol.get('familiarity') == '生疏':
                rows.append({
                    'number': problem['number'],
                    'title': problem['title'],
                    'file': sol.get('file', ''),
                    'difficulty': sol.get('difficulty', ''),
                    'topics': ', '.join(to_list(sol.get('topics'))),
                })
    rows.sort(key=lambda r: r['number'])

    lines = ['# 📝 複習清單（生疏）', '',
             f'目前共有 {len(rows)} 個解法標記為生疏，建議找時間重新練習。', '',
             '| # | 題目 | 難度 | 解法檔案 | 分類 |',
             '| --- | --- | --- | --- | --- |']
    for r in rows:
        link = f"problems/{r['number']:04d}.md"
        lines.append(f"| {r['number']} | [{r['title']}]({link}) | {r['difficulty']} | {r['file']} | {r['topics']} |")

    with open(os.path.join(docs_dir, 'review.md'), 'w', encoding='utf-8') as f:
        f.write('\\n'.join(lines) + '\\n')

    return len(rows)


'''

OLD_INFO_BLOCK = '''        info = (f"**難度:** {sol.get('difficulty','')}　"
                f"**標籤:** {tags_str}　"
                f"**時間:** {sol.get('time','')}　"
                f"**空間:** {sol.get('space','')}")'''

NEW_INFO_BLOCK = '''        familiarity = sol.get('familiarity')
        familiarity_badge = ''
        if familiarity == '熟練':
            familiarity_badge = '　**熟悉度:** 🟢 熟練'
        elif familiarity == '生疏':
            familiarity_badge = '　**熟悉度:** 🔴 生疏'

        info = (f"**難度:** {sol.get('difficulty','')}　"
                f"**標籤:** {tags_str}　"
                f"**時間:** {sol.get('time','')}　"
                f"**空間:** {sol.get('space','')}{familiarity_badge}")'''

OLD_MAIN_TOPICROWS = "    topic_rows = build_topic_indexes(problems, topics_out_dir)\n    print(f\"\\n寫入 {len(topic_rows)} 個 docs/topics/*.md\")"
NEW_MAIN_TOPICROWS = OLD_MAIN_TOPICROWS + '''

    review_count = build_review_page(problems, docs_dir)
    print(f"複習清單（生疏）: {review_count} 筆 -> docs/review.md")'''

OLD_NAV_HOME = '    print("  - 首頁: index.md")'
NEW_NAV_HOME = OLD_NAV_HOME + '\n    print("  - 📝 複習清單: review.md")'


def apply_patch(content, old, new, label):
    if old not in content:
        print(f"❌ 找不到錨點，無法套用「{label}」，請手動處理")
        return content, False
    if new in content:
        print(f"（「{label}」看起來已經套用過，跳過）")
        return content, True
    return content.replace(old, new, 1), True


def main():
    path = sys.argv[1] if len(sys.argv) > 1 else 'generate_site.py'
    with open(path, 'r', encoding='utf-8') as f:
        content = f.read()

    ok_all = True

    if 'def build_review_page' not in content:
        marker = 'def main():'
        if marker not in content:
            print("❌ 找不到 def main():，無法插入 build_review_page")
            ok_all = False
        else:
            content = content.replace(marker, REVIEW_PAGE_FUNC + marker, 1)
            print("✓ 已插入 build_review_page() 函式")
    else:
        print("（build_review_page 已存在，跳過插入）")

    content, ok1 = apply_patch(content, OLD_INFO_BLOCK, NEW_INFO_BLOCK, '題目頁熟悉度徽章')
    content, ok2 = apply_patch(content, OLD_MAIN_TOPICROWS, NEW_MAIN_TOPICROWS, 'main() 呼叫 build_review_page')
    content, ok3 = apply_patch(content, OLD_NAV_HOME, NEW_NAV_HOME, 'nav 加入複習清單連結')

    ok_all = ok_all and ok1 and ok2 and ok3

    with open(path, 'w', encoding='utf-8') as f:
        f.write(content)

    if ok_all:
        print("\n✅ 全部套用完成")
    else:
        print("\n⚠️ 有部分無法自動套用，請照上方訊息手動處理")


if __name__ == '__main__':
    main()
