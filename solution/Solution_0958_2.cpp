/**
 * 題目：958. Check Completeness of a Binary Tree
 * 難度：中等 (Medium)
 * 描述：給定一棵二元樹，判斷它是否為完全二元樹。
 * 完全二元樹定義：除了最後一層外每層都填滿，且最後一層的節點都靠左排列。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （BFS + 節點編號法）：
 * 1. 先計算樹的總節點數 n。
 * 2. 對每個節點編號（根節點為 1，左子節點為 2i，右子節點為 2i+1）。
 * 3. 完全二元樹的性質：所有節點的編號必須在 [1, n] 範圍內。
 * 4. BFS 遍歷時，若任一節點的編號超過 n，代表不是完全二元樹。
 *
 * 節點編號原理：
 * 若編號超過 n，代表該位置前面有空缺，即不符合完全二元樹的靠左排列條件。
 */
class Solution {
private:
    int getCount(TreeNode* root) {
        if (!root) return 0;
        return 1 + getCount(root->left) + getCount(root->right);
    }
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        int n = getCount(root);
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 1});
        while (!q.empty()) {
            for (int i = q.size() - 1; i >= 0; i--) {
                auto [node, idx] = q.front(); q.pop();
                if (idx > n) return false;
                if (node->left)  q.push({node->left,  idx * 2});
                if (node->right) q.push({node->right, idx * 2 + 1});
            }
        }
        return true;
    }
};