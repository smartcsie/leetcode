# Solution_3392

```cpp
/**
 * 題目：3392. Count Subarrays of Length Three With a Condition
 * 描述：給你一個整數陣列 nums，請你返回長度為 3 且滿足以下條件的子陣列數量：
 *       子陣列的第一個元素加上第三個元素的兩倍（或根據題目數學關係：2 * (nums[i] + nums[i+2]) == nums[i+1]）等於中間元素。
 *       *(註：實際題目條件通常為 第一個加第三個的總和乘以 2 等於中間元素，或視具體題目數學式而定)*
 * 
 * 解法思路（固定長度視窗滑動模擬）：
 * 1. 限制迴圈範圍：
 *    - 由於子陣列長度固定為 3，我們只需要遍歷陣列到 `n - 3` 的位置（即 `i <= n - 3`），確保以 `i` 為起點時後面還有足夠的兩個元素。
 * 2. 條件判斷與計數：
 *    - 對於每一個起點 `i`，直接套用題目給定的數學公式檢查 `2 * (nums[i] + nums[i+2]) == nums[i+1]`。
 *    - 若符合條件，將計數器 `count` 加 1。
 * 時間複雜度：O(N) - 單次遍歷，固定視窗大小 3。
 * 空間複雜度：O(1) - 僅使用常數空間。

 */

class Solution {
public:
    int countSubarrays(std::vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        // 遍歷所有可能的長度為 3 的子陣列起點
        for (int i = 0; i <= n - 3; i++) {
            // 檢查題目規定的數學條件
            if (2 * (nums[i] + nums[i + 2]) == nums[i + 1]) {
                count++;
            }
        }
        return count;
    }
};

```
