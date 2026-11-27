/**
 * 題目：129. Sum Root to Leaf Numbers (求根節點到葉節點數字之和)
 * 難度：中等 (Medium)
 * 描述：計算二元樹中所有從根節點到葉節點的路徑所代表的數字之和。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
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
    void dfs(TreeNode* root, long cur, long& sum) {
        if(!root) return;
        cur = 10 * cur + root->val;
        if(!root->left && !root->right) {
            sum += cur;
            return;
        }
        if(root->left) dfs(root->left, cur, sum);
        if(root->right) dfs(root->right, cur, sum);

    }
public:
    int sumNumbers(TreeNode* root) {
        long sum = 0;
        dfs(root, 0, sum);
        return static_cast<int>(sum);
    }
};