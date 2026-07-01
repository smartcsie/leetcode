/**
 * 題目：3918. Sum of Primes Between Number and Its Reverse
 * 難度：中等 (Medium)
 * 描述：計算從 n 到其反轉數字之間的質數總和。
 * * 時間複雜度：O(R log log R)，R 為區間較大值。
 * 空間複雜度：O(R)，篩選表格大小。
 * * 優化思路：
 * 1. 使用 vector<bool> 以利用 bit-packing 特性減少記憶體佔用。
 * 2. 篩法範圍僅需開到區間上限，避免不必要的運算。
 */

class Solution {
public:
    int sumOfPrimesInRange(int n) {
        int reversed = 0;
        int temp = n;
        while(temp > 0) {
            reversed = reversed * 10 + (temp % 10);
            temp /= 10;
        }
        int left = min(n, reversed);
        int right = max(n, reversed);
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(int p = 2; p * p <= right; p++) {
            if(isPrime[p]) {
                for(int i = p* p; i <= right; i += p) {
                    isPrime[i] = false;
                }
            }
        }
        int sum = 0;
        for(int i = left; i <= right; i++) {
            if(isPrime[i]) {
                sum += i;
            }
        }
        return sum;
    }
};
