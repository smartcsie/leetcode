/**
 * 題目：2415. Reverse Odd Levels of Binary Tree (反轉二元樹的奇數層)
 * 難度：中等 (Medium)
 * 描述：對於一棵完美二元樹，將所有奇數層的節點值進行反轉。
 * * 時間複雜度：O(N) - 每個節點訪問一次。
 * 空間複雜度：O(H) - H 為樹的高度 (遞迴堆疊)。
 * * 優化思路：
 * 1. 同步遍歷：同時傳遞左子樹的 left/right 與右子樹的 right/left，實現層級間的對稱交換。
 * 2. 狀態判斷：當 depth 為奇數時進行交換。
 */

class Solution {
private:
    void dfs(TreeNode* left, TreeNode* right, int depth) {
        // 完美二元樹，只要一個為 null，另一個也會為 null
        if (!left) return;

        // 如果是奇數層，直接交換對稱位置的節點值
        if (depth % 2 != 0) {
            swap(left->val, right->val);
        }

        // 遞迴處理下一層：
        // 1. 左子樹的左節點 對應 右子樹的右節點
        // 2. 左子樹的右節點 對應 右子樹的左節點
        dfs(left->left, right->right, depth + 1);
        dfs(left->right, right->left, depth + 1);
    }

public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;
        dfs(root->left, root->right, 1);
        return root;
    }
};
