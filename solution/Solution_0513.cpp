/**
 * 題目：513. Find Bottom Left Tree Value (找樹左下角的值)
 * 難度：中等 (Medium)
 * 描述：給定一個二元樹的根節點 root，找出該樹「最後一層」中「最左邊」的節點值。
 * 
 * 時間複雜度：O(n) - 每個節點都會進入隊列並被訪問一次。
 * 空間複雜度：O(w) - w 為樹的最大寬度，隊列中最多同時存儲一層的所有節點。
 * 
 * 解法思路：
 * 1. 使用廣度優先搜索 (BFS / 層序遍歷)。
 * 2. 在進入每一層的 while 迴圈時，該層的第一個節點（即 q.front()）就是該層最左邊的節點。
 * 3. 我們不斷更新 res 為每一層的第一個節點值。
 * 4. 當遍歷結束後，res 儲存的自然就是「最後一層」的「第一個節點值」。
 */

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q({root});
        int res = 0;
        while(!q.empty()) {
            res = q.front()->val;
            for(int i = q.size(); i > 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return res;
    }
};
