/**
 * 題目：1753. Maximum Score From Removing Stones
 * 難度：中等 (Medium)
 * 描述：有三堆石頭，每次從兩個不同的堆各取一顆石頭得 1 分，
 * 直到無法操作為止，求最大得分。
 *
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （數學）：
 * 情況一：最大堆 >= 其餘兩堆之和（sum - maxPile）
 *   最大堆無法全部配對，答案為 sum - maxPile。
 *
 * 情況二：最大堆 < 其餘兩堆之和
 *   三堆可以互相配對直到耗盡，答案為 sum / 2。
 *
 * 兩種情況合併：min(sum / 2, sum - maxPile)
 */
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int sum = a + b + c;
        int maxPile = max({a, b, c});
        return min(sum / 2, sum - maxPile);
    }
};