/**
 * 題目：144. Binary Tree Preorder Traversal
 * 難度：簡單 (Easy)
 * 描述：以前序（根→左→右）遍歷二元樹，回傳節點值序列。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * （迭代，Morris-like Stack）：
 * 用 stack 模擬遞迴，cur 指向當前節點，向左走時推入 stack，無左子節點時從 stack pop 轉向右子節點。
 */
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