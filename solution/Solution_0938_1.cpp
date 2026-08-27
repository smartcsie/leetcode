class Solution {
private:
    void dfs(TreeNode* root, int low, int high, int& sum) {
        if(!root) return;
        dfs(root->left, low, high, sum);
        if(root->val >= low && root->val <= high)sum += root->val;
        dfs(root->right, low, high, sum);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int sum = 0;
        dfs(root, low, high, sum);
        return sum;
    }
};