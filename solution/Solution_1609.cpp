/**
 * 註解：待補充
 */
class Solution {
public:
    
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q({root});
        bool isOdd = true;
        while(!q.empty()) {
            int pre = -1;
            for(int i = q.size() - 1; i >= 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                if((node->val & 1) != isOdd) return false;
                if(pre != -1 && isOdd && pre >= node->val) return false;
                if(pre != -1 && !isOdd && pre <= node->val) return false;
                pre = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            isOdd = !isOdd;
        }
        return true;
    }
};