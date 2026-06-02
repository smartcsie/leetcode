/**
 * 題目：1161. Maximum Level Sum of a Binary Tree
 * 難度：中等 (Medium)
 * * 優化思路：
 * 1. 使用 BFS 層序遍歷。
 * 2. 在每一層處理時累加 `levelSum`。
 * 3. 即時更新 `maxSum` 與對應的 `minLevel`，無需額外空間存儲與排序。
 */

public:
    int maxLevelSum(TreeNode* root) {
        if(root && !root->left && !root->right) return root->val;
        queue<TreeNode*> q({root});
        int level = 1;
        int maxSum = INT_MIN;
        int minLevel;
        while(!q.empty()) {
            int levelSum = 0;
            for(int i = q.size() - 1; i >= 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(levelSum > maxSum) {
                minLevel = level;
                maxSum = levelSum;
            }
            level++;
        }
        return minLevel;
    }
};
