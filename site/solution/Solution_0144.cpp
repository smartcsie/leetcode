/**
 * 題目：144. Binary Tree Preorder Traversal (二元樹的前序走訪)
 * 難度：簡單 (Easy)
 * 描述：給定一個二元樹的根節點 root ，返回它的「前序走訪」結果。
 *      順序：根節點 -> 左子樹 -> 右子樹
 * 
 * 時間複雜度：O(n) - 每個節點都會被訪問且僅被訪問一次。
 * 空間複雜度：O(h) - h 為樹的高度，遞迴棧空間。最壞情況 O(n)，平均情況 O(log n)。
 */

class Solution {
public:
    void preorder(TreeNode* root, vector<int>& res) {
        if(root == nullptr) return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};
