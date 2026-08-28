/**
 * 題目：待補充
 * 難度：待補充
 * 描述：待補充
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 快慢指標法 (Fast-slow Pointers)
 * 1. 我們需要「原地」移除所有數值等於 val 的元素。
 * 2. 定義兩個指標：
 * - fast (快指標)：遍歷整個陣列，尋找「不等於 val」的合法元素。
 * - slow (慢指標)：指向下一個「合法元素」應該存放的位置。
 * 3. 當 fast 指向的元素不等於 val 時：
 * - 將該元素複製到 slow 的位置。
 * - slow 向後移動一格。
 * 4. 最後 slow 的數值即為移除後新陣列的長度。
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for(int fast = 0; fast < nums.size(); fast++) {
            if(nums[fast] != val) swap(nums[fast], nums[slow++]);
        }
        return slow;
    }
};
