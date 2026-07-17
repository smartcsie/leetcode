/**
 * 題目：897. Increasing Order Search Tree
 * 描述：重新排列二元搜尋樹，使其成為一個遞增的單鏈樹 (只有右子節點)。
 * 
 * 解法思路：
 * 1. 使用中序遍歷 (In-order Traversal)。
 * 2. 遞迴函數 `inorder(root, pre)`：
 *    - `pre` 代表當前節點處理完後，右側應該連接的後繼節點。
 *    - 在處理每個節點時，將其 `left` 指向 `nullptr`，並將其 `right` 指向遞迴返回的結果。
 */

class Solution {
    // 遞迴函數：回傳轉換後的子樹之頭節點，pre 為右側後繼節點
    TreeNode* inorder(TreeNode* root, TreeNode* pre) {
        if (!root) return pre;
        
        // 處理左子樹，並將當前節點作為該左子樹的後繼
        TreeNode* res = inorder(root->left, root);
        
        // 切斷左鏈，將右側連接到右子樹遞迴處理後的結果
        root->left = nullptr;
        root->right = inorder(root->right, pre);
        
        return res;
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        return inorder(root, nullptr);
    }
};
