/**
 * 題目：1952. Three Divisors (三除數)
 * 難度：簡單 (Easy)
 * 描述：判斷 n 是否剛好有三個正因數。
 * * 時間複雜度：O(sqrt(sqrt(N))) 或 O(sqrt(N)) 取決於實現。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 一個數若有剛好 3 個因數，它必須是質數的平方。
 */

class Solution {
public:
    bool isThree(int n) {
        int root = round(sqrt(n));
        
        // 1. n 必須是某個數的平方，且該數必須大於 1
        if (root * root != n || root <= 1) return false;
        
        // 2. 判斷 root 是否為質數
        for (int i = 2; i * i <= root; ++i) {
            if (root % i == 0) return false;
        }
        
        return true;
    }
};
