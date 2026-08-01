#!/usr/bin/env python3
import sys
import re

COMPLEXITY_RANK_FUNC = '''
def complexity_rank(time_str):
    """回傳一個數字，越小代表複雜度越低（越快）。無法辨識的排最後。"""
    if not time_str:
        return 999
    m = re.match(r'\\s*O\\(([^)]*)\\)', time_str.strip())
    if not m:
        return 998
    t = m.group(1).replace(' ', '').upper()

    if t in ('1',):
        return 0

    if re.search(r'\\d\\^N|2\\^N|K\\^N|N!', t):
        return 100

    power_match = re.search(r'N[\\^²³](\\d*)', t)
    if power_match:
        exp_str = power_match.group(1)
        if exp_str:
            exp_val = int(exp_str)
        elif '²' in t:
            exp_val = 2
        elif '³' in t:
            exp_val = 3
        else:
            exp_val = 2
        return 20 * exp_val

    log_pos = t.find('LOG')
    if log_pos != -1:
        prefix = t[:log_pos]
        if re.search(r'[A-Z]', prefix):
            return 15
        return 1

    if 'SQRT' in t:
        return 5

    if re.search(r'[A-Z]', t):
        return 10

    return 3

'''

OLD_SOLUTIONS_LINE = "    solutions = problem['solutions']"
NEW_SOLUTIONS_LINE = "    solutions = sorted(problem['solutions'], key=lambda s: complexity_rank(s.get('time', '')))"

OLD_INFO_BLOCK = '''        familiarity_badge = ''
        if familiarity == '熟練':
            familiarity_badge = '　**熟悉度:** 🟢 熟練'
        elif familiarity == '生疏':
            familiarity_badge = '　**熟悉度:** 🔴 生疏'

        info = (f"**難度:** {sol.get('difficulty','')}　"
                f"**標籤:** {tags_str}　"
                f"**時間:** {sol.get('time','')}　"
                f"**空間:** {sol.get('space','')}{familiarity_badge}")'''

NEW_INFO_BLOCK = '''        familiarity_badge = ''
        if familiarity == '熟練':
            familiarity_badge = '　**熟悉度:** 🟢 熟練'
        elif familiarity == '生疏':
            familiarity_badge = '　**熟悉度:** 🔴 生疏'

        best_badge = '　🏆 **最佳解**' if sol.get('is_best') else ''

        info = (f"**難度:** {sol.get('difficulty','')}　"
                f"**標籤:** {tags_str}　"
                f"**時間:** {sol.get('time','')}　"
                f"**空間:** {sol.get('space','')}{familiarity_badge}{best_badge}")'''

OLD_NOTE_BLOCK = '''        note_body = sol.get('note')
        if note_body:
            lines.append(note_body)
            lines.append('')

        if multi:'''

NEW_NOTE_BLOCK = '''        note_body = sol.get('note')
        if note_body:
            lines.append(note_body)
            lines.append('')

        related = to_list(sol.get('related'))
        if related:
            related_links = ', '.join(
                f"[{r}](../problems/{int(r):04d}.md)" for r in related
            )
            lines.append(f"**相關題目:** {related_links}")
            lines.append('')

        if multi:'''


def apply_patch(content, old, new, label):
    if old not in content:
        print(f"❌ 找不到錨點，無法套用「{label}」，請手動處理")
        return content, False
    return content.replace(old, new, 1), True


def main():
    path = sys.argv[1] if len(sys.argv) > 1 else 'generate_site.py'
    with open(path, 'r', encoding='utf-8') as f:
        content = f.read()

    if 'def complexity_rank' not in content:
        marker = 'def build_problem_page('
        if marker not in content:
            print("❌ 找不到 def build_problem_page(，無法插入 complexity_rank")
            sys.exit(1)
        content = content.replace(marker, COMPLEXITY_RANK_FUNC + marker, 1)
        print("✓ 已插入 complexity_rank() 函式")
    else:
        print("（complexity_rank 已存在，跳過插入）")

    content, ok1 = apply_patch(content, OLD_SOLUTIONS_LINE, NEW_SOLUTIONS_LINE, '依複雜度排序')
    content, ok2 = apply_patch(content, OLD_INFO_BLOCK, NEW_INFO_BLOCK, '最佳解徽章')
    content, ok3 = apply_patch(content, OLD_NOTE_BLOCK, NEW_NOTE_BLOCK, '相關題目區塊')

    with open(path, 'w', encoding='utf-8') as f:
        f.write(content)

    if ok1 and ok2 and ok3:
        print("\n✅ 全部套用完成")
    else:
        print("\n⚠️ 有部分無法自動套用，請照上方訊息手動處理")

if __name__ == '__main__':
    main()
