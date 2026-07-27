/**
 * 題目：3618. Split Array by Prime Indices
 * 難度：簡單 (Easy)
 * 描述：根據索引是否為質數，對應的數值執行加法或減法，最終回傳絕對值。
 * * 時間複雜度：O(N + R log log R)，N 為陣列長度，R 為最大索引。
 * 空間複雜度：O(R)，用於儲存質數表。
 * * 優化思路：
 * 1. 使用 vector<bool> 以適應不同大小的 nums，避免 bitset 固定長度的限制。
 * 2. 使用 std::abs 提高語意清晰度。
 */

class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;;
        for(int p = 2; p * p < n;p++) {
            if(isPrime[p]) {
                for(int i = p * p; i < n; i += p) {
                    isPrime[i] = false;
                }
            }
        }
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(isPrime[i]) {
                sum += nums[i];
            } else {
                sum -= nums[i];
            }
        }
        return labs(sum);
    }
};
