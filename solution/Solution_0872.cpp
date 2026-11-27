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
    void dfs(TreeNode* root, vector<int>& leaves) {
        if(!root) return;
        if(!root->left && !root->right) leaves.push_back(root->val);
        dfs(root->left, leaves);
        dfs(root->right, leaves);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        dfs(root1, leaves1);
        dfs(root2, leaves2);
        return leaves1 == leaves2;
    }
};