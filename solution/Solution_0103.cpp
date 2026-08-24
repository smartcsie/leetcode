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
        if(!root) return {};
        deque<TreeNode*> q({root});
        vector<vector<int>> ans;
        bool leftToRight = true;
        while(!q.empty()) {
            vector<int> row;
            for(int i = q.size() - 1; i >= 0; i--) {
                 TreeNode* node;
                if(leftToRight) {
                    node= q.front();
                    q.pop_front();
                    row.push_back(node->val);
                    if(node->left) q.push_back(node->left);
                    if(node->right) q.push_back(node->right);
                } else {
                    node = q.back();
                    q.pop_back();
                    row.push_back(node->val);
                    if(node->right) q.push_front(node->right);
                    if(node->left) q.push_front(node->left);
                }
            }
            leftToRight = !leftToRight;
            ans.push_back(row);
        }
        return ans;
    }
};