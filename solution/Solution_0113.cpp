/**
 * 題目：113. Path Sum II (路徑總和 II)
 * 難度：中等 (Medium)
 * 描述：找出所有從根節點到葉子節點的路徑，其節點值之和等於 targetSum。
 * * 時間複雜度：O(N) - 每個節點最多被訪問一次。
 * 空間複雜度：O(H) - H 為樹的高度，用來儲存遞迴堆疊與當前路徑。
 */

class Solution {
public:
    void dfs(TreeNode* root, int target, vector<int>& path, vector<vector<int>>& res) {
        if (!root) return;
        
        path.push_back(root->val);
        
        // 檢查是否為葉子節點，且滿足條件
        if (!root->left && !root->right && root->val == target) {
            res.push_back(path);
        } else {
            // 若非葉子，繼續深入子節點
            dfs(root->left, target - root->val, path, res);
            dfs(root->right, target - root->val, path, res);
        }
        
        // 回溯：移出當前節點，保持 path 與遞迴層級同步
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, targetSum, path, res);
        return res;
    }
};
