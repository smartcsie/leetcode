/**
 * 題目：700. Search in a Binary Search Tree (二元搜尋樹中的搜尋)
 * 難度：簡單 (Easy)
 * 描述：在 BST 中尋找值為 val 的節點，若存在則回傳該節點，否則回傳 nullptr。
 *
 * 時間複雜度：O(H)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 利用 BST 特性，比目標值小則往右，大則往左，直到找到節點或到達葉子節點為止。
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root && root->val != val) {
            if(val < root->val ) root = root->left;
            else if(val > root->val ) root = root->right;
        }
        return root;
    }
};
