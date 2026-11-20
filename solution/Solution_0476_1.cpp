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
        int bits = bit_width(static_cast<unsigned int>(num));
        long mask = (1u << bits) - 1;
        return static_cast<int>(mask - num);
    }
};