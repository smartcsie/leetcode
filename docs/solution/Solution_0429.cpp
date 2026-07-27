/**
 * 題目：429. N-ary Tree Level Order Traversal (N 叉樹的層序遍歷)
 * 難度：中等 (Medium)
 * 描述：回傳 N 叉樹的層序遍歷結果（以二維陣列形式呈現）。
 * * 時間複雜度：O(N) - 每個節點被訪問且進出 Queue 一次。
 * 空間複雜度：O(W) - W 為最大寬度，即佇列中同時存在的最大節點數。
 * * 優化思路：
 * 1. 使用 `q.size()` 鎖定當前層的節點數量，確保每一層的節點能正確分組。
 * 2. 使用 `reserve` 預先配置記憶體，減少 `vector` 動態擴充的成本。
 */

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            // 預先配置空間避免頻繁記憶體分配
            level.reserve(size); 
            
            for (int i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop();
                
                level.push_back(node->val);
                
                // 將子節點加入佇列
                for (Node* child : node->children) {
                    q.push(child);
                }
            }
            res.push_back(level);
        }
        
        return res;
    }
};
