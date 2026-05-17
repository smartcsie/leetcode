/**
 * 題目：222. Count Complete Tree Nodes (完全二元樹的節點個數)
 * 難度：簡單 (Easy)
 * 描述：給你一個「完全二元樹」的根節點 root，求出該樹的節點個數。
 * 
 * 時間複雜度：O(log n * log n) 
 *    - 每次遞迴都會計算高度，耗時 O(log n)。
 *    - 遞迴深度為 O(log n)。
 * 空間複雜度：O(log n) - 遞迴棧的深度。
 * 
 * 解法思路：
 * 1. 利用完全二元樹 (Complete Binary Tree) 的特性。
 * 2. 分別計算根節點向左走到底的高度 (leftHeight) 與向右走到底的高度 (rightHeight)。
 * 3. 判斷：
 *    - 若 leftHeight == rightHeight：說明這是一棵「滿二元樹」，節點數為 (2^height) - 1。
 *    - 若不相等：則回傳 1 + 左子樹節點數 + 右子樹節點數（傳統遞迴）。
 * 4. 由於是完全二元樹，這種方式會大量跳過滿子樹的遍歷，效能遠高於 O(n)。
 */

class Solution {
public:
    int countNodes(TreeNode* root) {
        TreeNode* left = root;
        TreeNode* right = root;
        int leftHeight = 0;
        int rightHeight = 0;

        while(left) {
            leftHeight++;
            left = left->left;
        }

        while(right) {
            rightHeight++;
            right = right->right;
        }

        if(leftHeight == rightHeight) {
            return (1<<leftHeight)-1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
