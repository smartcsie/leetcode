/**
 * 題目：993. Cousins in Binary Tree (二元樹的堂兄弟節點)
 * 難度：簡單 (Easy)
 * 描述：判斷兩個數值 x 和 y 的節點是否為「堂兄弟」（同一層但父節點不同）。
 * * 時間複雜度：O(N) - N 為節點總數。
 * 空間複雜度：O(W) - W 為樹的寬度。
 * * 優化思路：
 * 1. 結構精簡：統一 BFS 的處理邏輯，並確保在找到兩個節點後立即比對。
 * 2. 變數命名：提高可讀性，明確區分層數與父節點資訊。
 */

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({nullptr, root});
        TreeNode *xParent = nullptr, *yParent = nullptr;
        int xDepth = -1, yDepth = -1;
        int depth = 0;
        while(!q.empty()) {
            for(int i = q.size() - 1; i >= 0; i--) {
                auto [parent, node] = q.front();
                q.pop();
                if(node-> val == x) {
                    xParent = parent;
                    xDepth = depth;
                }
                if(node-> val == y) { 
                    yParent = parent;
                    yDepth = depth;
                }
                if(node->left) q.push({node, node->left});
                if(node->right) q.push({node, node->right});
            }
            if(xDepth != -1 && yDepth != -1) {
                return (xParent != yParent) && xDepth == yDepth;
            }
            depth++;
        }
        return false;
    }
};
