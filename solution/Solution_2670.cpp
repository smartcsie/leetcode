/**
 * 題目：2670. Find the Distinct Difference Array
 * 難度：簡單 (Easy)
 * 描述：計算陣列中每個位置的前綴相異數減去後綴相異數的結果。
 * * 優化重點：
 * 1. 雙重預處理：先計算好完整的 prefix 與 suffix 陣列，避免重複計算。
 * 2. Set 操作：利用 unordered_set 的特性快速去重。
 */

class Solution {
public:
    std::vector<int> distinctDifferenceArray(std::vector<int>& nums) {
        int n = nums.size();
        std::unordered_set<int> distincts;
        std::vector<int> prefix(n), suffix(n);
        
        // 計算前綴相異數
        for (int i = 0; i < n; i++) {
            distincts.insert(nums[i]);
            prefix[i] = distincts.size();
        }
        
        // 計算後綴相異數
        distincts.clear();
        for (int i = n - 1; i >= 0; i--) {
            distincts.insert(nums[i]);
            suffix[i] = distincts.size();
        }
        
        // 計算差值
        std::vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int suff_val = (i + 1 < n) ? suffix[i + 1] : 0;
            res[i] = prefix[i] - suff_val;
        }
        
        return res;
    }
};
