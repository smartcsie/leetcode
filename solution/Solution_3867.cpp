/**
 * 題目：3867. Sum of GCD of Formed Pairs
 * 難度：中等 (Medium)
 * 描述：計算陣列中由特定規則形成的配對 GCD 之和。
 * 
 * 解法思路：
 * 1. 計算每個元素 `nums[i]` 與其當前「歷史最大值」的 GCD，形成 `prefixGcd` 陣列。
 * 2. 對 `prefixGcd` 進行排序，將極值兩兩配對。
 * 3. 透過雙指針從兩端向中間收斂進行配對 GCD 計算。
 */

class Solution {
public:
    long long gcdSum(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        std::vector<int> prefixGcd(n);
        int currentMax = 0;
        long long ans = 0;
        
        // 1. 計算各項與歷史最大值的 GCD
        for (int i = 0; i < n; i++) {
            currentMax = std::max(currentMax, nums[i]);
            prefixGcd[i] = std::gcd(currentMax, nums[i]);
        }
        
        // 2. 排序以便進行配對
        std::sort(prefixGcd.begin(), prefixGcd.end());
        
        // 3. 雙指針配對計算總和
        for (int left = 0, right = n - 1; left < right; left++, right--) {
            ans += std::gcd(prefixGcd[left], prefixGcd[right]);
        }
        
        return ans;
    }
};
