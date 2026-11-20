// 題目：1009. Complement of Base 10 Integer
// 難度：Easy
// 時間複雜度：O(1)
// 空間複雜度：O(1)
// 分類主題：bit-manipulation / math
// 技巧：用 bit_width 取得位數，建立位數相同的全 1 遮罩，遮罩減 n 即補數
//       n = 0 要特判（0 的二進位是 "0"，補數為 1）

class Solution {
public:
    int bitwiseComplement(int n) {
        // 特判：n = 0 的二進位是 "0"（1 位），補數是 "1" = 1
        // 若不特判，bit_width(0) = 0 -> mask = 0 -> 回傳 0，答案錯誤
        // 與 476 的差別：這題的 n 可以是 0
        if(n == 0) return 1;

        // bit_width(x) = x 的二進位有效位數（不含前導 0），需要 C++20 <bit>
        // 例：n = 5（101）-> bits = 3；n = 10（1010）-> bits = 4
        // 先轉成 unsigned，因為 bit_width 只接受無號整數
        int bits = bit_width(static_cast<unsigned int>(n));

        // 建立 bits 個 1 的遮罩：(1 << bits) - 1
        // 例：bits = 3 -> 1000 - 1 = 111
        // 用 1L（64 位元）做位移，避免 bits = 31 時 1 << 31 在 int 溢位
        int mask = (1u << bits) - 1;

        // 全 1 減去 n 等於把 n 每個 bit 翻轉（不會借位）
        // 例：111 - 101 = 010；等價於 mask ^ n
        return mask - n;
    }
};