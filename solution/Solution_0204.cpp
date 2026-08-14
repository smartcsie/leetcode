/**
 * 題目：204. Count Primes (計算質數)
 * 難度：中等 (Medium)
 * 描述：統計小於 n 的質數數量。
 *
 * 時間複雜度：O(NloglogN)
 * 空間複雜度：O(N)，但佔用的記憶體空間極小。
 *
 * 解法思路：
 * 1. 使用 bitset 的 .count() 函數取代手動迴圈統計。
 * 2. 篩選時精準控制邊界為 n-1。
 */
class Solution {

public:
    int countPrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(int p = 2; p * p <= n; p++) {
            if(isPrime[p]) {
                for(int i =  p * p; i <= n; i += p) {
                    isPrime[i] = false;
                }
            }
        }
        int ans = 0;
        for(int x = 1; x < n; x++) {
            if(isPrime[x]) ans++;
        }
        return ans;
    }
};