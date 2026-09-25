/**
 * 題目：404. Sum of Left Leaves
 * 難度：簡單 (Easy)
 * 描述：計算二元樹中所有左葉節點的值之和。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * （DFS，傳遞 left flag）：
 * 遞迴時傳入 bool left 標記當前節點是否為左子節點，遇到左葉節點時累加。
 */

class Solution {
private:
    void dfs(TreeNode* root, int& sum) {
        if(!root || (!root->left && !root->right)) return;
        if(root->left && !root->left->left && !root->left->right) sum += root->left->val;
        dfs(root->left, sum);
        dfs(root->right, sum);

    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return sum;
    }
};