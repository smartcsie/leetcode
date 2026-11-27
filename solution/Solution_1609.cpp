/**
 * 題目：1609. Even Odd Tree
 * 難度：中等 (Medium)
 * 描述：判斷二元樹是否為 Even-Odd 樹（奇數層嚴格遞增且為奇數，偶數層嚴格遞減且為偶數）。
 * 時間複雜度：O(N)
 * 空間複雜度：O(W)

 */

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q({root});
        bool isOdd = true;
        while(!q.empty()) {
            for(int i = q.size() - 1, prev = 0; i >= 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                if(isOdd ^ (node->val & 1)) return false;
                if(prev && (prev >= node->val) && isOdd) return false;
                if(prev && (prev <= node->val) && !isOdd) return false;
                prev = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            isOdd = !isOdd;
        }
        return true;
    }
};