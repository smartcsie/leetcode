/**
 * 題目：922. Sort Array By Parity II (按奇偶排序陣列 II)
 * 難度：簡單 (Easy)
 * 描述：給定一個整數陣列 nums，其中一半是偶數，一半是奇數。
 *      請將陣列排序，使得偶數索引位置放偶數，奇數索引位置放奇數。
 * 
 * 時間複雜度：O(n) - 每個指標最多遍歷陣列一次。
 * 空間複雜度：O(1) - 直接在原陣列進行交換，不使用額外空間。
 * 
 * 解法思路 (雙指標)：
 * 1. 使用兩個指標：`i` 指向偶數索引（起始為 0），`j` 指向奇數索引（起始為 1）。
 * 2. 透過 `while` 迴圈檢查位置：
 *    - 如果 nums[i] 已經是偶數，則 `i += 2` 跳過正確位置。
 *    - 如果 nums[j] 已經是奇數，則 `j += 2` 跳過正確位置。
 *    - 若兩者都不符合（代表 nums[i] 是奇數且 nums[j] 是偶數），直接 `swap(nums[i], nums[j])`。
 * 3. 當其中一個指標超出範圍時，陣列即已完成排序。
 */

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int i = 0; // 偶數指標
        int j = 1; // 奇數指標
        
        while (i < n && j < n) {
            // 如果當前偶數索引位置放的是偶數，直接跳過
            if (nums[i] % 2 == 0) {
                i += 2;
            } 
            // 如果當前奇數索引位置放的是奇數，直接跳過
            else if (nums[j] % 2 == 1) {
                j += 2;
            } 
            // 如果都不對（nums[i] 是奇數且 nums[j] 是偶數），交換它們
            else {
                swap(nums[i], nums[j]);
                i += 2;
                j += 2;
            }
        }
        return nums;
    }
};
