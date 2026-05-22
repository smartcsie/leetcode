/**
 * 題目：94. Binary Tree Inorder Traversal (二元樹的中序走訪)
 * 難度：簡單 (Easy)
 * 描述：給定一個二元樹的根節點 root ，返回它的「中序走訪」結果。
 *      順序：左子樹 -> 根節點 -> 右子樹
 * 
 * 時間複雜度：O(n) - 每個節點都會被訪問且僅被訪問一次。
 * 空間複雜度：O(h) - h 為樹的高度，遞迴棧空間。
 *      - 最壞情況（傾斜樹）：O(n)
 *      - 最好情況（平衡樹）：O(log n)
 * 
 * 解法思路 (遞迴)：
 * 1. 基本情況 (Base Case)：如果當前節點為 nullptr，則直接返回。
 * 2. 遞迴處理左子樹。
 * 3. 處理當前根節點（存入結果）。
 * 4. 遞迴處理右子樹。
 */

class Solution {
public:
    // 輔助函數：執行遞迴走訪
    void inorder(TreeNode* root, vector<int>& res) {
        if (root == nullptr) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};
