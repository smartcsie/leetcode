/**
 * 題目：1305. All Elements in Two Binary Search Trees
 * 難度：中等 (Medium)
 * 描述：合併兩個 BST 並返回一個升序排序的節點值陣列。
 * * 時間複雜度：O(N + M) - N 與 M 分別為兩棵樹的節點數。
 * 空間複雜度：O(N + M) - 儲存兩棵樹的中序遍歷結果。
 * * 優化思路：
 * 1. 使用 vector 代替 queue，因為 vector 的存取效率更高。
 * 2. 採用中序遍歷 (In-order) 取得兩個有序序列。
 * 3. 使用雙指針合併兩個有序序列，這與歸併排序的合併步驟完全一致。
 */

class Solution {
private:
    // 將中序遍歷的結果直接存入 vector
    void dfs(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        dfs(root->left, vals);
        vals.push_back(root->val);
        dfs(root->right, vals);
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        dfs(root1, v1);
        dfs(root2, v2);
        
        vector<int> res;
        res.reserve(v1.size() + v2.size()); // 預留空間，提升效能
        
        int i = 0, j = 0;
        // 雙指針合併
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] <= v2[j]) res.push_back(v1[i++]);
            else res.push_back(v2[j++]);
        }
        
        // 加入剩餘元素
        while (i < v1.size()) res.push_back(v1[i++]);
        while (j < v2.size()) res.push_back(v2[j++]);
        
        return res;
    }
};
