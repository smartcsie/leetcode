/**
 * 註解：待補充
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)

 */
class Solution {
public:
    int minDepth(TreeNode* root) {
            if(!root) return 0;
            if(!root->left) return 1 + minDepth(root->right);
            if(!root->right) return 1 + minDepth(root->left);
            return 1+min(minDepth(root->left), minDepth(root->right));
    }
};
