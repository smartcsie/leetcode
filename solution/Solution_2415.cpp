/**
 * 題目：2415. Reverse Odd Levels of Binary Tree (反轉二元樹的奇數層)
 * 難度：中等 (Medium)
 * 描述：對於一棵完美二元樹，將所有奇數層的節點值進行反轉。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * 1. 同步遍歷：同時傳遞左子樹的 left/right 與右子樹的 right/left，實現層級間的對稱交換。
 * 2. 狀態判斷：當 depth 為奇數時進行交換。
 */

class Solution {
private:
    void dfs(TreeNode* root1, TreeNode* root2, bool isOdd) {
        if(!root1) return;
        if(isOdd) swap(root1->val, root2->val);
        dfs(root1->left, root2->right, !isOdd);
        dfs(root1->right, root2->left, !isOdd);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, true);
        return root;
    }
};
