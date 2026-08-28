/**
 * 題目：113. Path Sum II (路徑總和 II)
 * 難度：中等 (Medium)
 * 描述：找出所有從根節點到葉子節點的路徑，其節點值之和等於 targetSum。
 *
 * 時間複雜度：O(N) - 每個節點最多被訪問一次。
 * 空間複雜度：O(H) - H 為樹的高度，用來儲存遞迴堆疊與當前路徑。
 */

class Solution {
private:
    void dfs(TreeNode* root, int targetSum, vector<int>& cur, vector<vector<int>>& ans) {
        if(!root) return;
        cur.push_back(root->val);
        if(!root->left && !root->right && root-> val == targetSum) {
            ans.push_back(cur);
        }
        dfs(root->left, targetSum - root->val, cur, ans);
        dfs(root->right, targetSum - root->val, cur, ans);
        cur.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(root, targetSum, cur, ans);
        return ans;
    }
};
