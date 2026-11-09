/**
 * 題目：1492. The kth Factor of n (n 的第 k 個因數)
 * 難度：中等 (Medium)
 * 描述：回傳 n 的第 k 個因數，若不存在則回傳 -1。
 *
 * 時間複雜度：O(sqrt(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 因數成對性：若 i 是因數，則 n/i 也是因數。
 * 2. 分段搜尋：先找完前半段的因數，再回頭找後半段的因數。
 */

class Solution {
public:
    int kthFactor(int n, int k) {
        for(int x = 1; x * x <= n; x++) {
            if(n % x == 0 && --k == 0) return x;
        }
        for(int x = static_cast<int>(sqrt(n)); x >= 1; x--) {
            if(n % x == 0 && x * x != n && --k == 0) return n / x;
        }
        return -1;
    }
};