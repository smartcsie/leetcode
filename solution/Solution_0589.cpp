class Solution {
public:
    void pre(Node* root, vector<int>& res) {
        if(root == nullptr) return;
        res.push_back(root->val);
        for(int i=0; i< root->children.size(); i++) {
            pre(root->children[i], res);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> res;
        pre(root, res);
        return res;
    }
};