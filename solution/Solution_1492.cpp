/**
 * 題目：1492. The kth Factor of n (n 的第 k 個因數)
 * 難度：中等 (Medium)
 * 描述：回傳 n 的第 k 個因數，若不存在則回傳 -1。
 * * 時間複雜度：O(sqrt(N)) - 僅需遍歷至 n 的平方根。
 * 空間複雜度：O(1) - 使用兩個分段遍歷策略，無需額外儲存完整因數列表。
 * * 優化思路：
 * 1. 因數成對性：若 i 是因數，則 n/i 也是因數。
 * 2. 分段搜尋：先找完前半段的因數，再回頭找後半段的因數。
 */

class Solution {
public:
    int kthFactor(int n, int k) {
        // 第一階段：遍歷 1 到 sqrt(n)，找出前段因數
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                if (--k == 0) return i;
            }
        }

        // 第二階段：回頭找後半段因數 (i * i = n 的情況需排除)
        // 為了確保從小到大順序，需從 sqrt(n) 往 1 找
        for (int i = sqrt(n); i >= 1; --i) {
            // 如果 i*i == n，這個因數已經在第一階段算過了，跳過
            if (i * i == n) continue;
            
            if (n % i == 0) {
                if (--k == 0) return n / i;
            }
        }
        
        return -1;
    }
};
