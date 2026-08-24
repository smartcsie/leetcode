class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                ans.push_back(cur->val);
                cur = cur->left;
            } else {
                cur = st.top();  
                st.pop();
                cur = cur->right;        
            }
        }
        return ans;
    }
};