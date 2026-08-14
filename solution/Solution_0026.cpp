/**
 * 題目：26. Remove Duplicates from Sorted Array (刪除有序陣列中的重複項)
 * 難度：簡單 (Easy)
 * 描述：給你一個非遞減排序的陣列 nums ，請你原地刪除重複出現的元素，使每個元素只出現一次。
 * 返回刪除後陣列的新長度。
 *
 * 時間複雜度：O(N) - 只需要遍歷一次陣列。
 * 空間複雜度：O(1) - 直接在原陣列上修改，僅使用常數個額外空間。
 *
 * 解法思路：
 * 1. 由於陣列已經排序，重複的元素一定會相鄰。
 * 2. 使用 `count` 作為慢指標，紀錄下一個不重複元素應該存放的位置。
 * 3. 使用 `i` 作為快指標，從第二個元素開始遍歷：
 * - 如果 `nums[i]` 與前一個元素 `nums[i-1]` 不同，代表發現了新的唯一元素。
 * - 將該元素移至 `nums[count]`，隨後 `count` 加 1。
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
