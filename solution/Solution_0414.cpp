/**
 * 題目：414. Third Maximum Number (第三大的數)
 * 難度：簡單 (Easy)
 * 描述：找出陣列中第三大的數，若不存在則回傳最大數。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 邊界處理：使用 long 型別大於 int 範圍，以區分未初始化狀態。
 * 2. 重複值：透過 `num == first` 等判斷過濾重複數字，確保嚴格的數值比較。
 */

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long max1 = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;
        for(const int& x : nums) {
            if(x == max1 || x == max2 || x== max3) continue;
            if(x > max1) {
                max3 = max2;
                max2 = max1;
                max1 = x;
            } else if(x > max2) {
                max3 = max2;
                max2 = x;
            } else if(x > max3) {
                max3 = x;
            }
        }
        return max3 == LONG_MIN ? max1 : max3;
    }
};
