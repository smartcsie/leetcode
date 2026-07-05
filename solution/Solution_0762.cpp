/**
 * 題目：762. Prime Number of Set Bits in Binary Representation
 * 難度：簡單 (Easy)
 * 描述：計算 [left, right] 範圍內，二進位表示中 1 的個數為質數的數字個數。
 * * 優化重點：
 * 1. 位元計數：利用 __builtin_popcount 進行 O(1) 的位元統計。
 * 2. 質數預判：由於整數（最大 10^6）的二進位位數極少，使用硬編碼查表法判斷質數最快。
 */

class Solution {
private:
    // 預判函數：由於整數在 32 位元內，1 的個數最多僅為 32，直接查表最快
    bool isPrime(int n) {
        // 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 均為質數
        return (n == 2 || n == 3 || n == 5 || n == 7 || 
                n == 11 || n == 13 || n == 17 || n == 19 || 
                n == 23 || n == 29 || n == 31);
    }

public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; ++i) {
            // __builtin_popcount 為編譯器內建函數，效能極高
            if (isPrime(__builtin_popcount(i))) {
                count++;
            }
        }
        return count;
    }
};
