/**
 * 題目：2605. Form Smallest Number From Two Digit Arrays
 * 難度：簡單 (Easy)
 * 描述：從兩個陣列各取一個數字，組成最小的兩位數或一位數。
 *
 * 時間複雜度：O(N*M)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （暴力雙層迴圈）：
 * 枚舉所有 (x, y) 組合，若相等取最小公共值，否則取兩種拼接方式的最小值。
 */
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int res = 100;
        for(const int& x : nums1) {
            for(const int& y : nums2) {
                if(x == y) {
                    res = min(res, x);
                } else {
                    res = min({res, 10 * x + y, 10 * y + x});
                }
            }
        }
        return res;
    }
};