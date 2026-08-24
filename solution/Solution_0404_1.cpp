class Solution {
private:
    void dfs(TreeNode* root, int& sum, bool left) {
        if(!root) return;
        dfs(root->left, sum, true);
        if(left && !root->left && !root->right) sum += root->val;
        dfs(root->right, sum, false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        dfs(root, sum, false);
        return sum;
    }
};