/**
 * 題目：2256. Minimum Average Difference
 * 難度：中等 (Medium)
 * 描述：找到索引 i，使得前 i+1 個數與後 n-i-1 個數的平均值差最小。
 * * 優化重點：
 * 1. 累加技巧：利用總和動態調整前綴與後綴，避免重複遍歷計算。
 * 2. 型別安全：使用 long long 處理總和，防止數值加總時溢位。
 */

class Solution {
public:
    int minimumAverageDifference(std::vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int minDiff = INT_MAX;
        
        long long prefix = 0;
        // 使用 0L 確保累加過程使用 long long 避免溢位
        long long suffix = std::accumulate(nums.begin(), nums.end(), 0L);
        
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            suffix -= nums[i];
            
            // 計算平均值
            int prefixAvg = prefix / (i + 1);
            int suffixAvg = (i == n - 1) ? 0 : suffix / (n - 1 - i);
            
            int diff = std::abs(prefixAvg - suffixAvg);
            
            // 找到更小的差異時更新
            if (diff < minDiff) {
                res = i;
                minDiff = diff;
            }
        }
        
        return res;
    }
};
