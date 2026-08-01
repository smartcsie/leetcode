/**
 * 題目：1995. Count Special Quadruplets (統計特殊四元組)
 * 難度：簡單 (Easy)
 * 描述：給定整數陣列 nums，統計滿足 0 <= a < b < c < d < n 且
 *       nums[a] + nums[b] + nums[c] == nums[d] 的四元組 (a, b, c, d) 數量。
 *
 * 時間複雜度：O(N⁴) - 四層巢狀迴圈窮舉所有滿足 a < b < c < d 的索引組合。
 * 空間複雜度：O(1) - 只使用常數個變數（ans, a, b, c, d），不需額外配置記憶體。
 *
 * 解法思路：
 * 1. 暴力窮舉所有合法索引組合 (Brute Force Enumeration)：
 *    - 由於題目資料規模通常很小（陣列長度上限較低），直接用四層巢狀迴圈
 *      窮舉所有滿足 a < b < c < d 的索引組合即可，不需要額外的優化技巧
 *      （例如雜湊表加速）。
 * 2. 逐一驗證等式是否成立：
 *    - 對每組 (a, b, c, d)，檢查 nums[a] + nums[b] + nums[c] 是否恰好等於 nums[d]。
 * 3. 累加符合條件的組合數：
 *    - 只要等式成立，就將計數 ans 加一，最終回傳總數。
 */
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int a = 0; a < n; a++) {
            for(int b =  a + 1; b < n; b++) {
                for(int c = b + 1; c < n; c++) {
                    for(int d = c + 1; d < n; d++) {
                        if((nums[a] + nums[b] + nums[c]) == nums[d]) ans++;
                    }
                }
            }
        }
        return ans;
    }
};
