/**
 * 題目：230. Kth Smallest Element in a BST (BST 中第 K 小的元素)
 * 難度：中等 (Medium)
 * 描述：在 BST 中找出第 k 小的元素。
 *
 * 時間複雜度：O(H+K)
 * 空間複雜度：O(H)
 */

class Solution {
private:
    void inorder(TreeNode* root, int& k, int& ans) {
        if(!root) return;
        inorder(root->left, k, ans);
        if(--k == 0) {
            ans = root->val;
            return;
        }
        inorder(root->right, k, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inorder(root, k, ans);
        return ans;
    }
};
