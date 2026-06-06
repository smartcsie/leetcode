/**
 * 題目：47. Permutations II (全排列 II)
 * 難度：中等 (Medium)
 * 描述：給定一個可能含重複數字的陣列，返回所有不重複的全排列。
 * * 時間複雜度：O(N * N!)
 * 空間複雜度：O(N) - 用於標記陣列 (visited) 與遞迴堆疊。
 * * 優化思路：
 * 1. 先對陣列進行排序，將重複元素相鄰。
 * 2. 使用 `visited` 陣列記錄哪些元素已被使用。
 * 3. 關鍵去重邏輯：當前元素與前一個相同 (`nums[i] == nums[i-1]`) 且 
 * 前一個元素未被使用 (`!visited[i-1]`) 時，跳過該分支，防止重複排列生成。
 */

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        
        // 必須先排序，這是去重的前提
        sort(nums.begin(), nums.end());
        
        backtrack(nums, visited, path, res);
        return res;
    }

private:
    void backtrack(vector<int>& nums, vector<bool>& visited, vector<int>& path, vector<vector<int>>& res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // 如果已選過，則跳過
            if (visited[i]) continue;
            
            // 核心去重邏輯：
            // 如果當前元素與前一個元素相同，且前一個元素尚未被選入 path，
            // 代表這會造成重複分支（例如：在第一層迴圈中選取了第二個 '1'，而第一個 '1' 還未被處理過）
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            
            visited[i] = true;
            path.push_back(nums[i]);
            
            backtrack(nums, visited, path, res);
            
            // 回溯：撤銷標記與選擇
            path.pop_back();
            visited[i] = false;
        }
    }
};
