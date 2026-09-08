/**
 * 註解：待補充
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)

 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == q) return true;
        if(!p || !q || p->val != q->val) return false;
        return isSameTree(p->left , q->left) && isSameTree(p->right , q->right);
    }
};