/**
 * 題目：3982. Sum of Integers with Maximum Digit Range
 * 難度：簡單 (Easy)
 * 描述：計算陣列中擁有「最大數位極差」的所有整數之和。
 * 優化重點：
 * 1. 數位拆解：使用 while 迴圈配合取模運算。
 * 2. 邊界條件：使用 INT_MAX 與 INT_MIN 初始化比較基準。
 *
 * 時間複雜度：O(N*D)
 * 空間複雜度：O(N)
 */

class Solution {
public:
    int maxDigitRange(std::vector<int>& nums) {
        int n = nums.size();
        int mxRange = -1;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int t = nums[i];
            int  mx = -1, mn = 10;
            while(t > 0) {
                int d = t % 10;
                mx = max(mx, d);
                mn = min(mn, d);
                t /= 10;
            }
            if(mx - mn > mxRange) {
                mxRange = mx - mn;
                ans = nums[i];
            } else if(mx - mn == mxRange) {
                ans += nums[i];
            }
        }
        return ans;
    }
};
