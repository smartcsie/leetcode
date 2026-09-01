/**
 * 題目：3770. Largest Prime from Consecutive Prime Sum
 * 難度：中等 (Medium)
 * 描述：在小於等於 n 的範圍內，找出由連續質數相加而成的最大質數。
 *
 * 時間複雜度：O(max_SIZE*loglogmax_SIZE)
 * 空間複雜度：O(max_SIZE)
 *
 * 解法思路：
 * 1. 使用 static 變數快取篩選結果，避免多次呼叫時重複運算。
 * 2. 移除錯誤的重複 sieve 調用，確保資料一致性。
 */

class Solution {
public:
    int largestPrime(int n) {
        static const int MX = 500000;
        static vector<bool> isPrime;
        static vector<int> primes;

        if (isPrime.empty()) {
            isPrime.assign(MX + 1, true);
            isPrime[0] = isPrime[1] = false;
            for (int p = 2; p * p <= MX; p++) {
                if (isPrime[p]) {
                    for (int i = p * p; i <= MX; i += p)
                        isPrime[i] = false;
                }
            }
            for (int i = 2; i <= MX; i++)
                if (isPrime[i]) primes.push_back(i);
        }

        int ans = 0, current_sum = 0;
        for (int p : primes) {
            if (p > n) break;
            current_sum += p;
            if (current_sum > n) break;
            if (isPrime[current_sum]) ans = current_sum;
        }
        return ans;
    }
};
