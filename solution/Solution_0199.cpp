class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q({root});
        while(!q.empty()) {
            res.push_back(q.front()->val);
            for(int i = q.size(); i >0 ; i--) {
                TreeNode* node = q.front();
                q.pop();
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
        }
        return res;
    }
};