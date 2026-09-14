/**
 * 題目：958. Check Completeness of a Binary Tree (二元樹的完全性檢驗)
 * 難度：Medium
 * 
 * 時間複雜度：O(N)
 *   - getCount 遍歷所有節點一次：O(N)
 *   - validIndex (DFS) 最多遍歷所有節點一次：O(N)
 *   - 總時間為 O(N)
 * 
 * 空間複雜度：O(H)
 *   - 在完全二元樹的情況下，樹高 H = O(log N)
 *   - 最壞情況 (偏斜樹) 空間可達 O(N)
 * 
 * 解法思路 (DFS / Heap Indexing 堆疊索引法)：
 * 1. 計算總數：先遞迴計算出整棵樹的總節點數 N。
 * 2. 堆疊編號規則 (1-based)：
 *    若父節點編號為 index，則左子節點為 index * 2，右子節點為 index * 2 + 1。
 * 3. 完全二元樹核心性質：
 *    一棵包含 N 個節點的完全二元樹，所有有效節點的編號都必須「小於等於 N」。
 * 4. 驗證機制：
 *    利用 DFS 遍歷給予每個節點編號，若遇到任何節點編號 index > N，
 *    代表前面存在空缺，該樹必不完全。
 */

class Solution {
private:
    int getCount(TreeNode* root) {
        if(!root) return 0;
        return 1 + getCount(root->left) + getCount(root->right);
    }
    bool dfs(TreeNode* root, int count, long long idx) {
        if(!root) return true;
        if(idx > count) return false;
        return dfs(root->left, count, idx * 2) && dfs(root->right, count, idx * 2 + 1);
    }
public:
    bool isCompleteTree(TreeNode* root) {
        int n = getCount(root);
        return dfs(root, n, 1);
    }
};