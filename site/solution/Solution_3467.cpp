/**
 * 題目：3467. Transform Array by Parity
 * 難度：簡單 (Easy)
 * 描述：將數組中的偶數排在前面，奇數排在後面，並將最終數字轉為奇偶標記（0 為偶，1 為奇）。
 * * 時間複雜度：O(N) - N 為陣列長度，每個元素最多被訪問常數次。
 * 空間複雜度：O(1) - 原地修改陣列，不使用額外空間。
 * * 解法思路：
 * 1. 使用雙指標 `left` 從左向右掃描，`right` 從右向左掃描。
 * 2. `left` 尋找奇數，`right` 尋找偶數，找到後進行交換 (swap)。
 * 3. 完成排序後，再次遍歷陣列，使用位元運算 `num &= 1` 將奇偶轉為 0 或 1。
 */

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left < right) {
            while(left < right && ((nums[left] & 1) == 0)) left++;
            while(left < right && ((nums[right] & 1) == 1)) right--;
            if(left < right) swap(nums[left++], nums[right--]);
        }
        for(int& num : nums) {
            num &= 1;
        }
        return nums;
    }
};
