/**
 * 題目：662. Maximum Width of Binary Tree (二元樹最大寬度)
 * 難度：中等 (Medium)
 * 描述：給定一棵二元樹，回傳其最大寬度。
 *       寬度定義為每層最左節點到最右節點之間的長度（含兩端點及中間的 null 節點）。
 *
 * 時間複雜度：O(N) - 每個節點只拜訪一次。
 * 空間複雜度：O(N) - BFS queue 最多同時存放一層的節點數。
 *
 * 解法思路：
 * 1. BFS 層序遍歷，每個節點額外記錄編號 (index)：
 *    - 根節點編號為 0
 *    - 左子節點編號 = 父節點編號 * 2 + 1
 *    - 右子節點編號 = 父節點編號 * 2 + 2
 * 2. 每層寬度 = 最右節點編號 - 最左節點編號 + 1。
 * 3. 偏移處理 (idx -= first)：
 *    - 每層處理時將編號減去該層最左節點的編號，
 *      使每層從 0 開始重新計算相對位置，
 *      避免樹很深時編號指數成長導致溢位。
 */

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, unsigned long>> q;
        q.push({root, 0});
        unsigned long maxWidth = 0;
        while(!q.empty()) {
            unsigned long first = q.front().second;
            unsigned long last = q.back().second;
            maxWidth = max(maxWidth, last - first + 1);
            for(int i = q.size() - 1; i>= 0; i--) {
                TreeNode* node = q.front().first;
                unsigned long idx = q.front().second;
                q.pop();
                if(node->left) q.push({node->left, idx * 2 + 1});
                if(node->right) q.push({node->right, idx * 2 + 2});
            }
        }
        return static_cast<int>(maxWidth);
    }
};