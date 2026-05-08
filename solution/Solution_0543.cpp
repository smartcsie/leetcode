class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> int {
            if(!root) return 0;
            int l = dfs(root->left);
            int r = dfs(root->right);
            diameter = max (diameter, l + r);
            return 1 + max(l , r);
        };
        dfs(root);
        return diameter;
    }
};