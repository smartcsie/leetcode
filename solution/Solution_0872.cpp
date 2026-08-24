/**
 * 題目：872. Leaf-Similar Trees (葉子相似的樹)
 * 難度：簡單 (Easy)
 * 描述：檢查兩棵樹的葉子節點序列是否相同。
 *
 * 時間複雜度：O(N+M) - N 和 M 為兩棵樹的節點數量。
 * 空間複雜度：O(H1+H2) - 遞迴堆疊深度加上儲存葉子節點的空間。
 *
 * 解法思路：
 * 1. 使用 DFS 遍歷並提取葉子節點。
 * 2. 透過 vector 的賦值比較直接驗證兩序列是否一致。
 */

class Solution {
private:
    void similar(TreeNode* root, vector<int>& leaves) {
        if(!root) return;
        if(!root->left && !root->right) {
            leaves.push_back(root->val);
        }
        similar(root->left, leaves);
        similar(root->right, leaves);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;
        similar(root1, leaves1);
        similar(root2, leaves2);
        return leaves1 == leaves2;
    }
};
