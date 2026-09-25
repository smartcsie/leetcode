/**
 * 題目：671. Second Minimum Node In a Binary Tree (二元樹中第二小的節點)
 * 難度：簡單 (Easy)
 * 描述：找出二元樹中第二小的節點值，若不存在則回傳 -1。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * 1. 根節點最小值：題目定義節點值等於子節點最小值，因此 root->val 必為全域最小值。
 * 2. 剪枝策略：
 * - 若 root->val > minVal，此分支節點大於最小值，可能是第二小候選，無需深入子樹。
 * - 若 root->val == minVal，必須深入子樹尋找是否存在大於 minVal 的值。
 * - 若 root->val > secMin，則該分支不可能找到更小的第二最小值，直接跳過。
 */

class Solution {
private:
    void dfs(TreeNode* root, long& mn1, long& mn2) {
        if(!root) return;
        if(root->val < mn1) {
            mn2 = mn1;
            mn1 = root->val;
        } else if(root->val < mn2 && root->val > mn1) {
            mn2 = root->val;
        }
        dfs(root->left, mn1, mn2);
        dfs(root->right, mn1, mn2);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        long mn1 = LONG_MAX, mn2 = LONG_MAX;
        dfs(root, mn1, mn2);
        return mn2 == LONG_MAX ? -1 : static_cast<int>(mn2);
    }
};