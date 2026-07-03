/**
 * 題目：39. Combination Sum (組合總和)
 * 難度：中等 (Medium)
 * 描述：在給定陣列中尋找和為 target 的所有組合（元素可重複使用）。
 * * 時間複雜度：O(N^(T/M))，其中 T 為目標值，M 為最小的候選數。
 * 空間複雜度：O(T/M) - 遞迴堆疊深度，取決於選擇最小元素的次數。
 * * 優化思路：
 * 1. 排序：先對 `candidates` 進行排序。
 * 2. 剪枝：在 `for` 迴圈中，若 `candidates[i] > target`，直接結束迴圈，因為後續元素更大。
 */

class Solution {
    void combinationSum(vector<int>& candidates, int target, int start, vector<int>& cur, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(cur);
            return;
        }
        for(int i = start; i < candidates.size(); i++) {
            if(candidates[i] > target) break;
            cur.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i] , i, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, target, 0, cur, res);
        return res;
    }
};
