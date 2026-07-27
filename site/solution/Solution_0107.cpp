/**
 * 題目：107. Binary Tree Level Order Traversal II (自底向上的層序遍歷)
 * 難度：簡單 (Easy)
 * 描述：回傳二元樹自底向上的層序遍歷結果。
 * * 時間複雜度：O(N) - 每個節點訪問一次，反轉操作為 O(L)，總和為 O(N)。
 * 空間複雜度：O(W) - W 為樹的最大寬度。
 * * 優化思路：
 * 1. 正常進行 BFS 從上到下收集每一層。
 * 2. 最後使用 std::reverse 反轉整個結果容器，大幅減少記憶體移動成本。
 */

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q({root});
        while(!q.empty()) {
            vector<int> level;
            for(int i = q.size() - 1; i >= 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
