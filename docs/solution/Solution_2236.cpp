/**
 * 題目：2236. Root Equals Sum of Children (根節點等於子節點和)
 * 難度：簡單 (Easy)
 * 描述：檢查根節點的值是否等於其左、右子節點值的和。
 * * 時間複雜度：O(1) - 僅進行一次加法與一次比較。
 * 空間複雜度：O(1) - 無額外記憶體開銷。
 * * 優化思路：
 * 1. 簡潔性：利用布林運算直接回傳結果，無需 if-else。
 */

class Solution {
public:
    bool checkTree(TreeNode* root) {
        return root->val == (root->left->val + root->right->val);
    }
};
