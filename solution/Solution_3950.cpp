/**
 * 題目：3950. Exactly One Consecutive Set Bits Pair (恰好一對連續位元 1)
 * 難度：簡單 (Easy)
 * 描述：判斷整數 n 的二進位中，是否恰好包含一組相鄰的 1 (11)。
 * * 時間複雜度：O(log N)，遍歷所有位元。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 精確控制步進：若題目要求「不重疊的對」，使用 `n >>= 2`；若要求「出現過 11 模式」，需小心處理 `111` 等情況。
 * 2. 位元運算：使用 `(n & 3) == 3` 作為檢測核心。
 */

class Solution {
public:
    bool consecutiveSetBits(int n) {
        int count = 0;
        while(n > 0) {
            if((n & 3) == 3)  {
                count++;
                n >>= 2;
            } else {
                n >>= 1;
            }
        }
        return count == 1;
    }
};
