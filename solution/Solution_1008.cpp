/**
 * 題目：1008. Construct Binary Search Tree from Preorder Traversal
 * 難度：中等
 * 優化思路：利用 BST 的性質 (Left < Root < Right)，
 * 為每個節點設定允許的數值範圍 [min, max]。
 */

class Solution {
private:
    int index = 0;
    TreeNode* build(vector<int>& preorder, int left, int right) {
        if(index >= preorder.size() || preorder[index] < left || preorder[index] > right) 
            return nullptr;
        TreeNode* root = new TreeNode( preorder[index++]);
        root->left = build(preorder, left, root->val);
        root->right = build(preorder, root->val, right);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, 0, 1001);
    }
};
