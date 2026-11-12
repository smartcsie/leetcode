/**
 * 題目：2044. Count Number of Maximum Bitwise-OR Subsets
 * 難度：Medium
 * 描述：給定整數陣列 nums，找出子集（以索引區分）能得到的最大按位或（bitwise OR）值，
 *       並回傳有多少個不同的子集能達到這個最大值。
 *
 * 分類主題：backtracking-combination
 * 技巧：遞迴選或不選, OR 只增不減所以最大值是全部元素的 OR, OR 達標後剩餘元素任選直接用 2^k 計數
 *
 * 時間複雜度：O(2^n)，最壞情況要走完整棵決策樹；OR 提早達標時會少走很多分支
 * 空間複雜度：O(n)，遞迴深度
 *
 * 解法思路：遞迴 + 提早結束
 * 1. OR 只會讓位元越來越多，所以任何子集的 OR 都不會超過「全部元素的 OR」，
 *    最大值 target 就是全部元素 OR 起來的結果。問題變成：有幾個子集的 OR 等於 target。
 * 2. 決策樹：對每個 nums[i] 決定「不選」或「選」，cur 記錄目前選到的元素的 OR。
 * 3. 提早結束：只要 cur 已經等於 target，
 *    剩下 n - i 個元素不論選不選，OR 都不會再變（不會超過 target，也不會變小），
 *    所以這 n - i 個元素任意取捨，共 2^(n - i) 種，全部合格，直接回傳。
 * 4. 邊界：i == n 時，若 cur == target 會在第 3 點回傳 1 << 0 = 1；
 *    否則代表走到底都沒達標，回傳 0。
 * 5. 空子集的 OR 是 0，而 nums[i] >= 1，所以 target >= 1，空子集不會被誤算。
 */
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;  // 全部元素的 OR，也就是最大可能的 OR 值
        for (int x : nums) target |= x;
        return dfs(nums, 0, 0, target);
    }

private:
    // i：目前要決定的元素索引；cur：目前選到的元素的 OR
    int dfs(const vector<int>& nums, int i, int cur, int target) {
        int n = nums.size();

        // 目前 OR 已達最大值：剩下 n - i 個元素任選，共 2^(n - i) 種，全部合格
        if (cur == target) return 1 << (n - i);

        // 所有元素都決定完了，仍沒有達到最大值
        if (i == n) return 0;

        return dfs(nums, i + 1, cur, target)              // 不選 nums[i]
             + dfs(nums, i + 1, cur | nums[i], target);   // 選 nums[i]
    }
};