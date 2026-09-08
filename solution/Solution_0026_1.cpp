/**
 * 題目：26. Remove Duplicates from Sorted Array
 * 難度：簡單 (Easy)
 * 描述：移除排序陣列中的重複元素，回傳不重複元素的個數。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （快慢指針）：
 * fast 往前跳過重複元素，找到不同值後與 slow+1 交換，slow 記錄有效元素的末端。
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        int fast = 1;
        while(fast < n) {
            while(fast < n && nums[slow] == nums[fast]) fast++;
            if(fast < n) swap(nums[++slow], nums[fast++]);
        }
        return slow + 1;
    }
};