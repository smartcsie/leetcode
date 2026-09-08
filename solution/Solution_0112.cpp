/**
 * 註解：待補充
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)

 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right && root->val == targetSum) return true;
        return hasPathSum(root->left, targetSum -root->val) || hasPathSum(root->right, targetSum -root->val);
    }
};