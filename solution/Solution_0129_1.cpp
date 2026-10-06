/**
 * 題目：1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 * 難度：簡單 (Easy)
 * 描述：給定一棵原始二元樹 original 和其完整複製版本 cloned，
 * 以及 original 中的一個目標節點 target，找出 cloned 中對應的節點。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * （同步 DFS）：
 * 1. 同時遍歷 original 和 cloned 兩棵樹。
 * 2. 當 original 的當前節點等於 target 時，cloned 的當前節點就是答案。
 * 3. 找到答案後提早終止，不繼續遍歷。
 *
 * 關鍵：兩棵樹結構完全相同，同步走訪保證對應節點位置一致。
 */
class Solution {
private:
    void dfs(TreeNode* t1, TreeNode* t2, TreeNode* target, TreeNode*& ans) {
        if (!t1 || ans) return;    // 空節點或已找到答案，提早終止
        if (t1 == target) { ans = t2; return; }
        dfs(t1->left,  t2->left,  target, ans);
        dfs(t1->right, t2->right, target, ans);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = nullptr;
        dfs(original, cloned, target, ans);
        return ans;
    }
};