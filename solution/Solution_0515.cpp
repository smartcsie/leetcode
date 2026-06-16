/**
 * 題目：515. Find Largest Value in Each Tree Row (二元樹每層最大值)
 * 難度：中等 (Medium)
 * 描述：找出二元樹每一層的最大節點值。
 * * 時間複雜度：O(N) - 每個節點遍歷一次。
 * 空間複雜度：O(W) - W 為樹的最大寬度。
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
