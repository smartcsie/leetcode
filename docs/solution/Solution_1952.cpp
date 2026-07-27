/**
 * 題目：1952. Three Divisors (恰有三個因數的數字)
 * 難度：簡單 (Easy)
 * 描述：判斷一個數是否恰好有三個正因數。
 * * 時間複雜度：O(√N) - 嚴格來說是 O(N^(1/4))，因為只對 sqrt(n) 進行素數測試。
 * 空間複雜度：O(1)
 * * 優化思路：
 * 1. 因數個數規律：若 n 有三個因數 {1, m, n}，則 n 必為 m^2，且 m 必為質數。
 * 2. 演算法：
 * a. 計算 n 的平方根，並確認 n 是否為完全平方數。
 * b. 檢查該平方根是否為質數。
 */

class Solution {
public:
    bool isThree(int n) {
        // 因數個數小於 3 的情況：n < 4 (最小具備 3 個因數的數為 4 = 1, 2, 4)
        if (n < 4) return false;
        
        // 取得平方根，並使用 round 確保浮點數轉換的精確度
        int root = static_cast<int>(round(sqrt(n)));
        
        // 1. 確認是否為完全平方數
        if (root * root != n) return false;
        
        // 2. 確認該平方根是否為質數
        return isPrime(root);
    }

private:
    bool isPrime(int num) {
        // 排除非質數情形
        if (num < 2) return false;
        // 使用 O(√M) 檢查質數，其中 M = √N
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }
};
