// 題目：476. Number Complement
// 難度：Easy
// 時間複雜度：O(1)
// 空間複雜度：O(1)
// 分類主題：bit-manipulation / math
// 技巧：用「位數相同的全 1 遮罩」減去 num，等同每個 bit 翻轉（補數）
//       bit_width 取得最高位 1 的位置，避免用迴圈逐位找

class Solution {
public:
    int findComplement(int num) {
        // bit_width(x) = x 的二進位有效位數（不含前導 0），需要 C++20 <bit>
        // 例：num = 5（101）-> bits = 3；num = 1（1）-> bits = 1
        // 先轉成 unsigned，因為 bit_width 只接受無號整數
        int bits = bit_width(static_cast<unsigned int>(num));

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