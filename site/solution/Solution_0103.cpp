/**
 * 題目：103. Binary Tree Zigzag Level Order Traversal (二元樹 Z 字型層次遍歷)
 * 難度：中等 (Medium)
 * 描述：以 Z 字型順序遍歷二元樹。
 * * 時間複雜度：O(N) - 每個節點僅被存取一次。
 * 空間複雜度：O(W) - W 為樹的最大寬度，用於儲存隊列與當前層節點。
 * * 優化思路：
 * 1. 使用 `std::deque` 可以在 O(1) 時間內進行雙端插入，避免 `reverse()` 操作帶來的 O(K) 額外開銷。
 * 2. 透過 `res.reserve(N)` 與 `oneLevel.reserve(width)` 預分配記憶體，提升效能。
 */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        
        bool leftToRight = true; // 旗標：控制當前層的插入順序
        
        while (!q.empty()) {
            int size = q.size();
            // 使用 deque 進行雙端插入，直接在生成時決定順序
            deque<int> level;
            
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                if (leftToRight) {
                    level.push_back(node->val);
                } else {
                    level.push_front(node->val);
                }
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // 將 deque 轉為 vector 放入結果集
            res.emplace_back(vector<int>(level.begin(), level.end()));
            leftToRight = !leftToRight; // 切換順序
        }
        
        return res;
    }
};
