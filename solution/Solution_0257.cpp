/**
 * 題目：257. Binary Tree Paths (二元樹的所有路徑)
 * 難度：簡單 (Easy)
 * 描述：回傳從根節點到所有葉節點的路徑，格式為 "1->2->5"。
 *
 * 時間複雜度：O(N^2)
 * 空間複雜度：O(H^2)
 *
 * 解法思路：
 * 採用引用傳遞 (Reference) 與手動回溯，避免 DFS 過程中不斷複製字串，
 * 顯著減少記憶體分配次數，提升在大規模樹結構下的效能。
 */

class Solution {
private:
    void inorder(TreeNode* root, string path, vector<string>& ans) {
        if(!root) return;
        path += path.empty() ? to_string(root->val) : "->" + to_string(root->val);
        if(!root->left && !root->right) {
            ans.push_back(path);
        }
        inorder(root->left, path, ans);
        inorder(root->right, path, ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        inorder(root, "", ans);
        return ans;
    }
};
