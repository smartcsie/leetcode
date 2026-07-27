/**
 * 題目：701. Insert into a Binary Search Tree (二元搜尋樹中的插入操作)
 * 難度：中等 (Medium)
 * 描述：將數值 val 插入 BST 中，並確保樹結構依然滿足 BST 特性。
 * * 時間複雜度：O(H) - H 為樹的高度。最壞情況 O(N)，平均 O(log N)。
 * 空間複雜度：O(H) - 遞迴堆疊深度。
 * * 優化思路：
 * 利用遞迴函式的回傳值（回傳新的子樹根節點）。
 * 如果遇到 null，則回傳 new TreeNode(val)；
 * 否則根據大小遞迴處理子樹，並將回傳的結果賦值給當前節點的左右指標。
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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // 基本情況：找到插入位置
        if (!root) {
            return new TreeNode(val);
        }
        
        // 根據 BST 性質選擇路徑
        if (val < root->val) {
            // 將插入結果重新連回左子樹
            root->left = insertIntoBST(root->left, val);
        } else {
            // 將插入結果重新連回右子樹
            root->right = insertIntoBST(root->right, val);
        }
        
        return root;
    }
};
