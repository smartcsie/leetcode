/**
 * 題目：3718. Smallest Missing Multiple of K (K 的最小缺失倍數)
 * 難度：簡單 (Easy)
 * 描述：在陣列 nums 中找出第一個未出現過的 K 的倍數。
 *
 * 時間複雜度：O(N+M)
 * 空間複雜度：O(M)
 *
 * 解法思路：
 * 1. 邊界控制：使用 vector<bool> 替代固定大小陣列，增加程式擴充性。
 * 2. 邏輯優化：直接計算倍數，避免遍歷所有數字。
 */

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bitset<101> seen;
        for(const int& x : nums) seen.set(x);
        int m;
        for(m = k; m <= 100 && seen.test(m); m += k ) {}
        return m;
    }
};
