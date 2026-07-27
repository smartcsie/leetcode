/**
 * 題目：2180. Count Integers With Even Digit Sum
 * 難度：簡單 (Easy)
 * 描述：計算 [1, num] 範圍內，有多少個整數的各數位總和為偶數。
 * 核心概念：
 * - 利用數學規律，避免逐一枚舉整個範圍。
 * - 基準值為 num / 2（整數除法）。
 * - 特殊修正：若 num 為偶數且其數位和為奇數，則需扣 1。
 *
 * 時間複雜度：O(D) - 計算 num 的 digit sum，D 為位數。
 * 空間複雜度：O(1) - 僅使用常數空間。
 */
class Solution {
public:
    int countEven(int num) {
        int digitSum = 0;
        int temp = num;
        while (temp > 0) {
            digitSum += temp % 10;
            temp /= 10;
        }
        int answer = num / 2;
        if (num % 2 == 0 && digitSum % 2 != 0) {
            answer -= 1;
        }
        return answer;
    }
};
