/**
 * 題目：1685. Sum of Absolute Differences in a Sorted Array
 * 難度：中等 (Medium)
 * 描述：對於每個元素，計算它與陣列中其他所有元素的絕對差值總和。
 * * 時間複雜度：O(N) - 兩次遍歷，一次建立前綴和，一次計算結果。
 * 空間複雜度：O(N) - 用於儲存前綴和陣列。
 * * 優化思路：
 * 1. 拆解絕對值：對於已排序陣列，nums[i] 左側元素皆小於它，右側皆大於它。
 * 2. 數學化簡：
 * 對於 nums[i]，總和 = (左側區間的差值) + (右側區間的差值)
 * = (i * nums[i] - leftSum) + (rightSum - (n - i) * nums[i])
 */

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        
        // 使用 long long 防止累加過程溢位
        vector<long long> prefixSum(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            long long leftSum = prefixSum[i];
            long long rightSum = prefixSum[n] - prefixSum[i + 1];
            
            // 左側部分：(nums[i] - nums[0]) + ... + (nums[i] - nums[i-1])
            // 簡化為：i * nums[i] - leftSum
            long long leftDiff = (long long)i * nums[i] - leftSum;
            
            // 右側部分：(nums[i+1] - nums[i]) + ... + (nums[n-1] - nums[i])
            // 簡化為：rightSum - (n - 1 - i) * nums[i]
            long long rightDiff = rightSum - (long long)(n - 1 - i) * nums[i];
            
            res[i] = (int)(leftDiff + rightDiff);
        }
        
        return res;
    }
};
