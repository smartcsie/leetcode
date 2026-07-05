/**
 * 題目：687. Longest Univalue Path
 * 難度：中等 (Medium)
 * 描述：找到二元樹中具有相同值且相鄰的最長路徑長度（以邊數計算）。
 * * 優化重點：
 * 1. 狀態更新：在後序遍歷中同時更新全局最大值 `res`。
 * 2. 路徑計算：若節點值相同則路徑 +1，否則重置為 0。
 */

class Solution {
private:
    // 回傳值為：以當前節點為起點，向下延伸且符合條件的路徑長度
    int dfs(TreeNode* root, int& maxPath) {
        if (!root) return 0;
        
        int left = dfs(root->left, maxPath);
        int right = dfs(root->right, maxPath);
        
        int arrowLeft = 0, arrowRight = 0;
        
        // 檢查左子樹與當前值是否相同
        if (root->left && root->left->val == root->val) {
            arrowLeft = left + 1;
        }
        
        // 檢查右子樹與當前值是否相同
        if (root->right && root->right->val == root->val) {
            arrowRight = right + 1;
        }
        
        // 更新全局最長路徑 (箭頭連接左右，形成經過根節點的路徑)
        maxPath = std::max(maxPath, arrowLeft + arrowRight);
        
        // 回傳其中較長的一側，給上層節點繼續擴展
        return std::max(arrowLeft, arrowRight);
    }

public:
    int longestUnivaluePath(TreeNode* root) {
        int maxPath = 0;
        dfs(root, maxPath);
        return maxPath;
    }
};
