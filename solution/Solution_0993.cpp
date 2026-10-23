/**
 * 題目：993. Cousins in Binary Tree (二元樹的堂兄弟節點)
 * 難度：簡單 (Easy)
 * 描述：判斷兩個數值 x 和 y 的節點是否為「堂兄弟」（同一層但父節點不同）。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(W)
 *
 * 解法思路：
 * 1. 結構精簡：統一 BFS 的處理邏輯，並確保在找到兩個節點後立即比對。
 * 2. 變數命名：提高可讀性，明確區分層數與父節點資訊。
 */

/**
 * 題目：993. Cousins in Binary Tree
 * 難度：Easy
 * 時間複雜度：O(N)
 * 空間複雜度：O(W)，W 為樹的最大寬度（最差 O(N)）
 * 分類主題：tree-bfs-level-order
 *
 * 解法說明：
 * 堂兄弟的定義：深度相同，但父節點不同。
 * 用 BFS 逐層走訪，佇列同時記錄每個節點的父節點。
 * 每一層結束後檢查 x、y 的狀況：
 *   - 同層都找到且父節點不同 → 是堂兄弟
 *   - 只有其中一個出現在這層 → 深度不同，不可能是堂兄弟，可提早結束
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;

        // 佇列存 (節點, 父節點)，根節點沒有父節點，用 nullptr 表示
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});

        while(!q.empty()) {
            // 每一層重新記錄 x、y 的父節點，以此判斷是否「同層」
            TreeNode* xParent = nullptr;
            TreeNode* yParent = nullptr;

            // 固定處理這一層的節點數，避免混進下一層的節點
            for(int i = q.size() - 1; i >= 0; i--) {
                auto [node, parent] = q.front();
                q.pop();

                // 找到 x 或 y 時，記下它的父節點
                if(node->val == x) xParent = parent;
                if(node->val == y) yParent = parent;

                // 同一層都找到，且父節點不同 → 滿足堂兄弟條件
                // （父節點相同代表是親兄弟，不算堂兄弟）
                if(xParent && yParent && xParent != yParent) return true;

                // 子節點入佇列，並把當前節點記為它們的父節點
                if(node->left) q.push({node->left, node});
                if(node->right) q.push({node->right, node});
            }

            // 這層結束時只找到其中一個 → 兩者深度不同，不可能是堂兄弟
            if(xParent && !yParent) return false;
            if(!xParent && yParent) return false;
        }

        // 走完整棵樹都沒找到符合條件的組合
        return false;
    }
};