/**
 * 題目：80. Remove Duplicates from Sorted Array II (刪除有序陣列中的重複項 II)
 * 難度：中等 (Medium)
 * 描述：給你一個有序陣列 nums ，請你原地刪除重複出現的元素，使得出現次數超過兩次的元素只出現兩次。
 *      返回刪除後陣列的新長度。
 * 
 * 時間複雜度：O(n) - 只需要遍歷一次陣列。
 * 空間複雜度：O(1) - 原地修改，不需要額外空間。
 * 
 * 解法思路：
 * 1. 使用變數 `count` (慢指標) 紀錄下一個有效元素該存放的位置。
 * 2. 使用 `i` (快指標) 遍歷整個陣列。
 * 3. 核心判定條件：
 *    - 如果 `count < 2`，代表目前的結果陣列長度不足 2，任何元素都可以直接放入。
 *    - 如果 `nums[i] > nums[count - 2]`，代表當前元素與結果陣列中「倒數第二個」元素不同。
 *      由於陣列是有序的，這保證了同一個數字最多只會被存入兩次。
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0; // 慢指標：指向下一個待寫入的位置
        // i 是快指標：走在前面掃描原始數據
        for (int i = 0; i < nums.size(); i++) {
            // 關鍵邏輯：
            // 只要 count 還沒到 2，或者當前數字比「結果區域」倒數第二個數字大
            // 就代表這個數字可以被保留
            if (count < 2 || nums[i] > nums[count - 2]) {
                nums[count] = nums[i];
                count++;
            }
        }
        // 返回有效區域的長度
        return count;
    }
};
