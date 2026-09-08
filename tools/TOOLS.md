# Tools 使用指南

## 工具清單與作用

### 🔄 資料同步 / 產生類

| 工具 | 作用 |
|---|---|
| `fetch_leetcode_ac.py` | 從 LeetCode GraphQL API 分頁抓取完整 AC 清單，寫入 `leetcode_ac_cache.json` |
| `generate_site.py` | 產生 MkDocs 網站所需的 md 檔案 |
| `save_server.py` | 儲存本地開發伺服器狀態 |

### 🔍 檢查類

| 工具 | 作用 |
|---|---|
| `check.py` | 綜合檢查 metadata 格式完整性 |
| `check_comments.py` | 檢查 cpp `/**` 開頭註解及複雜度格式是否正確 |
| `check_topic_classification.py` | 檢查 topics 是否有分類問題，標記可疑題目 |

### 🕵️ 分析 / 列表類

| 工具 | 作用 |
|---|---|
| `find_ac_gap.py` | 找 LeetCode AC 但本地 metadata 沒有的題目 |
| `find_gap.py` | 找特定分類下缺少的題目 |
| `backtracking_gap.py` | 找 Backtracking 分類缺題 |
| `dp_pattern_gap.py` | 找 DP 分類缺題 |
| `greedy_pattern_gap.py` | 找 Greedy 分類缺題 |
| `find_array_subtopic_candidates.py` | 找 Array 類可細分子分類的題目 |
| `find_redundant_array_tag.py` | 找有重複 Array 標籤的題目 |
| `find_multi_topic_tags.py` | 找有多個 topic 標籤的題目 |
| `find_reset_pattern_fixed.py` | 嚴格搜尋 `if > mx / else if == mx` 模式的 cpp |
| `find_reset_pattern_loose.py` | 寬鬆搜尋相同模式的 cpp |
| `list_binary_search_topics.py` | 列出 Binary Search 所有子分類題目 |
| `list_dp_topics.py` | 列出 DP 所有子分類題目 |
| `list_greedy_topics.py` | 列出 Greedy 所有子分類題目 |
| `list_sorting_topics.py` | 列出 Sorting 所有子分類題目 |
| `list_uncategorized.py` | 列出尚未分類的題目 |
| `topic_coverage.py` | 統計各分類的題目覆蓋率 |
| `suggest_by_tag.py` | 根據標籤推薦下一題 |

### 🔧 修正類

| 工具 | 作用 |
|---|---|
| `fix_complexity.py` | 移除 cpp 複雜度後面的描述文字，只保留 `O(...)` |
| `fix_pending_complexity.py` | 修正 cpp 裡「待補充」的複雜度 |
| `fix_missing_complexity.py` | 為有 `/**` 但缺少複雜度欄位的 cpp 插入複雜度 |
| `fix_metadata_complexity.py` | 修正 yml metadata 裡的複雜度格式 |
| `fix_missing_urls.py` | 補齊 yml 裡缺少的 LeetCode URL |
| `fix_difficulty_and_tags.py` | 修正 yml 裡的難度和標籤 |
| `fix_topic_classification.py` | 修正核心邏輯放錯分類的 yml |
| `fix_note_links.py` | 修正 md 筆記裡的連結 |
| `insert_missing_comments.py` | 為缺少 `/**` 的 cpp 插入完整開頭註解 |

### 🔀 搬移 / 重新命名類

| 工具 | 作用 |
|---|---|
| `move_binary_search_topics.py` | 將 Binary Search 題目搬移到正確子分類 |
| `move_dp_topics.py` | 將 DP 題目搬移到正確子分類 |
| `move_greedy_topics.py` | 將 Greedy 題目搬移到正確子分類 |
| `move_sorting_topics.py` | 將 Sorting 題目搬移到正確子分類 |
| `rename_dp_topics.py` | 批次重命名 DP 子分類名稱 |
| `rename_topic.py` | 重命名單一 topic 名稱 |
| `rename_zhuyi_to_zailianxi.py` | 將熟悉度「注意」改名為「再練習」 |

### 🩹 Patch 類（一次性修補）

| 工具 | 作用 |
|---|---|
| `patch_review_stats_feature.py` | 補上複習統計功能所需的欄位 |
| `patch_topic_split_familiarity.py` | 補上 topic 拆分後的熟悉度欄位 |

### 📤 抓取 / 輸出類（輔助 Claude）

| 工具 | 作用 |
|---|---|
| `dump_missing_comments.py` | 輸出缺少 `/**` 的 cpp 內容 → 貼給 Claude 補註解 |
| `dump_flagged_solutions.py` | 輸出分類有問題的 cpp 內容 → 貼給 Claude 分析 |

### 🗑️ 清理類

| 工具 | 作用 |
|---|---|
| `cleanup_obsolete_tools.py` | 清理過時不再使用的工具 |

---

## 建議使用順序

### 【日常維護】

```bash
python3 tools/fetch_leetcode_ac.py           # 同步 AC 清單
python3 tools/find_ac_gap.py                 # 找本地缺少的題目
python3 tools/check.py                       # 綜合格式檢查
python3 tools/check_comments.py             # 檢查 cpp 註解
python3 tools/check_topic_classification.py # 檢查分類問題
```

### 【修正問題】

```bash
python3 tools/fix_complexity.py             # 清理複雜度描述
python3 tools/fix_pending_complexity.py     # 補「待補充」複雜度
python3 tools/fix_missing_complexity.py     # 補缺少的複雜度欄位
python3 tools/fix_metadata_complexity.py    # 修正 yml 複雜度
python3 tools/fix_missing_urls.py           # 補缺少的 URL
python3 tools/fix_difficulty_and_tags.py    # 修正難度和標籤
python3 tools/fix_topic_classification.py   # 修正分類錯誤
python3 tools/fix_note_links.py             # 修正筆記連結
```

### 【補充缺少內容】

```bash
# 補 cpp 開頭註解
python3 tools/dump_missing_comments.py > missing_dump.txt
# → 貼給 Claude → 取得 insert_missing_comments.py → 執行
python3 tools/insert_missing_comments.py

# 修正分類問題
python3 tools/dump_flagged_solutions.py > flagged_dump.txt
# → 貼給 Claude → 取得 fix_topic_classification.py → 執行
python3 tools/fix_topic_classification.py
```

### 【搬移 / 重新命名】

```bash
python3 tools/move_binary_search_topics.py
python3 tools/move_dp_topics.py
python3 tools/move_greedy_topics.py
python3 tools/move_sorting_topics.py
python3 tools/rename_topic.py
python3 tools/rename_dp_topics.py
```

### 【定期分析】

```bash
python3 tools/topic_coverage.py                    # 分類覆蓋率統計
python3 tools/list_uncategorized.py                # 未分類題目
python3 tools/suggest_by_tag.py                    # 推薦下一題
python3 tools/find_gap.py                          # 各分類缺題
python3 tools/backtracking_gap.py
python3 tools/dp_pattern_gap.py
python3 tools/greedy_pattern_gap.py
python3 tools/find_array_subtopic_candidates.py    # Array 可細分題目
python3 tools/find_redundant_array_tag.py
python3 tools/find_multi_topic_tags.py
python3 tools/list_binary_search_topics.py
python3 tools/list_dp_topics.py
python3 tools/list_greedy_topics.py
python3 tools/list_sorting_topics.py
```

### 【產生網站】

```bash
python3 tools/generate_site.py
```

### 【清理】

```bash
python3 tools/cleanup_obsolete_tools.py
```
