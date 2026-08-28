/**
 * 題目：938. Range Sum of BST (二元搜尋樹的範圍總和)
 * 難度：簡單 (Easy)
 * 描述：回傳所有值在 [low, high] 範圍內的節點數值之和。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * 1. 若 root->val < low：說明整個左子樹都太小，只需搜尋右子樹。
 * 2. 若 root->val > high：說明整個右子樹都太大，只需搜尋左子樹。
 * 3. 若在區間內：將當前值計入，並同時搜尋左右子樹。
 */

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        if(root-> val < low) return rangeSumBST(root->right, low ,high);
        if(root-> val > high) return rangeSumBST(root->left, low ,high);
        return root->val 
                + rangeSumBST(root->left, low, high)
                + rangeSumBST(root->right, low, high);
    }
};
