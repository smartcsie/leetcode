// 題目：3370. Smallest Number With All Set Bits
// 難度：Easy
// 時間複雜度：O(1)
// 空間複雜度：O(1)
// 分類主題：bit-manipulation / math
// 技巧：__builtin_clz 求出 n 的位數，答案是位數相同的全 1 數字 (2^bits - 1)

class Solution {
public:
    int smallestNumber(int n) {
        // 找出 >= n 的最小「二進位全是 1」的數字（1、3、7、15、31...）。
        // 這種數字一定是 2^k - 1，k 是 n 的二進位位數。
        //
        // __builtin_clz(x)（count leading zeros）：32 位元下 x 的前導 0 個數
        // （GCC／Clang 內建；x 不可為 0，題目保證 n >= 1）
        // 位數 = 32 - 前導 0 個數
        // 例：n = 5（00...0101）：前導 0 有 29 個 -> cnt = 3
        int cnt = 32 - __builtin_clz(n);

        // cnt 個 1：(1 << cnt) - 1
        // 例：cnt = 3 -> 1000 - 1 = 111 = 7（>= 5）
        // 如果 n 本身就是全 1（如 7），cnt 仍是 3，回傳 7 自己，符合「>= n」
        // 這題 n <= 1000，cnt 最多 10，不會溢位
        return (1 << cnt) - 1;
    }
};