/**
 * 題目：783. Minimum Distance Between BST Nodes (BST 節點間的最小距離)
 * 難度：簡單 (Easy)
 * 描述：在二元搜尋樹中，找出任意兩個節點值之間的最小差值。
 * * 時間複雜度：O(N) - 每個節點都會被訪問一次。
 * 空間複雜度：O(H) - 樹的高度（遞迴堆疊深度）。
 * * 優化思路：
 * 1. BST 中序遍歷產生的數列必定是單調遞增的。
 * 2. 最小差值必定出現在中序遍歷產生的相鄰節點之間。
 */

class Solution {
public:
    void inorder(TreeNode* root,int& prev ,int& diff) {
        if(!root) return;
        inorder(root->left, prev, diff);
        if(prev != -1) diff = min(diff, root->val - prev);
        prev = root->val;
        inorder(root->right, prev, diff);
    } 
    int minDiffInBST(TreeNode* root) {
        int prev = -1;
        int diff = INT_MAX;
        inorder(root, prev, diff);
        return diff;
    }
};
