/**
 * 題目：783. Minimum Distance Between BST Nodes (BST 節點間的最小距離)
 * 難度：簡單 (Easy)
 * 描述：在二元搜尋樹中，找出任意兩個節點值之間的最小差值。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * 1. BST 中序遍歷產生的數列必定是單調遞增的。
 * 2. 最小差值必定出現在中序遍歷產生的相鄰節點之間。
 */

class Solution {
private:
    void inorder(TreeNode* root, int& pre, int& mn) {
        if(!root) return;
        inorder(root->left, pre, mn);
        if(pre != -1) mn = min(mn, root->val - pre);
        pre = root->val;
        inorder(root->right, pre, mn);
    }
public:
    int minDiffInBST(TreeNode* root) {
        int mn = INT_MAX, pre = -1;
        inorder(root, pre, mn);
        return mn;
    }
};