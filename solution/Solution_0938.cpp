/**
 * 題目：938. Range Sum of BST (二元搜尋樹的範圍總和)
 * 難度：簡單 (Easy)
 * 描述：回傳所有值在 [low, high] 範圍內的節點數值之和。
 * * 時間複雜度：O(N) - 最壞情況需遍歷所有節點。
 * 空間複雜度：O(H) - H 為樹的高度，遞迴深度。
 * * 優化思路：
 * 1. 若 root->val < low：說明整個左子樹都太小，只需搜尋右子樹。
 * 2. 若 root->val > high：說明整個右子樹都太大，只需搜尋左子樹。
 * 3. 若在區間內：將當前值計入，並同時搜尋左右子樹。
 */

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        
        // 情況 1：當前節點太小，只需往右找
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        
        // 情況 2：當前節點太大，只需往左找
        if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }
        
        // 情況 3：當前節點在範圍內，計入當前值，並繼續往兩邊搜尋
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};
