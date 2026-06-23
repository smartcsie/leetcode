/**
 * 題目：3945. Digit Frequency Score (數位頻率分數)
 * 難度：簡單 (Easy)
 * 描述：計算數字中各數位之總和或頻率統計。
 * * 時間複雜度：O(log N)，處理數字的位數。
 * 空間複雜度：O(1)，僅使用常數空間。
 * * 優化思路：
 * 1. 簡化分支：若 n 為正整數，直接處理，減少不必要的條件檢查。
 * 2. 效率：使用 `while` 迴圈處理數位提取是標準做法。
 */

class Solution {
public:
    int digitFrequencyScore(int n) {
        int sum = 0;
        // 直接操作 n，無需額外檢查，因為 n <= 0 時迴圈不會執行
        while (n > 0) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
};
