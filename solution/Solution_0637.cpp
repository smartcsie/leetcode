/**
 * 題目：637. Average of Levels in Binary Tree (二元樹的層平均值)
 * 難度：簡單 (Easy)
 * 描述：待補充
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(W)
 */

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q({root});
        vector<double> ans;
        while(!q.empty()) {
            double sum = 0;
            int count = q.size();
            for(int i = q.size() - 1; i >= 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                sum += static_cast<double>(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(sum / count);
        }
        return ans;
    }
};
