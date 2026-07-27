/**
 * 題目：414. Third Maximum Number (第三大的數)
 * 難度：簡單 (Easy)
 * 描述：找出陣列中第三大的數，若不存在則回傳最大數。
 * * 時間複雜度：O(N) - 遍歷一次陣列。
 * 空間複雜度：O(1) - 使用三個變數存儲最大值。
 * * 優化思路：
 * 1. 邊界處理：使用 long 型別大於 int 範圍，以區分未初始化狀態。
 * 2. 重複值：透過 `num == first` 等判斷過濾重複數字，確保嚴格的數值比較。
 */

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;
        for(const int& num: nums){
            if(num > first) {
                third = second;
                second = first;
                first = num;
            } else if(num < first && num > second) {
                third = second;
                 second = num;
            } else if(num < second && num > third) {
                third = num;
            }
        }
        return third == LONG_MIN ? static_cast<int>(first) : static_cast<int>(third);
    }
};
