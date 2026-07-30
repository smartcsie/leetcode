#!/usr/bin/env bash
set -euo pipefail

COMMIT_MSG="${1:-}"

if [ -z "$COMMIT_MSG" ]; then
  echo "❌ 請提供 commit 訊息，例如："
  echo "   ./publish.sh \"Add solution for problem 421\""
  exit 1
fi

step() { echo -e "\n\033[1;36m▶ $1\033[0m"; }
ok()   { echo -e "\033[1;32m✓ $1\033[0m"; }
fail() { echo -e "\033[1;31m✗ $1\033[0m"; exit 1; }

if [ ! -f "tools/generate_site.py" ]; then
  fail "找不到 generate_site.py，請在 repo 根目錄執行這個腳本"
fi

if [ -z "${VIRTUAL_ENV:-}" ]; then
  echo "⚠️  偵測到虛擬環境未啟動，嘗試自動啟動 ../venv ..."
  if [ -f "../venv/bin/activate" ]; then
    source ../venv/bin/activate
    ok "已啟動虛擬環境"
  else
    fail "找不到虛擬環境，請自行 source venv/bin/activate 後再試一次"
  fi
fi

step "重新產生網站 (generate_site.py)"
python3 tools/generate_site.py metadata notes solution docs
ok "網站頁面已更新"

step "Git add + commit"
git add .
if git diff --cached --quiet; then
  echo "（沒有偵測到變更，跳過 commit）"
else
  git commit -m "$COMMIT_MSG"
  ok "已 commit：$COMMIT_MSG"
fi

step "Push 到 origin/main"
if git push origin main; then
  ok "已推送到 GitHub"
else
  fail "push 失敗，請檢查是否需要先 git pull，或 token 是否過期"
fi

step "部署到 GitHub Pages (mkdocs gh-deploy)"
if mkdocs gh-deploy; then
  ok "部署完成！"
else
  fail "部署失敗，請檢查上方錯誤訊息（常見原因：token 過期）"
fi

echo -e "\n\033[1;32m🎉 全部完成！網站：https://smartcsie.github.io/leetcode/\033[0m"
