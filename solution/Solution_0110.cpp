/**
 * 題目：110. Balanced Binary Tree
 * 難度：簡單 (Easy)
 * 描述：判斷一棵二元樹是否為高度平衡的二元樹（每個節點的左右子樹高度差不超過 1）。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * （遞迴計算高度 + 判斷平衡）：
 * 對每個節點計算左右子樹高度，若差值超過 1 或子樹不平衡則回傳 false。
 **/
class Solution {
public:
    int depth(TreeNode* root) {
        if(!root) return 0;
        else return 1 + max(depth(root->left),depth(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        else if(abs(depth(root->left) - depth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};