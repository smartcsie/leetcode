/**
 * 題目：560. Subarray Sum Equals K (和為 K 的子陣列)
 * 難度：中等 (Medium)
 * 描述：找出陣列中連續子陣列和等於 k 的個數。
 * * 時間複雜度：O(N) - 遍歷陣列一次。
 * 空間複雜度：O(N) - Hash Map 最多儲存 N 個前綴和。
 * * 解法思路：
 * 1. 維護 `curSum` 表示從起點到當前位置的總和。
 * 2. 若存在一個之前的累加和 `prevSum` 使得 `curSum - prevSum == k`，
 * 則該區間的和為 k。即 `prevSum = curSum - k`。
 * 3. 利用 Hash Map 儲存 `prevSum` 出現的頻率，能快速查詢。
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, curSum = 0;
        
        // 使用 unordered_map 儲存前綴和出現的次數
        // 預留空間給 map，減少雜湊擴充的頻率
        unordered_map<int, int> prefixSums;
        prefixSums.reserve(nums.size()); 
        prefixSums[0] = 1;
        
        for (const int num : nums) {
            curSum += num;
            
            // 若 (curSum - k) 存在，則表示找到了區間和為 k 的子陣列
            auto it = prefixSums.find(curSum - k);
            if (it != prefixSums.end()) {
                res += it->second;
            }
            
            // 更新目前前綴和的出現次數
            prefixSums[curSum]++;
        }
        return res;
    }
};
