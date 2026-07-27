/**
 * 題目：1523. Count Odd Numbers in an Interval Range
 * 難度：簡單 (Easy)
 * 描述：計算給定閉區間 [low, high] 中奇數的個數。
 * * 時間複雜度：O(1) - 直接透過數學公式計算。
 * 空間複雜度：O(1)
 * * 解法思路：
 * 1. 若 low 為偶數，將其加 1 變為區間內的第一個奇數。
 * 2. 若 high 為偶數，將其減 1 變為區間內的最後一個奇數。
 * 3. 調整後的區間 [low, high] 兩端皆為奇數。
 * 4. 奇數個數公式為：((high - low) / 2) + 1。
 */

class Solution {
public:
    int countOdds(int low, int high) {
        if(!(low & 1)) low++;
        if(!(high & 1)) high--;
        return (high - low) / 2 + 1;
    }
};
