/**
 * 題目：283. Move Zeroes
 * 難度：簡單 (Easy)
 * 描述：將所有 0 移到陣列末端，保持非零元素的相對順序。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （快慢指針 swap）：
 * fast 跳過 0，找到非零元素後與 slow 交換，slow 記錄下一個放置位置。
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        int fast = 0;
        while(fast < n) {
            while(fast < n && nums[fast] == 0) fast++;
            if(fast < n) swap(nums[slow++], nums[fast++]);
        }
    }
};