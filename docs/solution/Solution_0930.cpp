/**
 * 題目：930. Binary Subarrays With Sum (和為 goal 的二進位子陣列)
 * 難度：中等 (Medium)
 * 描述：計算陣列中所有和為 goal 的連續子陣列個數。
 * * 時間複雜度：O(N) - 線性遍歷陣列。
 * 空間複雜度：O(N) - 哈希表儲存前綴和狀態。
 * * 優化思路：
 * 1. 使用前綴和技巧：sum[j] - sum[i] = goal => sum[i] = sum[j] - goal。
 * 2. 利用哈希表儲存歷史前綴和的出現頻率，即可快速計算當前位置有多少個子陣列符合條件。
 */

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // 使用 unordered_map 紀錄前綴和出現的頻率
        // Key: 前綴和, Value: 出現次數
        unordered_map<int, int> countMap;
        countMap[0] = 1; // 初始化：前綴和為 0 出現過 1 次
        
        int currentSum = 0;
        int result = 0;
        
        for (int num : nums) {
            currentSum += num;
            
            // 如果存在 (currentSum - goal) 的前綴和，代表找到了目標子陣列
            if (countMap.find(currentSum - goal) != countMap.end()) {
                result += countMap[currentSum - goal];
            }
            
            // 紀錄當前前綴和
            countMap[currentSum]++;
        }
        
        return result;
    }
};
