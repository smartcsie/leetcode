#!/usr/bin/env python3
"""
一鍵同步：打開就 pull 最新的 code，不管在家裡還是公司都能跑。

用法：
  python3 sync_repo.py               # 用預設路徑 ~/leetcode-docs/repo
  python3 sync_repo.py /path/to/repo # 指定其他路徑

行為：
  1. 如果有還沒 commit 的變更，先自動 stash 起來（不會弄丟你的東西）
  2. git fetch
  3. git pull --rebase
  4. 如果剛剛有 stash，pull 完再自動 pop 回來
  5. 全部訊息用中文印出來，出問題會停下來告訴你要手動處理什麼
"""
import os
import subprocess
import sys


def run(cmd, cwd):
    """執行指令，回傳 (returncode, stdout+stderr 文字)。"""
    result = subprocess.run(
        cmd, cwd=cwd, shell=False,
        stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
        text=True,
    )
    return result.returncode, result.stdout


def main():
    repo_dir = sys.argv[1] if len(sys.argv) > 1 else os.path.expanduser("~/leetcode-docs/repo")

    if not os.path.isdir(os.path.join(repo_dir, ".git")):
        print(f"❌ 這裡不是一個 git repo：{repo_dir}")
        print("   可以用 python3 sync_repo.py <repo路徑> 指定正確位置")
        sys.exit(1)

    print(f"📂 repo 位置：{repo_dir}\n")

    # 1. 檢查有沒有未 commit 的變更
    code, out = run(["git", "status", "--porcelain"], repo_dir)
    has_local_changes = bool(out.strip())
    stashed = False

    if has_local_changes:
        print("⚠️  發現還沒 commit 的變更，先幫你 stash 起來：")
        print(out)
        code, out = run(["git", "stash", "push", "-m", "sync_repo.py 自動 stash"], repo_dir)
        print(out)
        if code != 0:
            print("❌ stash 失敗，中止（避免弄丟你的變更），請自己檢查 git status")
            sys.exit(1)
        stashed = True

    # 2. fetch
    print("▶ git fetch origin ...")
    code, out = run(["git", "fetch", "origin"], repo_dir)
    print(out)
    if code != 0:
        print("❌ fetch 失敗，請檢查網路連線或 GitHub 認證（token 是否過期）")
        sys.exit(1)

    # 3. pull --rebase
    print("▶ git pull --rebase origin ...")
    code, out = run(["git", "pull", "--rebase", "origin"], repo_dir)
    print(out)

    if code != 0:
        print("❌ pull --rebase 失敗，很可能是衝突（conflict）。")
        print("   請手動處理：")
        print("     git status                看哪些檔案衝突")
        print("     （解決衝突後）git add <檔案> && git rebase --continue")
        print("     如果想先放棄這次 rebase：git rebase --abort")
        if stashed:
            print("\n⚠️  你原本未 commit 的變更還在 stash 裡，處理完 rebase 之後記得執行：")
            print("     git stash pop")
        sys.exit(1)

    print("✅ pull 完成，已經是最新的 code")

    # 4. 如果剛剛有 stash，pop 回來
    if stashed:
        print("\n▶ 把你原本的變更 stash pop 回來 ...")
        code, out = run(["git", "stash", "pop"], repo_dir)
        print(out)
        if code != 0:
            print("⚠️  stash pop 有衝突，你的變更還安全地留在 stash 裡（沒有弄丟）。")
            print("   請手動處理：git status 看衝突，解決後 git stash drop 清掉這筆 stash")
            sys.exit(1)
        print("✅ 你原本的變更已經拿回來了")

    print("\n🎉 全部完成，可以開始工作了")


if __name__ == "__main__":
    main()
