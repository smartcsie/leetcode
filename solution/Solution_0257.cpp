/**
 * 題目：257. Binary Tree Paths (二元樹的所有路徑)
 * 難度：簡單 (Easy)
 * 描述：回傳從根節點到所有葉節點的路徑，格式為 "1->2->5"。
 * * 時間複雜度：O(N^2) - 每個路徑長度平均為 O(H)，共 N 個節點。
 * 空間複雜度：O(H^2) - 儲存路徑的額外空間。
 * * 優化思路：
 * 採用引用傳遞 (Reference) 與手動回溯，避免 DFS 過程中不斷複製字串，
 * 顯著減少記憶體分配次數，提升在大規模樹結構下的效能。
 */

class Solution {
private:
    void dfs(TreeNode* root, string path, vector<string>& res) {
        if (!root) return;
        // 將當前節點值加入路徑
        path += to_string(root->val);
        // 若為葉節點，將路徑加入結果集
        if (!root->left && !root->right) {
            res.push_back(path);
        } else {
            // 若非葉節點，繼續向下遍歷並加上箭頭
            path += "->";
            dfs(root->left, path, res);
            dfs(root->right, path, res);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
};
