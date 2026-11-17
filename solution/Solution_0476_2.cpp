// 題目：476. Number Complement
// 難度：Easy
// 時間複雜度：O(1)
// 空間複雜度：O(1)
// 分類主題：bit-manipulation / math
// 技巧：__builtin_clz 計算前導 0 個數 -> 得到位數 -> 全 1 遮罩減 num 即補數

class Solution {
public:
    int findComplement(int num) {
        // __builtin_clz(x)（count leading zeros）：32 位元下 x 的前導 0 個數（GCC／Clang 內建）
        // 位數 = 32 - 前導 0 個數
        // 例：num = 5（00...0101）：前導 0 有 29 個 -> bits = 3
        // 注意 num 不可為 0（clz(0) 未定義），題目保證 num >= 1
        int bits = 32 - __builtin_clz(num);

        // 建立 bits 個 1 的遮罩：(1 << bits) - 1
        // 例：bits = 3 -> 1000 - 1 = 111
        // 用 1L（64 位元）做位移：num 最大 2^31 - 1 時 bits = 31，
        // 若用 int 的 1 << 31 會溢位（C++20 前是未定義行為）
        long mask = (1L << bits) - 1;

        // 全 1 減去 num 等於把 num 每個 bit 翻轉（不會借位）
        // 例：111 - 101 = 010；等價於 mask ^ num
        // 結果一定落在 int 範圍內，轉回 int 回傳
        return static_cast<int>(mask - num);
    }
};