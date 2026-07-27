/**
 * 題目：918. Maximum Sum Circular Subarray (環形子陣列的最大和)
 * 難度：中等 (Medium)
 * 描述：在環形陣列中找出連續子陣列的最大和。
 * * 時間複雜度：O(N) - 線性掃描一次。
 * 空間複雜度：O(1) - 使用常數空間變數。
 * * 優化思路：
 * 最大和可能出現在：
 * 1. 非環形區間：標準 Kadane 算法 (ans = max(ans, s - pmi))。
 * 2. 環形區間：總和減去中間的最小子陣列和 (s - smi)。
 * 我們維護 `pmi` (前綴最小和) 與 `pmx` (前綴最大和) 來動態推導。
 */

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // 使用一個足夠大的常數，並處理邊界情況
        const int INF = 1e9 + 7;
        
        int pre_min = 0, pre_max = 0;
        int max_sum = -INF, min_sum = INF, total_sum = 0;
        
        for (int x : nums) {
            total_sum += x;
            
            // 處理非環形最大和：當前總和 - 歷史前綴最小和
            max_sum = max(max_sum, total_sum - pre_min);
            // 處理環形最大和所需條件：總和 - (當前總和 - 歷史前綴最大和)
            min_sum = min(min_sum, total_sum - pre_max);
            
            // 更新歷史前綴極值
            pre_min = min(pre_min, total_sum);
            pre_max = max(pre_max, total_sum);
        }
        
        // 特殊情況：如果所有數字皆為負數，max_sum 會是負值，
        // 此時環形計算 (total_sum - min_sum) 會得到 0 (空陣列)，必須排除
        return (max_sum < 0) ? max_sum : max(max_sum, total_sum - min_sum);
    }
};
