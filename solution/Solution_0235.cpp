/**
 * 題目：235. Lowest Common Ancestor of a Binary Search Tree (二元搜尋樹的最近共同祖先)
 * 難度：簡單 (Easy)
 * 描述：給定一個二元搜尋樹 (BST)，找到該樹中兩個指定節點 p 和 q 的最近共同祖先 (LCA)。
 * 
 * 時間複雜度：O(h) - 其中 h 為樹的高度。最壞情況（斜向樹）為 O(n)，平衡情況為 O(log n)。
 * 空間複雜度：O(h) - 遞迴棧的深度。
 * 
 * 解法思路：
 * 1. 利用 BST 的性質：對於任一節點，其左子樹的值都比它小，右子樹的值都比它大。
 * 2. 比較當前節點 root 與 p, q 的值：
 *    - 如果 root->val 同時大於 p->val 和 q->val：
 *      代表 p 和 q 都在 root 的「左子樹」，所以 LCA 一定在左邊，往左遞迴。
 *    - 如果 root->val 同時小於 p->val 和 q->val：
 *      代表 p 和 q 都在 root 的「右子樹」，所以 LCA 一定在右邊，往右遞迴。
 *    - 其他情況 (分叉情況)：
 *      如果 root 的值介於 p 和 q 之間（或是等於其中一個），代表 root 就是分叉點，也就是 LCA。
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root->val > p->val && root->val >  q->val) return lowestCommonAncestor(root->left, p, q);
        if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
