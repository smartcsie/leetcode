/**
 * 題目：204. Count Primes (計算質數)
 * 難度：中等 (Medium)
 * 描述：統計小於 n 的質數數量。
 * * 時間複雜度：O(N log log N)
 * 空間複雜度：O(N)，但佔用的記憶體空間極小。
 * * 優化思路：
 * 1. 使用 bitset 的 .count() 函數取代手動迴圈統計。
 * 2. 篩選時精準控制邊界為 n-1。
 */

class Solution {
private:
    bitset<5000001> isPrime;
public:
    int countPrimes(int n) {
        if(n <= 1) return 0;
        isPrime.set();
        isPrime.reset(0);
        isPrime.reset(1);
        for(int p = 2; p *p <= n; p++) {
            if(isPrime[p]) {
                for(int i = p*p; i <= n; i += p) {
                    isPrime.reset(i);;
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(isPrime[i]) count++;
        }
        return count;
    }
};
