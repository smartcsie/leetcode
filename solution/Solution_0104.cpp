/**
 * 題目：104. Maximum Depth of Binary Tree
 * 難度：Easy
 * 描述：給定一棵二元樹，找出其最大深度（從根節點到最遠葉節點的最長路徑上的節點數）。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * DFS 遞迴，分別算出左右子樹的最大深度，取兩者較大值再加 1（算上自己這一層）。
 * 遞迴堆疊深度等於樹高 H，最壞情況（鏈狀樹）退化為 O(N)。
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + max(left, right);
    }
};