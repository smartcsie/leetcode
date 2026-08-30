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
        for(int i = 1; i * i <= n; i++) 
            if(n % i == 0 && --k == 0) return i;
        for(int i = static_cast<int>(sqrt(n)); i >= 1 ; i--) 
            if(n % i == 0 && i * i != n && --k == 0) return n / i;
        return -1;
    }
};
