/**
 * 題目：191. Number of 1 Bits (漢明重量)
 * 難度：簡單 (Easy)
 * 描述：計算一個無符號整數中二進位表示中 1 的個數。
 * * 時間複雜度：O(k)，其中 k 為 1 的個數。
 * 空間複雜度：O(1)
 * * 優化思路：
 * 1. Brian Kernighan's Algorithm：每次執行 `n &= (n - 1)` 會將最右側的一個 1 變為 0。
 * 2. 效率：相較於遍歷 32 位元，此法跳過了所有 0，直接對 1 進行計數。
 */

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n != 0) {
            n &= (n - 1); // 消除最低位的 1
            count++;
        }
        return count;
    }
};
