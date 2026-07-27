/**
 * 題目：228. Summary Ranges (區間彙總)
 * 難度：簡單 (Easy)
 * 描述：將已排序陣列中的連續整數歸納為區間字串。
 * * 時間複雜度：O(N) - 每個元素被遍歷一次。
 * 空間複雜度：O(1) - 不考慮回傳的結果陣列空間。
 * * 優化思路：
 * 1. 遍歷陣列，記錄區間起始點。
 * 2. 持續檢查後續元素是否為當前元素 + 1，若不是則代表區間結束。
 * 3. 處理邊界：若起始點等於終點則只輸單數，反之則輸出 range 格式。
 */

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        const int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int start = nums[i];
            
            // 尋找連續區間的終點
            while (i + 1 < n && (long long)nums[i + 1] - nums[i] == 1) {
                i++;
            }
            
            // 根據區間長度輸出不同格式
            if (start == nums[i]) {
                res.push_back(to_string(start));
            } else {
                res.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
        }
        return res;
    }
};
