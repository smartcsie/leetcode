/**
 * 題目：872. Leaf-Similar Trees (葉子相似的樹)
 * 難度：簡單 (Easy)
 * 描述：檢查兩棵樹的葉子節點序列是否相同。
 *
 * 時間複雜度：O(N+M)
 * 空間複雜度：O(H1+H2)
 *
 * 解法思路：
 * 1. 使用 DFS 遍歷並提取葉子節點。
 * 2. 透過 vector 的賦值比較直接驗證兩序列是否一致。
 */

class Solution {
private:
    void dfs(TreeNode* root, vector<int>& ans) {
        if(!root) return;
        dfs(root->left, ans);
        if(!root->left && !root->right) ans.push_back(root->val);
        dfs(root->right, ans);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        dfs(root1, v1);
        dfs(root2, v2);
        return v1 == v2;
    }
};