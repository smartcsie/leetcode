#!/usr/bin/env python3
"""
cleanup_obsolete_tools.py

刪除 tools/ 資料夾裡已經確認過時的腳本：
    1. 一次性搬移/修復腳本（TODO.md「已完成的重大工作」逐項核對過，任務已完成）
    2. 可能過時、功能被取代的腳本（add_new_solutions/extract_metadata 被
       solution-generator.html 取代；diagnose/diagnose2 被 check.py 取代；
       wrap_solutions 用途待確認）

預設是 dry-run（只列出會刪什麼，不會真的刪），要真的刪除要加 --yes。
用 git rm 刪除（如果在 git repo 裡），這樣刪除本身也會被記錄進 git 歷史，
之後想找回來可以用 git log / git revert，不是真的憑空消失。

用法：
    python3 cleanup_obsolete_tools.py [tools_dir]              # dry-run，只列出
    python3 cleanup_obsolete_tools.py [tools_dir] --yes         # 真的刪除

    tools_dir  預設 'tools'
"""
import sys
import os
import subprocess

# 一次性搬移/修復腳本，任務已完成
ONE_TIME_DONE = [
    "split_docs.py",
    "fix_missing_files.py",
    "patch_familiarity_feature.py",
    "reset_all_familiarity.py",
    "patch_multi_solution_features.py",
    "fix_comment_linebreaks.py",
    "migrate_notes_to_metadata.py",
    "patch_remove_notes_folder.py",
    "migrate_topics.py",
    "set_gcd_topic.py",
    "patch_table_columns.py",
    "fix_table_full.py",
    "normalize_complexity_case.py",
    "strip_complexity_spaces.py",
    "normalize_comments.py",
    "normalize_tags_slash.py",
    "patch_groups.py",
    "check_and_fix.py",
    "apply_recategorization.py",
    "apply_uncategorized_fixes.py",
    "find_recategorize_candidates.py",
    "check_multi_solution_migration.py",
    "check_skeleton_data.py",
    "cleanup_old_docs.py",
]

# 可能過時、功能被取代
POSSIBLY_OBSOLETE = [
    "add_new_solutions.py",
    "extract_metadata.py",
    "diagnose.py",
    "diagnose2.py",
    "wrap_solutions.py",
]

ALL_TARGETS = ONE_TIME_DONE + POSSIBLY_OBSOLETE


def is_git_repo():
    return subprocess.run(
        ["git", "rev-parse", "--is-inside-work-tree"],
        capture_output=True, text=True
    ).returncode == 0


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    tools_dir = args[0] if args else "tools"
    do_delete = "--yes" in sys.argv

    if not os.path.isdir(tools_dir):
        print(f"❌ 找不到資料夾: {tools_dir}")
        sys.exit(1)

    found = []
    missing = []
    for name in ALL_TARGETS:
        path = os.path.join(tools_dir, name)
        if os.path.exists(path):
            found.append(path)
        else:
            missing.append(name)

    print(f"會刪除的檔案（共 {len(found)} 個）：\n")
    print("一次性搬移/修復腳本：")
    for name in ONE_TIME_DONE:
        path = os.path.join(tools_dir, name)
        if os.path.exists(path):
            print(f"  🗑️  {path}")
    print("\n可能過時、功能被取代：")
    for name in POSSIBLY_OBSOLETE:
        path = os.path.join(tools_dir, name)
        if os.path.exists(path):
            print(f"  🗑️  {path}")

    if missing:
        print(f"\n（{len(missing)} 個在清單裡但資料夾中找不到，跳過：{', '.join(missing)}）")

    if not found:
        print("\n沒有要刪除的檔案，結束。")
        return

    if not do_delete:
        print(f"\n這是 dry-run，還沒有真的刪除任何檔案。")
        print(f"確認沒問題後，加上 --yes 再跑一次：")
        print(f"  python3 {os.path.basename(__file__)} {tools_dir} --yes")
        return

    use_git = is_git_repo()
    print(f"\n開始刪除{'（用 git rm，會一併 stage）' if use_git else '（純 rm，不是 git repo 或非 git 追蹤）'}...")

    failed = []
    for path in found:
        try:
            if use_git:
                result = subprocess.run(["git", "rm", "-q", path], capture_output=True, text=True)
                if result.returncode != 0:
                    # 可能是沒被 git 追蹤的檔案，退回用一般刪除
                    os.remove(path)
            else:
                os.remove(path)
            print(f"  ✓ 已刪除 {path}")
        except OSError as e:
            failed.append((path, str(e)))
            print(f"  ✗ 刪除失敗 {path}: {e}")

    print(f"\n完成：刪除 {len(found) - len(failed)}/{len(found)} 個檔案。")
    if use_git:
        print("記得檢查 git status，確認後 git commit。")


if __name__ == "__main__":
    main()
