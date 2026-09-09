/**
 * 題目：100. Same Tree
 * 難度：簡單 (Easy)
 * 描述：判斷兩棵二元樹是否完全相同（結構相同且對應節點值相同）。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * （DFS 遞迴比較）：
 * 同時遍歷兩棵樹，若當前節點值相同則繼續比較左右子樹，任一不同則回傳 false。
 **/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == q) return true;
        if(!p || !q || p->val != q->val) return false;
        return isSameTree(p->left , q->left) && isSameTree(p->right , q->right);
    }
};