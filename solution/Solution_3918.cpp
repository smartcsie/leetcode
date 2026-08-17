/**
 * 題目：3918. Sum of Primes Between Number and Its Reverse
 * 難度：中等 (Medium)
 * 描述：計算從 n 到其反轉數字之間的質數總和。
 *
 * 時間複雜度：O(RloglogR)，R 為區間較大值。
 * 空間複雜度：O(R)，篩選表格大小。
 *
 * 解法思路：
 * 1. 使用 vector<bool> 以利用 bit-packing 特性減少記憶體佔用。
 * 2. 篩法範圍僅需開到區間上限，避免不必要的運算。
 */

class Solution {
private:
    bool isPrime(int n) {
        if(n < 2) return false;
        if(n == 2 || n == 3) return true;
        if(n % 2 == 0 || n % 3 == 0) return false;
        for(int i = 5; i * i <= n; i += 6) {
            if(n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }
public:
    int sumOfPrimesInRange(int n) {
        int r = 0;
        int temp = n;
        while(temp > 0) {
            r = r * 10 + temp % 10;
            temp /= 10;
        }
        int sum = 0;
        for(int x = min(n, r); x <= max(n, r); x++) {
            if(isPrime(x)) sum += x;
        }
        return sum;
    }
};
