/**
 * 題目：78. Subsets (子集)
 * 難度：中等 (Medium)
 * 描述：回傳所有可能的子集 (冪集)。
 * * 時間複雜度：O(N * 2^N) - 共有 2^N 個子集，每個子集平均長度為 N。
 * 空間複雜度：O(N) - 遞迴堆疊深度與暫存路徑空間。
 * * 優化思路：
 * 使用「迴圈 + 回溯」模式，讓每一層的遍歷都能清楚地處理「從當前索引開始的所有元素」，
 * 這比單純的選擇/不選擇遞迴更符合大多數排列組合類題目的慣用寫法。
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(nums, 0, path, res);
        return res;
    }

private:
    void backtrack(const vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
        // 任何時刻的路徑都是一個合法的子集
        res.push_back(path);
        
        for (int i = start; i < nums.size(); ++i) {
            // 做選擇
            path.push_back(nums[i]);
            // 往下一層遞迴
            backtrack(nums, i + 1, path, res);
            // 回溯，撤銷選擇
            path.pop_back();
        }
    }
};
