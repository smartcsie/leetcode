/**
 * 題目：653. Two Sum IV - Input is a BST (二元搜尋樹中的兩數之和)
 * 難度：簡單 (Easy)
 * 描述：判斷 BST 中是否存在兩節點之和等於給定值 k。
 * * 時間複雜度：O(N) - N 為節點總數，每個節點訪問一次。
 * 空間複雜度：O(N) - 雜湊集儲存節點值的空間。
 * * 優化思路：
 * 利用 Hash Set 記錄已訪問過的節點值。對於每個節點，檢查 (k - node->val) 是否已存在於 Set 中。
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
private:
    // 將 Set 傳遞給輔助函式，避免成員變數造成的狀態污染
    bool dfs(TreeNode* root, int k, unordered_set<int>& seen) {
        if (!root) return false;
        
        // 檢查是否存在補數
        if (seen.count(k - root->val)) return true;
        
        // 將當前值加入 Set
        seen.insert(root->val);
        
        // 遞迴左右子樹
        return dfs(root->left, k, seen) || dfs(root->right, k, seen);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return dfs(root, k, seen);
    }
};
