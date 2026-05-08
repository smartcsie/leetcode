class Solution {
public:
    
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q({root});
        int level = 0;
        while(!q.empty()) {
            int prev = -1;
            for(int i = q.size(); i > 0 ; i --) {
                TreeNode* node = q.front();
                q.pop();
                if(level%2 == 0) {
                    if(node->val %2 ==0) {
                        return false;
                    } 
                } else {
                    if(node->val %2 ==1) {
                        return false;
                    } 
                }
                if(prev != -1) {
                    if(level%2 == 0 && prev >= node->val) return false;
                    if(level%2 == 1 && prev <= node->val) return false;
                }
                prev = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level++;
        }
        return true;
    }
};