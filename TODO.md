# LeetCode MkDocs 專案 — 進度摘要 & To-do 清單

最後更新：2026-08-02

## 專案概況

- **Live 網站**：https://smartcsie.github.io/leetcode/
- **GitHub Repo**：https://github.com/smartcsie/leetcode（public，GitHub Free 方案，不能設成 private，否則 Pages 會停止運作）
- **本機環境**：WSL Ubuntu，repo 位於 `~/leetcode-docs/repo`，venv 位於 `~/leetcode-docs/venv`
- **架構**：`metadata/<NNNN>.yml`（結構化資訊，含 note）→ `generate_site.py` → `docs/problems/*.md` + `docs/topics/*.md` + `docs/review.md` → mkdocs 建置 → gh-deploy

## 核心工具鏈

| 工具 | 用途 |
|---|---|
| `tools/generate_site.py` | 讀 metadata + solution，產生整個 docs/ 網站內容 |
| `tools/save_server.py` | 本機伺服器，提供 solution-generator.html，處理存檔/發佈/載入既有題目，**含啟用碼驗證** |
| `solution-generator.html` | 網頁表單工具，貼上 AI 回覆自動解析、存檔、發佈、載入既有題目編輯 |
| `publish.sh` | generate_site.py + git commit/push + mkdocs gh-deploy 一條龍 |
| `activation_code.txt` | **不會被 git 追蹤**，存放本機啟用碼，每台電腦都要各自建立 |
| `tools/fetch_leetcode_ac.py` | 抓 LeetCode 網站帳號 AC 總數，寫進 `leetcode_ac_cache.json`，供複習清單頁面顯示 |
| `leetcode_cookie.txt` | **不會被 git 追蹤**，存放 LeetCode 登入 Cookie，每台電腦都要各自建立 |
| `leetcode_ac_cache.json` | `fetch_leetcode_ac.py` 產生的快取（AC 總數/總題數/抓取時間），`generate_site.py` 讀取後寫進 `docs/review.md` |

## 資料結構（metadata schema）

```yaml
number: 137
title: Single Number II
url: https://leetcode.com/problems/single-number-ii/
solutions:
- file: Solution_0137.cpp        # 支援 .cpp / .sql / .js（LANG_MAP 已擴充）
  difficulty: 🟡 Medium
  tags: [Bit Manipulation]
  topics: [bit-manipulation]      # 決定分類頁歸屬
  time: O(N)                      # 複雜度已統一移除空格，例如 O(NlogN)
  space: O(1)
  familiarity: 生疏                # 生疏 | 熟練，目前全部 859 題已設為「生疏」
  note: "選填，顯示在程式碼旁邊"
  is_best: true                   # 選填，標記最佳解，顯示 🏆 徽章
  related: [136, 260]             # 選填，相關題目連結
```

## 已完成的重大工作

1. ✅ 從單一 README 遷移到 mkdocs Material 多頁架構
2. ✅ 35 題舊資料缺檔問題全部修復（含 7 題真的遺失的 .cpp，已找回並驗證）
3. ✅ 熟悉度標記 + 複習清單功能
4. ✅ 一題多解法功能（存檔合併邏輯、載入既有題目、依複雜度自動排序、最佳解徽章、相關題目連結）
5. ✅ 34 個 .cpp 註解換行 bug 修復
6. ✅ 筆記系統從獨立 `notes/` 資料夾整合進 metadata 的 `note` 欄位（202 筆搬移完成，內容原封不動）
7. ✅ LeetCode AC 落差比對完成（859/859 全部同步，過程中額外修正 2 個真正的程式邏輯 bug：747、1784）
8. ✅ 分類重整：`prime`→`math-prime`、新增 `design`、`math-game-theory`、`math-geometry` 三個分類，共搬移 12 題
9. ✅ 分類頁 + 複習清單表格改版（題目連結指向 LeetCode 原題、新增「解法檔案」欄位連到站內頁面）
10. ✅ 修復表格分隔線欄位數不符導致渲染失敗的 bug
11. ✅ 支援 `.js`（JavaScript）、182 題訂正為 `.sql`
12. ✅ 全部 859 題熟悉度重置為「生疏」
13. ✅ `save_server.py` 加上啟用碼驗證機制，密碼獨立存放（`activation_code.txt`），不進 git，可安全跨裝置使用
14. ✅ 複習清單頁面（`docs/review.md`）最上方加入總覽：LeetCode 網站 AC 總數（`fetch_leetcode_ac.py` + `leetcode_ac_cache.json`）、目前收錄總題目數與生疏/熟練/未標記各幾題、各分類生疏/熟練統計表格（已提供 `patch_review_stats_feature.py`，套用到 `generate_site.py` 後即可使用）

## 待辦清單

### 1. 筆記格式整理（部分完成）
- 3827 那筆自我連結、`>` 引用格式的舊筆記，還沒清理
- 0217、0476、2605、3370 這幾題（多解法題目）的壞連結已修好
- 其他約 200 筆搬移過來的舊筆記，格式沒有整理過，要不要逐一檢查還沒決定

### 2. 存檔提醒功能加強
- 目前存檔成功/失敗的視覺提示需要加強（Toast 通知時間加長、更明顯）

### 3. 爬蟲比對最佳解
- 完全還沒開始討論設計方向

### 4. 補齊多解法題目的遺失變體
從舊版 README 比對出來，這幾題原本有多種解法，但新架構裡缺少部分變體：
- **217 Contains Duplicate**：缺 3 個解法（Hashset 去重 / Unique 去重 / 排序法），目前只剩 1/4
- **648 Replace Words**：缺 1 個解法（String 分類引用的版本）
- **2605 Form Smallest Number From Two Digit Arrays**：缺 3 個解法（雙迴圈暴力法 / bitset / unordered_map），目前只剩 1/4

處理方式：需要使用者提供舊檔案備份，或請 Claude 依照舊 README 的邏輯描述重新寫出（會編譯測試過才交付）。

## 重要注意事項 / 已知風險

- **repo 必須維持 public**：GitHub Free 方案的 Pages 只支援 public repo，設成 private 會讓網站停止運作
- **`activation_code.txt` 每台電腦都要各自建立**：不會透過 git 同步，家裡/公司需要各自手動建立、內容需一致
- **`leetcode_cookie.txt` 每台電腦都要各自建立**：同樣不會透過 git 同步；LeetCode 的 Cookie 有效期有限，AC 總數顯示過期或抓不到時，重新登入 leetcode.com 複製新 Cookie 貼進去即可
- **`快速導覽.md`、`README.md`（舊版）** 裡有一些過時的錨點連結警告，不影響功能，長期可考慮清理或直接刪除舊 README
- Git remote 使用 token 認證方式（`https://TOKEN@github.com/...`），token 已在對話早期意外曝光過一次，使用者已申請新 token 並更新（新 token 未曾貼給 Claude，安全）

## 常用指令速查

```bash
# 啟動本機工具
cd ~/leetcode-docs/repo
source ../venv/bin/activate   # 如果還沒啟動
python3 tools/save_server.py 8090
# 瀏覽器開 http://localhost:8090/solution-generator.html

# 更新 LeetCode AC 總數快取（複習清單頁面用，非必要每次都跑）
python3 tools/fetch_leetcode_ac.py

# 手動重新產生網站（不發佈）
python3 tools/generate_site.py metadata solution docs

# 完整發佈流程
./publish.sh "commit 訊息"
```
