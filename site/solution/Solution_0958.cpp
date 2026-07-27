/**
 * 題目：958. Check Completeness of a Binary Tree (二元樹的完全性檢驗)
 * 難度：中等 (Medium)
 * 描述：檢查一棵二元樹是否為完全二元樹。
 * * 時間複雜度：O(N) - 遍歷所有節點。
 * 空間複雜度：O(W) - W 為樹的最大寬度，用於存放佇列。
 * * 優化思路：
 * 1. 層序遍歷：利用 BFS。
 * 2. 空節點檢查：當遇到第一個空節點後，只要後續再出現任何一個非空節點，則該樹不完全。
 */

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q({root});
        TreeNode* prev = root;
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(!prev && cur) return false;
            if(cur) {
                q.push(cur->left);
                q.push(cur->right);
            }
            prev = cur;
        }
        return true;
    }
};
