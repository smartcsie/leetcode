/**
 * 題目：606. Construct String from Binary Tree (根據二元樹建立字串)
 * 難度：簡單 (Easy)
 * 描述：將二元樹轉換為帶括號的字串，規則是省略所有不影響唯一性的空括號。
 * * 時間複雜度：O(N) - 每個節點訪問一次。
 * 空間複雜度：O(H) - H 為樹的高度 (遞迴堆疊)。
 * * 優化思路：
 * 1. 簡化邏輯：只需判斷「左子樹是否存在」以及「右子樹是否存在」來決定是否加括號。
 */

class Solution {
private:
    void dfs(TreeNode* root, string& res) {
        if(!root) return;
        res += to_string(root->val);
        if(root->left || root->right) {
            res.push_back('(');
            dfs(root->left, res);
            res.push_back(')');
        }
        if(root->right) {
            res.push_back('(');
            dfs(root->right, res);
            res.push_back(')');
        }
        
    }
public:
    string tree2str(TreeNode* root) {
        string res;
        dfs(root, res);
        return res;
    }
};
