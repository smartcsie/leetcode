/**
 * 題目：404. Sum of Left Leaves
 * 難度：Easy
 * 時間複雜度：O(N)
 * 空間複雜度：O(W)，W 為樹的最大寬度（最差 O(N)）
 * 分類主題：tree-bfs-level-order
 *
 * 解法說明：
 * 用 BFS 逐層走訪整棵樹，每個節點在入佇列時一併記錄「自己是不是父節點的左子」。
 * 出佇列時，若該節點是左子且沒有任何子節點（葉子），就把它的值加進總和。
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;

        // 佇列存 (節點, 是否為左子)，因為節點本身不知道自己是左或右，
        // 必須在入佇列時由父節點的角度標記
        queue<pair<TreeNode*, bool>> q;
        q.push({root, false});  // 根節點沒有父節點，不算左子
        int sum = 0;

        while(!q.empty()) {
            // 一次處理完當前這一層（先固定這層的節點數，避免新加入的下一層被混進來）
            // 本題其實不需要分層，這個 for 只是標準的 level-order 寫法
            for(int i = q.size() - 1; i >= 0; i--) {
                auto [node, isLeft] = q.front();
                q.pop();

                // 左葉子的條件：是左子 且 沒有左右子節點
                if(isLeft && !node->left && !node->right)  sum += node->val;

                // 子節點入佇列，順便標記身分：左子 true、右子 false
                if(node->left) q.push({node->left, true});
                if(node->right) q.push({node->right, false});
            }
        }
        return sum;
    }
};