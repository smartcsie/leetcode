/**
 * 題目：437. Path Sum III
 * 難度：中等 (Medium)
 * 描述：計算二元樹中路徑總和等於 targetSum 的路徑數量。
 * * 優化重點：
 * 1. 前綴和 (Prefix Sum)：使用雜湊表紀錄當前路徑和出現次數，避免重複遍歷。
 * 2. 溢位防護：使用 long long 處理路徑和，避免整數溢位。
 * 3. 回溯 (Backtracking)：離開節點時恢復雜湊表狀態，確保路徑計算準確。
 */

class Solution {
private:
    std::unordered_map<long long, int> prefixSumMap;
    
    int dfs(TreeNode* root, long long target, long long currentSum) {
        if (!root) return 0;
        
        currentSum += root->val;
        int count = 0;
        
        // 檢查是否存在一段路徑滿足條件：currentSum - oldSum == target
        if (prefixSumMap.count(currentSum - target)) {
            count = prefixSumMap[currentSum - target];
        }
        
        // 紀錄當前路徑和，並遞迴子節點
        prefixSumMap[currentSum]++;
        count += dfs(root->left, target, currentSum);
        count += dfs(root->right, target, currentSum);
        
        // 回溯：移除當前節點對路徑和的影響
        prefixSumMap[currentSum]--;
        
        return count;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        // 初始化：路徑和為 0 的出現次數為 1 (表示從根節點起算的路徑)
        prefixSumMap[0] = 1;
        return dfs(root, (long long)targetSum, 0);
    }
};
