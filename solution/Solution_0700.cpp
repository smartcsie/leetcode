/**
 * 題目：700. Search in a Binary Search Tree (二元搜尋樹中的搜尋)
 * 難度：簡單 (Easy)
 * 描述：在 BST 中尋找值為 val 的節點，若存在則回傳該節點，否則回傳 nullptr。
 * * 時間複雜度：O(H)，其中 H 為樹的高度。
 * 空間複雜度：O(1) - 迭代法不佔用額外遞迴堆疊空間。
 * * 優化思路：
 * 利用 BST 特性，比目標值小則往右，大則往左，直到找到節點或到達葉子節點為止。
 */

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root && val != root->val) {
            if (val < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return root;
    }
};
