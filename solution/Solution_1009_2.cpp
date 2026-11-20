// 題目：1009. Complement of Base 10 Integer
// 難度：Easy
// 時間複雜度：O(1)
// 空間複雜度：O(1)
// 分類主題：bit-manipulation / math
// 技巧：__builtin_clz 計算前導 0 個數 -> 得到位數 -> 全 1 遮罩減 n 即補數
//       n = 0 要特判（0 的二進位是 "0"，補數為 1）

class Solution {
public:
    int bitwiseComplement(int n) {
        // 特判：n = 0 的二進位是 "0"（1 位），補數是 "1" = 1
        // 必須在呼叫 __builtin_clz 前處理，因為 clz(0) 是未定義行為
        if(n == 0) return 1;

        // __builtin_clz(x)（count leading zeros）：32 位元下 x 的前導 0 個數（GCC／Clang 內建）
        // 位數 = 32 - 前導 0 個數
        // 例：n = 5（00...0101）：前導 0 有 29 個 -> bits = 3
        int bits = 32 - __builtin_clz(n);

        // 建立 bits 個 1 的遮罩：(1 << bits) - 1
        // 例：bits = 3 -> 1000 - 1 = 111
        // 用 1L（64 位元）做位移，避免 bits = 31 時 1 << 31 在 int 溢位
        int mask = (1u << bits) - 1;

        // 全 1 減去 n 等於把 n 每個 bit 翻轉（不會借位）
        // 例：111 - 101 = 010；等價於 mask ^ n
        return mask - n;
    }
};