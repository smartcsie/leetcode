/**
 * 題目：94. Binary Tree Inorder Traversal (二元樹的中序走訪)
 * 難度：簡單 (Easy)
 * 描述：順序：左子樹 -> 根節點 -> 右子樹
 * 
 * 時間複雜度：O(n) - 每個節點被入棧與出棧各一次。
 * 空間複雜度：O(h) - 堆疊空間與樹的高度相關。
 * 
 * 解法思路 (迭代)：
 * 1. 使用一個 Stack 來模擬遞迴的呼叫棧。
 * 2. 使用一個指針 `curr` 初始指向 root。
 * 3. 當 `curr` 不為空或堆疊不為空時：
 *    - 如果 `curr` 不為空：說明還有左子樹未遍歷，將 `curr` 入棧，並往左移動。
 *    - 如果 `curr` 為空：說明已經深入到最左側，從堆疊中彈出節點（此為當前根），
 *      訪問該節點，然後將指標轉向其右子樹。
 */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);   
                cur = cur->left;
            } else {
                cur = st.top();  
                st.pop();
                res.push_back(cur->val);
                cur = cur->right;        
            }
        }
        return res;
    }
};
