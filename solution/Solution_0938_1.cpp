/**
 * 題目：938. Range Sum of BST
 * 難度：簡單 (Easy)
 * 描述：計算 BST 中所有值在 [low, high] 範圍內的節點值之和。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * （中序 DFS）：
 * 中序遍歷 BST，遇到值在範圍內的節點就累加，利用 BST 性質可剪枝。
 */
class Solution {
private:
    void dfs(TreeNode* root, int low, int high, int& sum) {
        if(!root) return;
        dfs(root->left, low, high, sum);
        if(root->val >= low && root->val <= high)sum += root->val;
        dfs(root->right, low, high, sum);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int sum = 0;
        dfs(root, low, high, sum);
        return sum;
    }
};