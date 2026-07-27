/**
 * 題目：129. Sum Root to Leaf Numbers (求根節點到葉節點數字之和)
 * 難度：中等 (Medium)
 * 描述：計算二元樹中所有從根節點到葉節點的路徑所代表的數字之和。
 * * 時間複雜度：O(N) - N 為節點總數，每個節點訪問一次。
 * 空間複雜度：O(H) - H 為樹的高度，遞迴棧的最大深度。
 * * 優化思路：
 * 1. 使用 DFS 遍歷，每個節點將「當前值 * 10 + 節點值」傳遞給子節點。
 * 2. 傳值 (Pass-by-value) 傳遞 `curSum`，這能自動處理路徑狀態，不需要手動回溯。
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
    void dfs(TreeNode* root, int curSum, int& sum) {
        if (!root) return;
        
        // 將路徑值推進一位並加上當前節點值
        curSum = curSum * 10 + root->val;
        
        // 檢查是否為葉節點
        if (!root->left && !root->right) {
            sum += curSum;
            return;
        }
        
        // 若非葉節點，繼續向下遞迴
        if (root->left) dfs(root->left, curSum, sum);
        if (root->right) dfs(root->right, curSum, sum);
    }

public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
};
