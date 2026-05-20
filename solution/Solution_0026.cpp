/**
 * 題目：26. Remove Duplicates from Sorted Array (刪除有序陣列中的重複項)
 * 難度：簡單 (Easy)
 * 描述：給你一個非遞減排序的陣列 nums ，請你原地刪除重複出現的元素，使每個元素只出現一次。
 *      返回刪除後陣列的新長度。
 * 
 * 時間複雜度：O(n) - 只需要遍歷一次陣列。
 * 空間複雜度：O(1) - 直接在原陣列上修改，僅使用常數個額外空間。
 * 
 * 解法思路：
 * 1. 由於陣列已經排序，重複的元素一定會相鄰。
 * 2. 使用 `count` 作為慢指標，紀錄下一個不重複元素應該存放的位置。
 * 3. 使用 `i` 作為快指標，從第二個元素開始遍歷：
 *    - 如果 `nums[i]` 與前一個元素 `nums[i-1]` 不同，代表發現了新的唯一元素。
 *    - 將該元素移至 `nums[count]`，隨後 `count` 加 1。
 */


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 1. 處理空陣列的邊界情況
        if (nums.empty()) return 0;
        // 2. count 是慢指標，第一個元素永遠不需要移動，所以從 1 開始
        int count = 1;
        // 3. i 是快指標，掃描陣列寻找不重複的數字
        for (int i = 1; i < nums.size(); i++) {
            // 如果當前數字跟前一個數字不同，說明這是一個新的不重複數字
            if (nums[i] != nums[i - 1]) {
                nums[count] = nums[i];
                count++;
            }
        }
        // 返回不重複元素的總個數
        return count;
    }
};
