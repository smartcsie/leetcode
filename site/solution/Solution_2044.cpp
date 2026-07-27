/**
 * 題目：2044. Count Number of Maximum Bitwise-OR Subsets (統計按位或能得到最大值的子集數目)
 * 難度：中等 (Medium)
 * 描述：求所有子集按位或運算後，能達到最大值的子集有多少個。
 * * 時間複雜度：O(2^N) - 遍歷所有子集。
 * 空間複雜度：O(N) - 遞迴堆疊深度。
 * * 優化思路：
 * 1. 預計算目標值：整個陣列的位元或結果就是所有子集能達到的最大值。
 * 2. 簡化 DFS：只需統計有多少子集的 OR 結果等於目標值。
 */

class Solution {
private:
    int count = 0;
    int target = 0;

    void dfs(const vector<int>& nums, int index, int currentOr) {
        // 達到終點：檢查目前累積的 OR 是否等於目標最大值
        if (index == nums.size()) {
            if (currentOr == target) count++;
            return;
        }
        
        // 選擇包含當前數字：更新 OR 值
        dfs(nums, index + 1, currentOr | nums[index]);
        
        // 選擇不包含當前數字
        dfs(nums, index + 1, currentOr);
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        target = 0;
        count = 0;
        // 先計算全陣列的 OR，這即為子集能達到的最大值
        for (int num : nums) target |= num;
        
        dfs(nums, 0, 0);
        return count;
    }
};
