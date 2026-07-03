/**
 * 題目：40. Combination Sum II (組合總和 II)
 * 難度：中等 (Medium)
 * 描述：在包含重複數字的陣列中，尋找和為 target 的唯一組合（每個元素只能使用一次）。
 * * 時間複雜度：O(2^N) - 在最壞情況下需遍歷所有子集。
 * 空間複雜度：O(N) - 遞迴深度最多為陣列長度。
 * * 優化思路：
 * 1. 排序：`sort` 後可利用 `candidates[i] == candidates[i - 1]` 判斷重複。
 * 2. 剪枝：當 `candidates[i] > target` 時直接 `break`，減少無效分支。
 * 3. 遞迴傳遞：參數 `i + 1` 確保同一數字在單一組合中不被重複選取。
 */

class Solution {
private:
    void combinationSum2(vector<int>& candidates, int target, int start, vector<int>& cur, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(cur);
            return;
        }
        for(int i = start; i < candidates.size(); i++) {
            if(candidates[i] > target) break;
            if(i > start && candidates[i] == candidates[i - 1]) continue;
            cur.push_back(candidates[i]);
            combinationSum2(candidates, target - candidates[i], i+1, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        combinationSum2(candidates, target, 0, cur, res);
        return res;
    }
};
