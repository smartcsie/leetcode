/**
 * 題目：437. Path Sum III
 * 難度：中等 (Medium)
 * 描述：計算二元樹中路徑總和等於 targetSum 的路徑數量。
 * 優化重點：
 * 1. 前綴和 (Prefix Sum)：使用雜湊表紀錄當前路徑和出現次數，避免重複遍歷。
 * 2. 溢位防護：使用 long long 處理路徑和，避免整數溢位。
 * 3. 回溯 (Backtracking)：離開節點時恢復雜湊表狀態，確保路徑計算準確。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 */

class Solution {
private:
    unordered_map<long long, int> prefix;
    int dfs(TreeNode* root, long long target, long long curSum) {
        if(!root) return 0;
        curSum += root->val;
        int paths = 0;
        if(prefix.count(curSum - target)) {
            paths = prefix[curSum - target];
        }
        prefix[curSum]++;
        paths += dfs(root->left, target, curSum); 
        paths += dfs(root->right, target, curSum); 
        prefix[curSum]--;
        return paths; 
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return dfs(root, (long long)targetSum, 0); 
    }
};