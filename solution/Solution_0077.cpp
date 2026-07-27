/**
 * 題目：77. Combinations (組合)
 * 難度：中等 (Medium)
 * 描述：在 1 到 n 的整數中選取 k 個數字的所有組合。
 * * 時間複雜度：O(k * C(n, k)) - 其中 C(n, k) 為組合數。
 * 空間複雜度：O(k) - 遞迴堆疊深度與路徑長度。
 * * 優化思路：
 * 1. 剪枝 (Pruning)：在迴圈條件中加入 `i <= n - (k - cur.size()) + 1`。
 * 這意味著如果剩餘的可選數字個數小於還需要的個數，直接停止搜尋。
 */

class Solution {
private:
    void combine(int n, int start, int k , vector<int>& cur,vector<vector<int>>& res) {
        if(cur.size() == k) {
            res.push_back(cur);
            return;
        }
        for(int i =start; i <= n; i++ ) {
            cur.push_back(i);
            combine(n, i + 1, k, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        combine(n, 1, k, cur, res);
        return res;
    }
};
