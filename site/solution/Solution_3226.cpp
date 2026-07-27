/**
 * 題目：3226. Number of Bit Changes to Make Two Integers Equal (使兩整數相等所需的位元變更次數)
 * 難度：簡單 (Easy)
 * 描述：檢查 k 是否為 n 的位元子集，若是，回傳將 n 變為 k 所需的位元翻轉次數。
 * * 時間複雜度：O(1) - 位元操作在現代 CPU 為常數時間。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 子集檢查：利用位元遮罩 (n & k) == k 快速判斷。
 * 2. 內建函式：使用 __builtin_popcount 直接計算差異位元數量，效能極佳。
 */

class Solution {
public:
    int minChanges(int n, int k) {
        if ((n & k) != k) {
            return -1;
        }
        return __builtin_popcount(n ^ k);
    }
};
