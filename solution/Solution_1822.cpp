/**
 * 題目：1822. Sign of the Product of an Array (陣列乘積的符號)
 * 難度：簡單 (Easy)
 * 描述：判斷陣列所有元素乘積的符號（1, -1, 0）。
 * * 時間複雜度：O(N) - 遍歷一次陣列。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 1. 若出現 0，結果必為 0。
 * 2. 乘積的符號僅取決於負數的個數：負數個數為偶數則為正，奇數則為負。
 */

class Solution {
public:
    int arraySign(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int sign = 1;
        for(const int& num : nums) {
            if(num == 0) return 0;
            else if(num < 0) sign = -sign;
        }
        return sign;
    }
};
