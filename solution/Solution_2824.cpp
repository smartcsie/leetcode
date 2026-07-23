/**
 * 題目：2824. Count Pairs Whose Sum is Less than Target
 * 描述：給你一個從 0 開始編號長度為 n 的整數陣列 nums 和一個整數 target，
 *       請返回滿足 0 <= i < j < n 且 nums[i] + nums[j] < target 的下標對 (i, j) 的數量。
 * 
 * 解法思路：
 * 1. 宣告變數 `ans` 用來記錄符合條件的數對總數。
 * 2. 使用雙層迴圈枚舉所有不重複的數對組合：
 *    - 外層迴圈 `i` 從 0 走到 `n - 1`。
 *    - 內層迴圈 `j` 從 `i + 1` 走到 `n - 1`（確保 i < j）。
 * 3. 檢查 `nums[i] + nums[j]` 是否小於 `target`，若是則將 `ans` 加 1。
 * 4. 迴圈結束後返回 `ans`。
 */

class Solution {
public:
    int countPairs(std::vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        // 雙層迴圈枚舉所有可能的數對 (i, j)
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] < target) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
