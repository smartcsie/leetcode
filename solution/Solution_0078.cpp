/**
 * 題目：78. Subsets (子集)
 * 難度：中等 (Medium)
 * 描述：找出一個整數陣列的所有可能子集 (冪集)。
 * * 時間複雜度：O(N * 2^N) - 共有 2^N 個子集，每個子集平均長度為 N。
 * 空間複雜度：O(N) - 遞迴堆疊深度為 N。
 * * 優化思路：
 * 1. 預分配記憶體：子集總數為 2^N，若 N=10，則有 1024 個子集，預先 reserve 可避免多次重分配。
 * 2. 傳遞參數優化：使用 `const vector<int>&` 避免參數拷貝。
 */

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(const vector<int>& nums, int start) {
        res.push_back(path); 
        
        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            dfs(nums, i + 1);    
            path.pop_back();     // 回溯
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 優化：預先配置結果容器空間，2^N 為子集總數
        // 假設 nums.size() = n，則總數為 1 << n
        res.reserve(1 << nums.size());
        dfs(nums, 0);
        return res;
    }
};
