/**
 * 題目：101. Symmetric Tree (對稱二元樹)
 * 難度：簡單 (Easy)
 * 描述：判斷一棵二元樹是否為鏡像對稱。
 * * 時間複雜度：O(N) - 每個節點被遍歷一次。
 * 空間複雜度：O(H) - H 為樹的高度，遞迴棧空間。
 * * 優化思路：
 * 對稱樹的定義是：左右子樹互為鏡像。
 * 即：左子樹的左子節點等於右子樹的右子節點，且左子樹的右子節點等於右子樹的左子節點。
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    bool isSymmetric(TreeNode* root1, TreeNode* root2) {
        return (!root1 && !root2) ||
        ( (root1 && root2) && (root1->val == root2->val) &&
            isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
};
