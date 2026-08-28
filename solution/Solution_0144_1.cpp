/**
 * 題目：待補充
 * 難度：待補充
 * 描述：待補充
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 */

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    
    stack<TreeNode*> st;
    st.push(root);
    
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        res.push_back(node->val);
        
        // 注意：先壓右子樹，再壓左子樹，這樣彈出的順序才會是 左 -> 右
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return res;
}
