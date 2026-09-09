/**
 * 題目：112. Path Sum
 * 難度：簡單 (Easy)
 * 描述：判斷二元樹中是否存在一條從根節點到葉節點的路徑，使得路徑上所有節點值之和等於 targetSum。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * （DFS 遞迴，逐步減去當前節點值）：
 * 每次遞迴將 targetSum 減去當前節點值，到達葉節點時判斷剩餘值是否為 0。
 **/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right && root->val == targetSum) return true;
        return hasPathSum(root->left, targetSum -root->val) || hasPathSum(root->right, targetSum -root->val);
    }
};