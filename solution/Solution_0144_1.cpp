/**
 * 題目：144. Binary Tree Preorder Traversal
 * 難度：簡單 (Easy)
 * 描述：以前序（根→左→右）遍歷二元樹，回傳節點值序列。
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
