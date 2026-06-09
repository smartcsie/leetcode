/**
 * 題目：671. Second Minimum Node In a Binary Tree (二元樹中第二小的節點)
 * 難度：簡單 (Easy)
 * 描述：找出二元樹中第二小的節點值，若不存在則回傳 -1。
 * * 時間複雜度：O(N) - 最壞情況下遍歷所有節點。
 * 空間複雜度：O(H) - H 為樹的高度 (遞迴堆疊)。
 * * 優化思路：
 * 1. 根節點最小值：題目定義節點值等於子節點最小值，因此 root->val 必為全域最小值。
 * 2. 剪枝策略：
 * - 若 root->val > minVal，此分支節點大於最小值，可能是第二小候選，無需深入子樹。
 * - 若 root->val == minVal，必須深入子樹尋找是否存在大於 minVal 的值。
 * - 若 root->val > secMin，則該分支不可能找到更小的第二最小值，直接跳過。
 */

class Solution {
private:
    long long secMin; // 使用 long long 避免溢位並作為「未找到」的標記

    void dfs(TreeNode* root, int minVal) {
        if (!root) return;

        // 若找到比 minVal 大且比當前 secMin 小的值，更新 secMin
        if (root->val > minVal && root->val < secMin) {
            secMin = root->val;
        } 
        // 只有在當前節點值仍等於最小值時，才需要往子樹尋找
        // 若 root->val > secMin，則無需再遞迴，實現剪枝
        else if (root->val == minVal) {
            dfs(root->left, minVal);
            dfs(root->right, minVal);
        }
    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        
        secMin = LLONG_MAX; // 每次呼叫時重置，保證多執行緒或重複呼叫下的安全性
        dfs(root, root->val);
        
        return (secMin == LLONG_MAX) ? -1 : (int)secMin;
    }
};
