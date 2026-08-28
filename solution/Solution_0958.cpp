/**
 * 題目：958. Check Completeness of a Binary Tree (二元樹的完全性檢驗)
 * 難度：中等 (Medium)
 * 描述：檢查一棵二元樹是否為完全二元樹。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(W)
 *
 * 解法思路：
 * 1. 層序遍歷：利用 BFS。
 * 2. 空節點檢查：當遇到第一個空節點後，只要後續再出現任何一個非空節點，則該樹不完全。
 */

if(!root) return true;
        queue<TreeNode*> q({root});
        while(q.front()) {
            TreeNode* node = q.front();
            q.pop();
            q.push(node->left);
            q.push(node->right);
        }
        while(!q.empty() && !q.front()) q.pop();
        return q.empty();