/**
 * 題目：633. Sum of Square Numbers (平方數之和)
 * 難度：中等 (Medium)
 * 描述：判斷一個非負整數 c 是否能寫成 a^2 + b^2 的形式。
 * * 時間複雜度：O(sqrt(c)) - 質因數分解的上限。
 * 空間複雜度：O(1) - 使用常數空間。
 * * 優化思路：
 * 費馬平方和定理：一個整數 c 能表示為兩個平方數之和，若且唯若其質因數分解中，
 * 所有形如 4k+3 的質因數的冪次均為偶數。
 */

class Solution {
public:
    bool judgeSquareSum(int c) {
        // 使用 long long 防止計算過程中的溢位 (雖然輸入是 int)
        long long n = c;
        
        // 檢查質因數
        for (long long i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                int exp = 0;
                while (n % i == 0) {
                    n /= i;
                    ++exp;
                }
                // 若質因數形式為 4k+3，則其指數必須為偶數
                if (i % 4 == 3 && exp % 2 != 0) {
                    return false;
                }
            }
        }
        
        // 檢查分解後剩下的質因數 (若剩餘的 n > 1)
        return n % 4 != 3;
    }
};
