/**
 * 題目：236. Lowest Common Ancestor of a Binary Tree (二元樹的最近共同祖先)
 * 難度：中等 (Medium)
 * 描述：給定一個二元樹，找到該樹中兩個指定節點 p 和 q 的最近共同祖先 (LCA)。
 *      最近共同祖先的定義為：「對於有根樹 T 的兩個節點 p、q，最近共同祖先表示為一個節點 x，
 *      使得 x 是 p、q 的祖先且 x 的深度盡可能大（一個節點也可以是它自己的祖先）。」
 * 
 * 時間複雜度：O(n) - 最壞情況下需要遍歷樹中的所有節點。
 * 空間複雜度：O(h) - 其中 h 為樹的高度，主要取決於遞迴時系統棧（stack）的深度。
 * 
 * 解法思路：
 * 本題採用後序遍歷（自底向上）的邏輯：
 * 1. 終止條件：
 *    - 若當前節點為空，直接回傳 NULL。
 *    - 若當前節點就是 p 或 q，說明找到了其中一個目標，回傳當前節點給父層。
 * 2. 遞迴過程：
 *    - 去左子樹找尋 p 或 q (存入 left)。
 *    - 去右子樹找尋 p 或 q (存入 right)。
 * 3. 判斷邏輯（回傳規則）：
 *    - 若 left 和 right 都不為空：說明 p 和 q 分別分布在當前節點的左右子樹，
 *      則當前節點就是我們要找的「最近共同祖先」，回傳 root。
 *    - 若 left 為空、right 不為空：說明在左邊沒找到，目標都在右子樹，回傳 right。
 *    - 若 right 為空、left 不為空：說明目標都在左子樹，回傳 left。
 *    - 若皆為空：回傳 NULL。
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right) return root;
        return left ? left : right;;
    }
};
