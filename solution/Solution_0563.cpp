/**
 * 題目：563. Binary Tree Tilt
 * 難度：簡單 (Easy)
 * 描述：計算二元樹所有節點的傾斜度總和，傾斜度定義為左右子樹節點值之和的絕對差。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
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
