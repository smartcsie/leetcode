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
private:
void getPrimes(int n, vector<bool>& primes) {
    primes[0] = primes[1] = false;
    for(int p = 2; p * p < n; p++) {
        if(primes[p]) {
            for(int i = p * p; i < n; i += p) {
                primes[i] = false;
            }
        }
    }
}
public:
    int countPrimes(int n) {
        if(n < 2) return 0;
        vector<bool> isPrime(n, true);
        getPrimes(n, isPrime);
        return count(isPrime.begin(), isPrime.end(), true);
    }
};
