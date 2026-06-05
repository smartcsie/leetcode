/**
 * 題目：476. Number Complement (數字的補數)
 * 難度：簡單 (Easy)
 * 描述：給定一個正整數，將其二進位表示中的所有位元反轉（不包含前導零）。
 * * 時間複雜度：O(log N) - 二進位長度為 log N。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 設計思路：
 * 1. 建立一個與 num 等長的 Mask，其位元皆為 1。
 * 2. num ^ Mask 即為反轉後的結果。
 */

class Solution {
public:
    int findComplement(int num) {
        int mask = ~0;
        while(mask & num) {
            mask <<= 1;
        }
        return ~mask ^ num;
    }
};
