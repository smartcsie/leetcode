/**
 * 題目：226. Invert Binary Tree (翻轉二元樹)
 * 難度：簡單 (Easy)
 * 描述：翻轉一棵二元樹，使其成為其鏡像。
 * 
 * 時間複雜度：O(n) - 每個節點都必須訪問一次。
 * 空間複雜度：O(h) - h 為樹的高度。遞迴呼叫會消耗棧空間。
 *      - 最壞情況（傾斜樹）：O(n)
 *      - 最好情況（平衡樹）：O(log n)
 * 
 * 解法思路：
 * 這是一個典型的「分治法」與「遞迴」的應用。
 * 1. 基本情況 (Base Case)：如果節點為空，直接回傳 nullptr。
 * 2. 先序操作：交換當前節點的 left 與 right 指標。
 * 3. 遞迴處理：
 *    - 遞迴翻轉左子樹。
 *    - 遞迴翻轉右子樹。
 * 4. 最後回傳根節點。
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // 1. 基底情況：走到葉子節點的下方或樹本身為空
        if (!root) {
            return nullptr;
        }
        // 2. 交換左右子節點 (Pre-order 邏輯)
        std::swap(root->left, root->right);
        // 3. 遞迴地對左右子樹進行同樣的翻轉操作
        invertTree(root->left);
        invertTree(root->right);
        // 4. 回傳目前的根節點
        return root;
    }
};
