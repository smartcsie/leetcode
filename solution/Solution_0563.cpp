/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    // dfs 函數負責回傳該節點的「子樹總和」，並透過 res 累加傾斜度
    int dfs(TreeNode* root, int& res) {
        if (!root) return 0;
        
        int leftSum = dfs(root->left, res);
        int rightSum = dfs(root->right, res);
        
        // 當前節點的 Tilt = 左子樹和 - 右子樹和 的絕對值
        res += std::abs(leftSum - rightSum);
        
        // 回傳以當前節點為根的子樹總和
        return root->val + leftSum + rightSum;
    }

public:
    int findTilt(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};
