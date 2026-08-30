/**
 * 題目：29. Divide Two Integers
 * 難度：中等 (Medium)
 * 分類主題：bit-manipulation
 * 技巧：位元左移取代乘法
 * 描述：不能用乘法、除法、取餘數運算子，求兩數相除的商（結果無條件
 * 捨去小數部分），如果超出 32 位元整數範圍就回傳邊界值。
 *
 * 時間複雜度：O(log²N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （倍增減法，用 long 當緩衝避開 INT_MIN 取絕對值溢位的問題，核心
 * 邏輯比純 int 版直觀，但要注意：LeetCode 會靜態檢查程式碼裡有沒有
 * `*`、`/`、`%` 這些被禁止的運算子，寫的時候要全程改用位元運算）：
 * 1. 特例先處理：`dividend == INT_MIN && divisor == -1`，這是唯一
 *    真正會讓結果超出 int 範圍的情況，直接回傳 INT_MAX。
 * 2. 記錄最終答案的正負號，把 dividend、divisor 都用 `labs()` 轉成
 *    非負數（用 long 存，避免 INT_MIN 取絕對值時超出 int 範圍）。
 * 3. **核心減法邏輯（倍增法）**：每一輪先假設要減一次完整的 divisor
 *    （k=1，doubling=dvs），只要「doubling 左移一位（等於乘以 2）」
 *    還不超過 dvd，就持續左移，同時 k 也跟著左移——這個迴圈結束時，
 *    doubling 會是「不超過 dvd、divisor 的最大 2 的冪次倍數」，k 是
 *    對應的倍數。
 * 4. 把這一大塊 doubling 從 dvd 扣掉，k 累加進 ans，回到外層迴圈繼續
 *    處理剩下的 dvd，直到 dvd 小於 dvs 為止。
 * 5. **踩過的坑**：一開始寫 `k * 2 * dvs <= dvd` 和 `k *= 2` 用了
 *    乘法運算子，被 LeetCode 判定「Use of multiplication operator
 *    '*' is prohibited」直接擋下來；最後 `return sign * ans` 也犯
 *    同樣的錯。修正方式是把所有 `*2` 改成 `<<1`（左移一位等於乘以
 *    2），最後的正負號判斷改用三元運算子（`sign < 0 ? -ans : ans`）
 *    取代乘法。
 * 6. 這題的檢查機制提醒了一件事：解法邏輯正確不代表能通過判題，
 *    有些題目會限制「不能用哪些運算子/函式」，這種限制通常會用
 *    靜態程式碼檢查（不是跑測資才發現），寫的時候要留意題目敘述裡
 *    明確禁止的操作，全部避開才行。
 */

if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        const int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        long ans = 0;
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        while (dvd >= dvs) {
            long k = 1;
            long doubling = dvs;
            while ((doubling << 1) <= dvd) {
                doubling <<= 1;
                k <<= 1;
            }
            dvd -= doubling;
            ans += k;
        }
        return sign < 0 ? -ans : ans;