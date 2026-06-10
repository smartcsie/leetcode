/**
 * 題目：1302. Deepest Leaves Sum (層數最深葉節點的和)
 * 難度：中等 (Medium)
 * 描述：返回該二元樹最深層葉節點的和。
 * * 時間複雜度：O(N) - 每個節點只會被訪問一次。
 * 空間複雜度：O(W) - W 為二元樹的最大寬度，佇列中最多同時存放該層節點。
 * * 優化思路：
 * 1. 層序遍歷：利用 BFS 維護每一層的節點。
 * 2. 狀態更新：每一層開始時清空 sum，遍歷結束若該層有葉節點，更新 levelSum。
 */

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q({root});
        int deepestSum = 0;
        while(!q.empty()) {
            int sum = 0;
            for(int i = q.size() -1 ; i >= 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            deepestSum = sum;
        }
        return deepestSum;
    }
};
