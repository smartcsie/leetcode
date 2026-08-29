/**
 * 題目：3867. Sum of GCD of Formed Pairs
 * 難度：中等 (Medium)
 * 描述：計算陣列中由特定規則形成的配對 GCD 之和。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 計算每個元素 `nums[i]` 與其當前「歷史最大值」的 GCD，形成 `prefixGcd` 陣列。
 * 2. 對 `prefixGcd` 進行排序，將極值兩兩配對。
 * 3. 透過雙指針從兩端向中間收斂進行配對 GCD 計算。
 */

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> prefix(n);
        int mx= 0;
        long long ans = 0;
        for(int i = 0; i < n ; i++) {
            mx = max(mx, nums[i]);
            prefix[i] = gcd(mx, nums[i]);
        }
        sort(prefix.begin(), prefix.end());
        for(int left = 0, right = n - 1; left < right; left++, right--) {
            ans += gcd(prefix[left], prefix[right]);
        }
        return ans;
    }
};