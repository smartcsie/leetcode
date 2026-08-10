/**
 * 註解：待補充
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q({root});
        vector<int> ans;
        while(!q.empty()) {
            for(int i =q.size() -1; i >= 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                if(i == 0) ans.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ans;
    }
};