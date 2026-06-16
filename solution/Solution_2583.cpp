/**
 * 題目：2583. Kth Largest Sum in a Binary Tree (二元樹中第 K 大的層總和)
 * 難度：中等 (Medium)
 * 描述：計算二元樹每一層的節點總和，並回傳其中第 k 大的總和值。
 * * 時間複雜度：O(N) - N 為節點總數，每層遍歷一次。
 * 空間複雜度：O(M) - M 為樹的寬度，儲存每一層的總和。
 * * 優化思路：
 * 1. 邊界檢查：先判斷層數是否小於 k。
 * 2. 高效查找：使用 nth_element 達到 O(L) 的查找時間（L 為樹的層數）。
 */

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q({root});
        vector<long long> levelSums;
        while(!q.empty()) {
            long long sum = 0;
            for(int i = q.size() - 1 ; i >= 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
            }
            levelSums.push_back(sum);
        }
        if (k > levelSums.size()) return -1;
        auto targeet_pos = levelSums.begin() + levelSums.size() - k;
        nth_element(levelSums.begin(), targeet_pos, levelSums.end());
        return static_cast<long long>(*targeet_pos);
    }
};
