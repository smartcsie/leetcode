/**
 * 題目：22. Generate Parentheses (生成括號)
 * 難度：中等 (Medium)
 * 描述：使用 DFS 遞迴窮舉所有合法的括號排列組合。
 * * 時間複雜度：O(4^N / sqrt(N)) - Catalan Number 的漸進複雜度。
 * 空間複雜度：O(N) - 遞迴堆疊深度與字串長度。
 * * 邏輯解析：
 * 1. left: 剩餘可用的左括號數量。
 * 2. right: 剩餘可用的右括號數量。
 * 3. 剪枝條件：若 left > right，代表目前已使用的右括號多於左括號（即右邊已經多於左邊），此路徑必為非法。
 */

class Solution {
private:
    void dfs(int left, int right, string cur, vector<string>& res) {
        if(left > right) return;
        if(left == 0 && right == 0) res.push_back(cur);
        if(left > 0) dfs( left - 1,  right,  cur + '(', res);
        if(right > 0) dfs( left, right - 1,  cur + ')', res);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n, n, "", res);
        return res;
    }
};
