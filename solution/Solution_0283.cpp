/**
 * 題目：283. Move Zeroes (移動零)
 * 難度：簡單 (Easy)
 * 描述：將所有 0 移動到陣列末尾，並維持非零元素的相對順序。
 *
 * 時間複雜度：O(N) - 每個元素被訪問且最多參與一次交換。
 * 空間複雜度：O(1) - 原地操作 (In-place)。
 *
 * 解法思路：
 * 1. `slow` 指標指向下一個應該存放非零元素的位置。
 * 2. `fast` 指標遍歷整個陣列。
 * 3. 當 `nums[fast]` 不為 0 時，與 `nums[slow]` 交換，並將 `slow` 向前推進。
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int fast = 0, slow = 0; fast < nums.size(); ++fast) {
            if (nums[fast] != 0) {
                swap(nums[fast], nums[slow++]);
            }
        }
    }
};
