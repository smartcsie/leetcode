/**
 * 題目：2305. Fair Distribution of Cookies
 * 難度：中等 (Medium)
 * 描述：給定 n 袋餅乾（每袋 cookies[i] 片）和 k 個小孩，把每袋餅乾
 * （整袋不能拆）分給某個小孩，求「拿最多的那個小孩」所拿到的餅乾數，
 * 最小可能是多少（讓分配最公平）。
 *
 * 時間複雜度：O(K^N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （Constraint Satisfaction 回溯，每一步「放置」一袋餅乾都要更新
 * 全域最大值，並用它來剪枝，是這題跟 N-Queens/Sudoku 同一分類的
 * 原因）：
 * 1. backtrack(index, curMax) 代表「處理到第 index 袋餅乾為止，目前
 *    所有小孩裡拿最多的那個是 curMax」。
 * 2. **關鍵剪枝**：如果 curMax 已經 >= 目前找到的最佳解 best，代表
 *    這條路不可能比現有解更好（後面只會更多不會變少），直接放棄這條
 *    分支，不用繼續遞迴——這是這題效能的關鍵，沒有這個剪枝會慢很多。
 * 3. 狀態轉移：對第 index 袋餅乾，枚舉分給哪個小孩 i，更新那個小孩
 *    的總數，遞迴處理下一袋，回溯時要記得把餅乾數扣回去（children[i]
 *    -= cookies[index]），恢復現場給下一個小孩的嘗試用。
 * 4. base case：所有餅乾都分完了（index 到底），更新全域最佳解 best
 *    為目前的 curMax（如果更小的話）。
 */
class Solution {
    int best = INT_MAX;

    void backtrack(vector<int>& cookies, vector<int>& children, int index, int curMax) {
        if (curMax >= best) return;
        if (index == (int)cookies.size()) {
            best = min(best, curMax);
            return;
        }
        for (int i = 0; i < (int)children.size(); ++i) {
            children[i] += cookies[index];
            backtrack(cookies, children, index + 1, max(curMax, children[i]));
            children[i] -= cookies[index];
        }
    }

public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k, 0);
        backtrack(cookies, children, 0, 0);
        return best;
    }
};
