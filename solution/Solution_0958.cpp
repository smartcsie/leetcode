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
 * （BFS + 第一個 null 後不能再有非 null）：
 * 1. BFS 遍歷，把所有節點（含 null 子節點）都推入 queue。
 * 2. 遇到第一個 null 節點時停止推入（while(q.front()) 終止）。
 * 3. 此時 queue 裡剩下的應該全是 null。
 * 4. 清掉連續的 null，若 queue 還有元素代表第一個 null 後面還有非 null 節點。
 *    → 不是完全二元樹，return false。
 * 5. 若 queue 為空，代表所有節點靠左排列，return true。
 *
 * 核心觀察：
 * 完全二元樹的 BFS 序列中，第一個 null 之後不會再出現非 null 節點。
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q({root});
        while(q.front()) {
            TreeNode* node = q.front();
            q.pop();
            q.push(node->left);
            q.push(node->right);
        }
        while(!q.empty() && !q.front()) q.pop();
        return q.empty();
    }
};