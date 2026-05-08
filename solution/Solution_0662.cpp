class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        int maxWidth = 0;
        while(!q.empty()) {
            int first = q.front().second,last= q.back().second;
            for(int i=q.size(); i > 0; i--){
                unsigned long index=q.front().second;
                TreeNode*node=q.front().first;
                if(node->left) q.push({node->left, 2*index+1});
                if(node->right) q.push({node->right, 2*index+2});
                q.pop();
            }
            maxWidth=max(maxWidth, last - first + 1);
        }
        return maxWidth;
    }
};