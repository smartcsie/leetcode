/**
 * 題目：103. Binary Tree Zigzag Level Order Traversal (二元樹 Z 字型層次遍歷)
 * 難度：中等 (Medium)
 * 描述：以 Z 字型順序遍歷二元樹。
 *
 * 時間複雜度：O(N) - 每個節點僅被存取一次。
 * 空間複雜度：O(W) - W 為樹的最大寬度，用於儲存隊列與當前層節點。
 *
 * 解法思路：
 * 1. 使用 `std::deque` 可以在 O(1) 時間內進行雙端插入，避免 `reverse()` 操作帶來的 O(K) 額外開銷。
 * 2. 透過 `res.reserve(N)` 與 `oneLevel.reserve(width)` 預分配記憶體，提升效能。
 */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        int cnt = 0;
        while (!q.empty()) {
            vector<int> oneLevel;
            for (int i = q.size(); i > 0; --i) {
                TreeNode *t = q.front(); q.pop();
                oneLevel.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            if (cnt % 2 == 1) reverse(oneLevel.begin(), oneLevel.end());
            res.push_back(oneLevel);
            ++cnt;
        }
        return res;
    }
};
