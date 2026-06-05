/**
 * 題目：172. Factorial Trailing Zeroes (階乘後面的零)
 * 難度：中等 (Medium)
 * 描述：計算 n! 結果末尾有多少個零。
 * * 時間複雜度：O(log5 N) - 每次迭代 n 都會除以 5。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 階乘末尾的零由質因子 5 的個數決定。
 * 統計 1 到 n 中有多少個數包含 5 的因子，包含 25 的因子，125 的因子...
 * 也就是計算 `n/5 + n/25 + n/125 + ...`。
 */

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        // 不需使用 log 或 pow，直接不斷除以 5 即可
        // 當 n < 5 時，表示已經沒有因子 5 了
        while (n >= 5) {
            n /= 5;
            count += n;
        }
        return count;
    }
};
