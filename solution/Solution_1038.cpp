/**
 * 題目：1038. Binary Search Tree to Greater Sum Tree (將 BST 轉為大於值總和樹)
 * 難度：中等 (Medium)
 * 描述：將 BST 的每個節點值替換為原節點值加上所有大於該節點值的節點之和。
 * * 時間複雜度：O(N) - 每個節點被訪問一次。
 * 空間複雜度：O(H) - H 為樹的高度 (遞迴深度)。
 * * 優化思路：
 * 1. 反向中序遍歷：按照「右、根、左」的順序遍歷，數值會由大到小累積。
 * 2. 累加狀態：使用變數 `sum` 維護當前遍歷過所有節點的累計總和。
 */

class Solution {
private:
    void reverseInorder(TreeNode* root, int& cur) {
        if(!root) return;
        reverseInorder(root->right, cur);
        root->val += cur;
        cur = root->val;
        reverseInorder(root->left, cur);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int cur = 0;
        reverseInorder(root, cur);
        return root;
    }
};
