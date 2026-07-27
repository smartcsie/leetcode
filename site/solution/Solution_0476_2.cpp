/**
 * 題目：476. Number Complement (數字補數)
 * 難度：簡單 (Easy)
 * 描述：回傳 num 的二進位補數，不包含高位的前導零。
 * * 時間複雜度：O(log N)，num 的位元數。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 遮罩生成：通過將遮罩右移並填補 1，構造出與 num 位數相同的全 1 遮罩。
 * 2. XOR 運算：直接 XOR 即可得到翻轉後的結果。
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
