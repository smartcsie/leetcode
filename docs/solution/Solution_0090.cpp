/**
 * 題目：90. Subsets II (子集 II)
 * 難度：中等 (Medium)
 * 描述：找出一個可能包含重複整數的陣列的所有可能子集。
 * * 時間複雜度：O(N * 2^N) - 生成所有子集所需的時間。
 * 空間複雜度：O(N) - 遞迴堆疊深度。
 * * 優化思路：
 * 1. 排序：`sort` 是去重的基礎，確保相同的數字相鄰。
 * 2. 剪枝：`i > start && nums[i] == nums[i-1]` 用於確保在同一層遞迴中，
 * 相同的數字只會作為「第一個元素」被選取一次。
 * 3. 預分配：`res.reserve` 減少記憶體頻繁搬移的成本。
 */

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(const vector<int>& nums, int start) {
        res.push_back(path); 
        
        for (int i = start; i < nums.size(); ++i) {
            // 剪枝：若當前元素與前一個相同，且非本次迴圈起點，則跳過
            if (i > start && nums[i] == nums[i - 1]) continue;
            
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back(); 
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        // 優化：預先配置結果容器空間，最大子集數為 2^N
        res.reserve(1 << nums.size());
        
        dfs(nums, 0);
        return res;
    }
};
