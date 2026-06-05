/**
 * 題目：1480. Running Sum of 1d Array (一維陣列的動態總和)
 * 難度：簡單 (Easy)
 * 描述：計算陣列的累加總和，nums[i] = nums[0] + ... + nums[i]。
 * * 時間複雜度：O(N) - 遍歷陣列一次。
 * 空間複雜度：O(1) - 原地修改陣列，不使用額外空間。
 * * 設計思路：
 * 每個位置的累加值等於「當前值」加上「前一個位置的累加值」。
 */

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // 從第二個元素開始累加，每一個元素都變為當前位置的總和
        for (size_t i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};
