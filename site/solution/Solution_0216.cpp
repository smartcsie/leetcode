/**
 * 題目：216. Combination Sum III (組合總和 III)
 * 難度：中等 (Medium)
 * 描述：在 1-9 的數字中選出 k 個不同的數，使其總和為 n。
 * * 時間複雜度：O(C(9, k))，固定為從 9 個數中取 k 個的組合數。
 * 空間複雜度：O(k) - 遞迴堆疊深度與當前路徑長度。
 * * 優化思路：
 * 1. 數量剪枝：若當前已選數量 + 剩餘可選數量 < k，直接返回。
 * 2. 總和剪枝：若當前總和已經大於 n，直接 break 停止迴圈。
 */

class Solution {
private:
    void dfs(int k, int n, int start, vector<int>& cur, vector<vector<int>>& res) {
        // 剪枝：若元素已滿 k 個，檢查總和是否符合
        if (cur.size() == k) {
            if (n == 0) res.push_back(cur);
            return;
        }

        // 剪枝：從 start 開始遍歷，至多到 9。
        // 優化：i <= 9 - (k - cur.size()) + 1，確保剩餘空間足以放入剩下的數字
        for (int i = start; i <= 9 - (k - cur.size()) + 1; ++i) {
            // 剪枝：若當前數字已大於剩餘目標 n，後續更大，直接 break
            if (i > n) break;

            cur.push_back(i);
            dfs(k, n - i, i + 1, cur, res);
            cur.pop_back(); // 回溯
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(k, n, 1, cur, res);
        return res;
    }
};
