/**
 * 題目：3556. Sum of Largest Prime Substrings
 * 難度：中等 (Medium)
 * 描述：在字串 s 中找出所有子字串所代表的質數，並計算前三大相異質數之和。
 * * 時間複雜度：O(N^2 * sqrt(M))，N 為字串長度，M 為子字串代表的數值。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 使用 6k±1 試除法優化質數判斷。
 * 2. 累加生成數字避免 substr() 與 stoll() 的高額開銷。
 * 3. 維護前三大唯一值，確保重複發現的質數不會影響累加結果。
 */

class Solution {
private:
    void updateMax(long long val, long long& m1, long long& m2, long long& m3) {
        if (val == m1 || val == m2 || val == m3) return;
        if (val > m1) { 
            m3 = m2; m2 = m1; m1 = val; 
        } else if (val > m2) { 
            m3 = m2; m2 = val; 
        } else if (val > m3) { 
            m3 = val; 
        }
    }
    bool isPrime(long long n) {
        if(n < 2) return false;
        if(n == 2 || n == 3) return true;
        if(n % 2 == 0 || n % 3 == 0) return false;
        for(long long i = 5; i * i <= n; i += 6) {
            if(n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
public:
    long long sumOfLargestPrimes(string s) {
        long long max1 = 0, max2 = 0, max3 = 0;
        int n = s.size();
        for(int i = 0;i < n; i++) {
            long long curNum = 0;
            for(int j = i;j < n; j++) {
                curNum = curNum * 10 + (s[j] - '0');
                if(isPrime(curNum)) updateMax(curNum, max1, max2, max3);
                if (curNum > 1e10) break;
            }
        }
        return max1 + max2 + max3;
    }
};
