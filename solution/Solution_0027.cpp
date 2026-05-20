/**
 * 解題思路：快慢指標法 (Fast-slow Pointers)
 * 1. 我們需要「原地」移除所有數值等於 val 的元素。
 * 2. 定義兩個指標：
 *    - fast (快指標)：遍歷整個陣列，尋找「不等於 val」的合法元素。
 *    - slow (慢指標)：指向下一個「合法元素」應該存放的位置。
 * 3. 當 fast 指向的元素不等於 val 時：
 *    - 將該元素複製到 slow 的位置。
 *    - slow 向後移動一格。
 * 4. 最後 slow 的數值即為移除後新陣列的長度。
 * 
 * Time Complexity: O(n) - 只需要遍歷陣列一次。
 * Space Complexity: O(1) - 原地修改，僅使用兩個額外的整數指標。
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        
        for (int fast = 0; fast < nums.size(); fast++) {
            // 如果當前數字不是要移除的目標
            if (nums[fast] != val) {
                // 將合法數字搬到前方 slow 的位置
                nums[slow] = nums[fast];
                // 慢指標前進
                slow++;
            }
            // 如果 nums[fast] == val，slow 不動，fast 繼續走，
            // 相當於跳過了這個需要被移除的元素。
        }
        
        // slow 剛好等於新陣列的元素個數
        return slow;
    }
};
