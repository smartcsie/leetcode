/**
 * 題目：235. Lowest Common Ancestor of a Binary Search Tree
 * 難度：中等 (Medium)
 * 描述：找出 BST 中兩個節點的最低公共祖先。
 *
 * 時間複雜度：O(H)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （迭代，利用 BST 性質）：
 * 若 p、q 都小於 root 往左走，都大於往右走，否則 root 就是 LCA。
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(p->val< root->val && q->val < root->val) root = root->left;
            else if(p->val > root->val && q->val > root->val) root = root->right;
            else return root;
        } 
        return nullptr;
    }
};