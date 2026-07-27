/**
 * 題目：559. Maximum Depth of N-ary Tree (N 叉樹的最大深度)
 * 難度：簡單 (Easy)
 * 描述：計算 N 叉樹的最大深度。
 * * 時間複雜度：O(N) - 每個節點被訪問一次。
 * 空間複雜度：O(H) - H 為樹的高度 (遞迴堆疊)。
 * * 優化思路：
 * 將 root->children.empty() 的判斷合併進迴圈邏輯中。
 * 若沒有子節點，迴圈不會執行，depth 保持 0，回傳 0 + 1 = 1，符合葉節點深度。
 */

class Solution {
public:
    int maxDepth(Node* root) {
        // 基本邊界條件
        if (!root) return 0;
        
        int max_child_depth = 0;
        
        // 遍歷所有子節點
        // 如果沒有子節點，迴圈不會執行，max_child_depth 保持 0
        for (Node* child : root->children) {
            max_child_depth = max(max_child_depth, maxDepth(child));
        }
        
        // 返回子節點的最大深度 + 1 (計算當前層)
        return max_child_depth + 1;
    }
};
