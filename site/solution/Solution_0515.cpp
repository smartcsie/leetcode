/**
 * 題目：515. Find Largest Value in Each Tree Row (二元樹每層最大值)
 * 難度：中等 (Medium)
 * 描述：在給定的二元樹中，找出每一層的最大節點值。
 * * 時間複雜度：O(N) - 每個節點被遍歷一次。
 * 空間複雜度：O(W) - W 為樹的最大寬度 (隊列中最多容納的節點數)。
 * * 優化思路：
 * 1. 變數命名：將 max 改為 maxVal 以避免與 std::max 混淆。
 * 2. 結構清晰：使用 levelSize 鎖定當前層節點數量，使 BFS 邏輯更嚴謹。
 */

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        queue<TreeNode*> q({root});
        while(!q.empty()) {
            int max = INT_MIN;
            for(int i = q.size() -1; i >= 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                max = std::max(max, node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(max);
        }
        return res;
    }
};
