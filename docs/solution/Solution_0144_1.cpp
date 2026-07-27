/**
 * 迭代版前序走訪 (使用 Stack)
 * 
 * 時間複雜度：O(n) - 每個節點都會入棧並出棧一次。
 * 空間複雜度：O(h) - h 為樹的高度，Stack 最多儲存節點數量為樹的高度。
 * 
 * 核心邏輯：
 * 1. 利用 Stack 的「後進先出 (LIFO)」特性。
 * 2. 因為前序順序是「根 -> 左 -> 右」，
 *    所以我們在處理完根節點後，必須「先放入右子節點，再放入左子節點」，
 *    這樣下一次從 Stack 取出時，就會先拿到左子節點。
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
