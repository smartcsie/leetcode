/**
 * 題目：404. Sum of Left Leaves (左葉子節點之和)
 * 難度：簡單 (Easy)
 * 描述：計算二元樹中所有左葉子節點的和。
 * * 時間複雜度：O(N) - 每個節點最多被訪問一次。
 * 空間複雜度：O(H) - H 為樹的高度（遞迴堆疊空間）。
 * * 設計思路：
 * 遞迴檢查每個節點：
 * 1. 若該節點的左子節點是葉子，則直接加上該值。
 * 2. 若不是，則遞迴搜尋左子樹與右子樹。
 */

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        if(root->left) {
            if(!root->left->left && !root->left->right) sum += root->left->val;
            else sum += sumOfLeftLeaves(root->left);
        }   
        sum += sumOfLeftLeaves(root->right);
        return sum;
    }
};
