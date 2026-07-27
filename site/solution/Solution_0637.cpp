/**
 * 題目：637. Average of Levels in Binary Tree (二元樹的層平均值)
 * 難度：簡單 (Easy)
 * * 時間複雜度：O(N) - 每個節點被訪問一次。
 * 空間複雜度：O(W) - W 為樹的最大寬度。
 * * 優化重點：
 * 1. 加入 root 空值檢查，避免記憶體存取錯誤。
 * 2. 使用 `double` 進行累加，確保除法時不會發生整數溢位 (Integer Overflow)。
 * 3. 變數命名清晰化，提升程式碼可維護性。
 */

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {}; // 邊界檢查

        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int nodeCount = q.size();
            double levelSum = 0.0;

            for (int i = 0; i < nodeCount; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                levelSum += node->val; // 使用 double 累加避免溢位
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(levelSum / nodeCount);
        }
        return res;
    }
};
