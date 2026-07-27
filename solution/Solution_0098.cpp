class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if(root==nullptr) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        for(int i =0; i < res.size()-1; i++) {
            if(res[i] >= res[i+1]) {
                return false;
            }
        }
        return true;
    }
};