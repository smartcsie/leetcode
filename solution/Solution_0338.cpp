/**
 * 題目：338. Counting Bits (位元位元計數)
 * 難度：簡單 (Easy)
 * 描述：給定一個整數 n，對於範圍 [0, n] 中的每個數字 i，計算其二進位表示中 1 的個數。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * (動態規劃 + 位元操作)：
 * 1. 狀態轉移方程：`res[i] = res[i & (i - 1)] + 1`
 * - `i & (i - 1)` 的運算會消除數字 `i` 二進位表示中最右邊的一個 1。
 * - 因此，數字 `i` 的 1 的個數，就等於「去掉最右邊 1 之後的數字」的 1 的個數再加 1。
 * 2. 邊界條件：`res[0] = 0` (0 的二進位中沒有 1)。
 */

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counts(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            counts[i] = counts[i & (i - 1)] + 1;
        }
        return counts;
    }
};
