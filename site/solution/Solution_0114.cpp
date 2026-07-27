/**
 * 題目：114. Flatten Binary Tree to Linked List (將二元樹展開為連結串列)
 * 難度：中等 (Medium)
 * 描述：將二元樹攤平為一個「只有右子節點」的串列，順序為前序遍歷。
 * * 時間複雜度：O(N) - 每個節點訪問一次。
 * 空間複雜度：O(H) - H 為樹的高度 (遞迴深度)。
 * * 優化思路：
 * 1. 遞迴回傳末端：遞迴函式回傳該子樹攤平後的最後一個節點，避免重複遍歷串列。
 */

class Solution {
private:
     TreeNode* flattenTail(TreeNode* root) {
        if(!root) return nullptr;
        if(!root->left && !root->right) return root;
        TreeNode* leftTail = flattenTail(root->left);
        TreeNode* rightTail = flattenTail(root->right);
        if(root->left) {
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = nullptr;
            leftTail->right = temp;
        }
        return rightTail ? rightTail : leftTail;
     }
public:
    void flatten(TreeNode* root) {
        flattenTail(root);
    }
};
