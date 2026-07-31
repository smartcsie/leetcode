# uncategorized

| # | 題目 | 難度 | 標籤 | 時間 | 空間 |
| --- | --- | --- | --- | --- | --- |
| 532 | [K-diff Pairs in an Array](../problems/0532.md) | 待補充 |  | O(N log N) - 排序後雙指針或二分搜尋。 | O(N) - 排序空間 O(log N)，set O(N)。 |
| 1022 | [Sum of Root To Leaf Binary Numbers](../problems/1022.md) | 簡單 (Easy) |  | O(N) - 每個節點都會被走訪恰好一次，其中 n 為樹中節點的總數。 | O(H) - 遞迴呼叫堆疊（Call Stack）的深度取決於樹的高度 h。在最壞情況（斜樹）下為 O(N)，在平衡樹下為 O(log N)。 |
| 1422 | [Maximum Score After Splitting a String](../problems/1422.md) | 簡單 (Easy) |  | O(N) - 先使用 std::count 花費 O(N) 計算總 1 數量，接著用單一迴圈花費 O(N) 掃描分割點。 | O(1) - 僅使用常數個變數（zeros, ones, ans）來追蹤狀態，不需額外配置動態記憶體。 |
| 1567 | [Maximum Length of Subarray With Positive Product](../problems/1567.md) | 中等 (Medium) |  | O(N) - 僅需對 nums 陣列進行一次從頭到尾的線性掃描，每個元素的狀態轉移皆為常數時間。 | O(1) - 僅使用常數個變數（ans, pos, neg）來動態追蹤狀態，不需額外配置記憶體。 |
| 1593 | [Split a String Into the Max Number of Unique Substrings](../problems/1593.md) | 中等 (Medium) |  | O(N * 2^(N-1)) - 在最壞情況下，字串有 n-1 個可分割的間隙，總共有 2^(n-1) 種分割組合，每次分割與子字串截取需花費 O(N) 時間。 | O(N) - 遞迴呼叫堆疊的深度最多為 n，且雜湊表 `seen` 在任一時刻最多儲存 n 個子字串。 |
| 1738 | [Find Kth Largest XOR Coordinate Value](../problems/1738.md) | 中等 (Medium) |  | O(M * N) - 雙層迴圈遍歷矩陣計算 2D 前綴 XOR 需要 O(M * N)；使用 std::nth_element 尋找第 k 大元素的平均時間為 O(M * N)。 | O(M * N) - 需要額外的 prefix 矩陣（大小 (M+1) x (N+1)）與儲存所有 XOR 值的 xorVal 陣列。 |
| 1953 | [1952. Three Divisors](../problems/1953.md) | 簡單 (Easy) |  | O(sqrt(sqrt(N))) 或 O(sqrt(N)) 取決於實現。 | O(1)。 |
| 2044 | [Count Number of Maximum Bitwise-OR Subsets](../problems/2044.md) | 中等 (Medium) |  | O(2^N) - 遍歷所有子集。 | O(N) - 遞迴堆疊深度。 |
| 2176 | [Count Equal and Divisible Pairs in an Array](../problems/2176.md) | 簡單 (Easy) |  | O(N^2) - 使用雙重迴圈遍歷所有可能的索引對 (i, j)，在資料規模較小（通常 N <= 100）時能高效執行。 | O(1) - 僅使用常數個變數來記錄計數與迴圈索引，不需額外配置動態記憶體。 |
| 2210 | [Count Hills and Valleys in an Array](../problems/2210.md) | 簡單 (Easy) |  | O(N) - 僅需對 nums 陣列進行一次從頭到尾的線性掃描，每個元素的判斷為常數時間。 | O(1) - 僅使用常數個變數（ans, prev, 迴圈變數）來追蹤狀態，不需額外配置記憶體。 |
| 2454 | [2425. Bitwise XOR of All Pairings](../problems/2454.md) | 中等 (Medium) |  | O(N + M)，遍歷兩個陣列各一次。 | O(1)。 |
| 2570 | [Merge Two 2D Arrays by Summing Values](../problems/2570.md) | 簡單 (Easy) |  | O(N + M) - 由於兩個輸入陣列皆已排序，利用雙指標（Two Pointers）線性掃描一次即可完成，耗時與兩陣列長度總和成正比。 | O(1) - 僅使用常數個指標與變數（i, j, m, n），並透過 `ans.reserve(m + n)` 預先分配記憶體，避免動態擴容開銷。 |
| 2656 | [Maximum Sum With Exactly K Elements](../problems/2656.md) | 簡單 (Easy) |  | O(N) - 只需要遍歷一次 `nums` 陣列來尋找最大值，其中 n 為陣列長度。 | O(1) - 僅使用常數個變數來儲存最大值與計算結果，不需額外配置動態記憶體。 |
| 2974 | [Minimum Number Game](../problems/2974.md) | 簡單 (Easy) |  | O(N) - 計算所有元素和，生成交替奇偶數列。 | O(N) - 結果陣列大小為 N。 |
| 3514 | [Number of Unique XOR Triplets II](../problems/3514.md) | 困難 (Hard) |  | O(M log M) - M 為大於等於陣列最大元素的最小 2 的冪次，FWHT 的三層迴圈總共執行 M log M 次操作。 | O(M) - 需要配置大小為 V (即 M) 的多項式陣列來儲存頻率與進行頻域轉換。 |
| 3754 | [Concatenate Non-Zero Digits and Multiply by Sum I](../problems/3754.md) | 簡單 (Easy) |  | O(N) - 單次遍歷，根據數字奇偶性計算交替和。 | O(1) - 僅使用常數空間。 |
