/**
 * 題目：99. Recover Binary Search Tree (恢復二元搜尋樹)
 * 難度：中等 (Medium)
 * 描述：BST 中兩個節點的值被誤交換了，請恢復這棵樹。
 * * 時間複雜度：O(N) - 遍歷整棵樹一次。
 * 空間複雜度：O(1) - 不考慮遞迴深度，僅使用常數空間。
 * * 優化思路：
 * 1. 中序遍歷：在中序遍歷過程中，若 `prev->val > curr->val`，則記錄錯誤位置。
 * 2. 錯誤節點判定：
 * - 第一個錯位點：記錄第一次出現 `prev > curr` 的 `prev`。
 * - 第二個錯位點：記錄最後一次出現 `prev > curr` 的 `curr`。
 */

class Solution {
private:
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;

    void dfs(TreeNode* root) {
        if (!root) return;

        dfs(root->left);

        // 比較當前節點與前一個節點的值
        if (prev && prev->val > root->val) {
            // 第一次發現逆序，first 必為 prev
            if (!first) first = prev;
            // 第二次發現逆序 (或相鄰)，second 必為當前的 root
            second = root;
        }
        prev = root;

        dfs(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        dfs(root);
        // 交換兩處錯誤節點的值
        if (first && second) swap(first->val, second->val);
    }
};
