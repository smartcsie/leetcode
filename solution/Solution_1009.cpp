/**
 * 題目：1009. Complement of Base 10 Integer (十進位整數的反碼)
 * 難度：簡單 (Easy)
 * 描述：將整數 n 的二進位表示中的 0 變 1，1 變 0。
 * * 時間複雜度：O(log N) - 取決於 n 的二進位長度。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 1. 使用一個 Mask (遮罩) 填滿與 n 等長的 1。
 * 2. 例如 n = 5 (101)，Mask 為 7 (111)。
 * 3. n ^ Mask 即為反碼 (101 ^ 111 = 010 = 2)。
 * 4. 避免使用 `pow()`，改用位元運算以提升執行效率。
 */

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int mask = 0;
        int temp = n;
        while(temp > 0) {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }
        return n ^ mask;
    }
};
