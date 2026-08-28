/**
 * 題目：2180. Count Integers With Even Digit Sum
 * 難度：簡單 (Easy)
 * 描述：計算 [1, num] 範圍內，有多少個整數的各數位總和為偶數。
 * 核心概念：
 * - 利用數學規律，避免逐一枚舉整個範圍。
 * - 基準值為 num / 2（整數除法）。
 * - 特殊修正：若 num 為偶數且其數位和為奇數，則需扣 1。
 *
 * 時間複雜度：O(D)
 * 空間複雜度：O(1)
 */
class Solution {
public:
    int countEven(int num) {
        int digitsSum = 0;
        int n = num;
        while(n > 0) {
            digitsSum += n % 10;
            n /= 10;
        }
        return (num - digitsSum % 2) / 2;
    }
};
