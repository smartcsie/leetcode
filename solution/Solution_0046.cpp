/**
 * 題目：46. Permutations (全排列)
 * 難度：中等 (Medium)
 * 描述：給定一個不含重複數字的陣列，返回所有可能的全排列。
 * * 時間複雜度：O(N * N!) - 總共有 N! 個排列，每個排列複製需 O(N)。
 * 空間複雜度：O(N) - 遞迴堆疊的深度。
 * * 優化思路：
 * 採用「原地交換 (In-place Swap)」回溯法。在遞迴過程中，不斷交換元素以固定一個位置的數字，
 * 遞迴結束後再次交換還原狀態。這種方式無需 `visited` 陣列，空間效率最高。
 */

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }

private:
    void backtrack(vector<int>& nums, int idx, vector<vector<int>>& res) {
        // 達到終止條件：當索引達到陣列長度時，存入當前排列
        if (idx == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); ++i) {
            // 交換元素：將當前選擇的數字移到固定位置
            std::swap(nums[idx], nums[i]);
            
            // 遞迴：處理下一個位置
            backtrack(nums, idx + 1, res);
            
            // 回溯：交換回來，恢復原陣列狀態，以便嘗試下一個選擇
            std::swap(nums[idx], nums[i]);
        }
    }
};
