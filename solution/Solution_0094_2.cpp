/**
 * 題目：94. Binary Tree Inorder Traversal (二元樹的中序走訪)
 * 難度：簡單 (Easy)
 * 描述：給定一個二元樹的根節點 root ，返回它的「中序走訪」結果。
 * 順序：左子樹 -> 根節點 -> 右子樹
 * 
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *  - 最壞情況（傾斜樹）：O(N)
 *  - 最好情況（平衡樹）：O(logN)
 * 
 * 解法思路：
 * (迭代法 - 使用 Stack 模擬遞迴)：
 * 1. 使用一個指標 `cur` 從根節點開始，配合 `stack` 記錄拜訪過的節點。
 * 2. 透過內層 while 迴圈：將當前節點及其所有的「左子樹」依序壓入 stack 中，直到 `cur` 為空。
 * 3. 彈出 Stack 頂端的節點（此時代表左子樹已經走到底或處理完畢），將其值加入結果集 `ans` 中。
 * 4. 將 `cur` 指向該節點的「右子樹」，準備進入下一輪迴圈處理右半邊。
 */
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