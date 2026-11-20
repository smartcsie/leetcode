// 題目：3370. Smallest Number With All Set Bits
// 難度：Easy
// 時間複雜度：O(1)
// 空間複雜度：O(1)
// 分類主題：bit-manipulation / math
// 技巧：用 log2 算出 n 的位數，答案是「位數相同的全 1 數字」(2^bits - 1)

class Solution {
public:
    int smallestNumber(int n) {
        // 找出 >= n 的最小「二進位全是 1」的數字（1、3、7、15、31...）。
        // 這種數字一定是 2^k - 1；而 n 的位數就是能容納它的最小 k。
        // 位數 = floor(log2(n)) + 1
        // 例：n = 5（101）：log2(5) ≈ 2.32 -> 2 + 1 = 3 位
        //     n = 8（1000）：log2(8) = 3 -> 3 + 1 = 4 位
        // 指定給 int 時小數會被捨去（相當於 floor），題目保證 n >= 1，log2 才有意義
        int bits = log2(n) + 1;

        // bits 個 1：(1 << bits) - 1
        // 例：bits = 3 -> 1000 - 1 = 111 = 7（>= 5）
        // 如果 n 本身就是全 1（如 7），bits 仍是 3，回傳 7 自己，符合「>= n」
        // n <= 1000，bits 最多 10，不會溢位
        return (1 << bits) - 1;
    }
};