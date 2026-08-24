class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* cur = root;

        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;  // 一路往左走
            }
            cur = st.top();
            st.pop();
            ans.push_back(cur->val);  // 處理節點
            cur = cur->right;         // 轉向右子樹
        }
        return ans;
    }
};