/**
 * 題目：145. Binary Tree Postorder Traversal (二元樹的後序走訪)
 * 難度：簡單 (Easy)
 * 描述：給定一個二元樹的根節點 root，返回它的「後序走訪」結果。
 *      順序：左子樹 -> 右子樹 -> 根節點
 * 
 * 時間複雜度：O(n) - 每個節點都會被訪問且僅被訪問一次。
 * 空間複雜度：O(h) - h 為樹的高度。遞迴棧空間與樹的高度成正比。
 *      - 最壞情況（傾斜樹）：O(n)
 *      - 最好情況（平衡樹）：O(log n)
 * 
 * 解法思路 (遞迴)：
 * 1. 基本情況 (Base Case)：如果當前節點為 nullptr，則直接返回。
 * 2. 遞迴處理左子樹。
 * 3. 遞迴處理右子樹。
 * 4. 最後存入根節點的值，完成「左-右-根」的順序。
 */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<TreeNode*> st({root});
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            res.push_back(cur->val);
            // 為了得到「中->右->左」的順序，所以先壓左，後壓右
            if (cur->left) st.push(cur->left);
            if (cur->right) st.push(cur->right);
        }
        // 將結果反轉即得到「左->右->中」
        reverse(res.begin(), res.end());
        return res;
    }
};
