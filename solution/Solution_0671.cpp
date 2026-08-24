/**
 * 題目：671. Second Minimum Node In a Binary Tree (二元樹中第二小的節點)
 * 難度：簡單 (Easy)
 * 描述：找出二元樹中第二小的節點值，若不存在則回傳 -1。
 *
 * 時間複雜度：O(N) - 最壞情況下遍歷所有節點。
 * 空間複雜度：O(H) - H 為樹的高度 (遞迴堆疊)。
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
    void dfs(TreeNode* root, unordered_set<int>& sets) {
        if(!root) return;
        sets.insert(root->val);
        dfs(root->left, sets);
        dfs(root->right, sets);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        unordered_set<int> sets;
        dfs(root, sets);
        if(sets.size() < 2) return -1;
        long first = LONG_MAX, second = LONG_MAX;
        for(const int& x : sets) {
            if(x < first) {
                second = first;
                first = x;
            } else if(x < second) {
                second = x;
            }
        }
        return second;
    }
};