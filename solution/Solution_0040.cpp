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
    void dfs(const vector<int>& candidates, int target, int start, vector<int>& cur, vector<vector<int>>& res) {
        // 目標達成，儲存當前路徑組合
        if (target == 0) {
            res.push_back(cur);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // 剪枝：若當前數字已大於目標值，後續數字更大，無需繼續搜尋
            if (candidates[i] > target) break;
            
            // 去重：同一層遞迴中，若當前數值與前一個相同，則跳過，防止產生重複組合
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            cur.push_back(candidates[i]);
            // 傳入 i + 1，確保下一層遞迴不會重複使用當前元素
            dfs(candidates, target - candidates[i], i + 1, cur, res);
            cur.pop_back(); // 回溯
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        
        // 必須先排序，這是正確使用去重邏輯的前提
        sort(candidates.begin(), candidates.end());
        
        dfs(candidates, target, 0, cur, res);
        return res; 
    }
};
