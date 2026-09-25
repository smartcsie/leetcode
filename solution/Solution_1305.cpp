/**
 * 題目：1305. All Elements in Two Binary Search Trees
 * 難度：中等 (Medium)
 * 描述：合併兩個 BST 並返回一個升序排序的節點值陣列。
 *
 * 時間複雜度：O(N+M)
 * 空間複雜度：O(N+M)
 *
 * 解法思路：
 * 1. 使用 vector 代替 queue，因為 vector 的存取效率更高。
 * 2. 採用中序遍歷 (In-order) 取得兩個有序序列。
 * 3. 使用雙指針合併兩個有序序列，這與歸併排序的合併步驟完全一致。
 */

class Solution {
private:
    void dfs(TreeNode* root, vector<int>& v) {
        if(!root) return;
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2, ans;
        dfs(root1, v1);
        dfs(root2, v2);
        ans.reserve(v1.size() + v2.size());
        int i = 0, j = 0;
        while(i < v1.size() && j < v2.size()) {
            if(v1[i] < v2[j]) ans.push_back(v1[i++]);
            else ans.push_back(v2[j++]);
        }
        while(i < v1.size()) ans.push_back(v1[i++]);
        while(j < v2.size()) ans.push_back(v2[j++]);
        return ans;
    }
};
