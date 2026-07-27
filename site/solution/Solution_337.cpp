/**
 * 題目：337. House Robber III (打家劫舍 III)
 * 難度：中等 (Medium)
 * 描述：在二元樹結構的房屋中搶劫，相鄰節點不可同時搶劫。
 * * 時間複雜度：O(N) - 每個節點僅訪問一次。
 * 空間複雜度：O(H) - H 為樹的高度 (遞迴深度)。
 * * 優化思路：
 * 1. 狀態封裝：回傳 pair {搶當前節點的收益, 不搶當前節點的收益}。
 * 2. 轉移方程：
 * - rob = val + 左子樹不搶 + 右子樹不搶
 * - noRob = max(左搶, 左不搶) + max(右搶, 右不搶)
 */

class Solution {
public:
    int rob(TreeNode* root) {
        auto [rob, noRob] = dfs(root);
        return max(rob, noRob);
    }

private:
    // 回傳 pair: {含當前節點的最大值, 不含當前節點的最大值}
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        // 遞迴取得子節點狀態
        auto [lRob, lNoRob] = dfs(root->left);
        auto [rRob, rNoRob] = dfs(root->right);

        // 搶當前：必須加上左右子節點「不搶」時的狀態
        int rob = root->val + lNoRob + rNoRob;
        
        // 不搶當前：左右子節點各自取搶與不搶的最大值
        int noRob = max(lRob, lNoRob) + max(rRob, rNoRob);

        return {rob, noRob};
    }
};
