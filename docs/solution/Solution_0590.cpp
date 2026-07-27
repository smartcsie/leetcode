class Solution {
public:
    void post(Node* root, vector<int>& res) {
        if(root == nullptr) return;
        for(int i =0; i < root->children.size(); i++) {
            post(root->children[i], res);
        }
        res.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        post(root, res);
        return res;
    }
};