/**
 * 題目：3770. Largest Prime from Consecutive Prime Sum
 * 難度：中等 (Medium)
 * 描述：在小於等於 n 的範圍內，找出由連續質數相加而成的最大質數。
 * * 時間複雜度：O(MAX_SIZE * log log MAX_SIZE)，預處理後查詢為 O(pi(MAX_SIZE))。
 * 空間複雜度：O(MAX_SIZE)。
 * * 優化思路：
 * 1. 使用 static 變數快取篩選結果，避免多次呼叫時重複運算。
 * 2. 移除錯誤的重複 sieve 調用，確保資料一致性。
 */

class Solution {
private:
    void sieve(int n, vector<int>& primes, vector<char>& isPrime) {
        isPrime.assign(n + 1, 1);
        isPrime[0] = isPrime[1] = 0;
        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p)
                    isPrime[i] = 0;
            }
        }
        for (int i = 2; i <= n; i++)
            if (isPrime[i]) primes.push_back(i);
    }

public:
    int largestPrime(int n) {
        static vector<int> primes;
        static vector<char> isPrime;
        if (isPrime.empty()) {
            sieve(500000, primes, isPrime);  // 只跑一次
        }
        sieve(n, primes, isPrime);

        int ans = 0;
        long long current_sum = 0;
        for (const int& prime : primes) {
            current_sum += prime;
            if (current_sum > n) break;
            if (isPrime[current_sum]) ans = current_sum;
        }
        return ans;
    }
};
