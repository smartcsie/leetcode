/**
 * 題目：1952. Three Divisors (恰有三個因數的數字)
 * 難度：簡單 (Easy)
 * 描述：判斷一個數是否恰好有三個正因數。
 *
 * 時間複雜度：O(√N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 因數個數規律：若 n 有三個因數 {1, m, n}，則 n 必為 m^2，且 m 必為質數。
 * 2. 演算法：
 * a. 計算 n 的平方根，並確認 n 是否為完全平方數。
 * b. 檢查該平方根是否為質數。
 */

class Solution {
private:
    bool isPrime(int n) {
        if(n < 2) return false;
        if(n == 2 || n == 3) return true;
        if(n % 2 == 0 || n % 3 == 0) return false; 
        for(int i = 5; i * i <= n; i += 6) {
            if(n % i ==0 || n % (i + 2) == 0) return false;
        }
        return true;
    }
public:
    bool isThree(int n) {
        if (n == 1)
            return false;
        const int root = sqrt(n);
        return root * root == n && isPrime(root);
    }
};
