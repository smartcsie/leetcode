/**
 * 題目：3827. Count Monobit Integers
 * 難度：簡單 (Easy)
 * 描述：計算整數 n + 1 的二進位位元寬度。
 * * 優化重點：
 * 1. 標準庫函數：使用 C++20 <bit> 中的 std::bit_width，直接調用 CPU 的位元掃描指令。
 * 2. 類型安全：使用 static_cast<uint32_t> 確保符合位元運算的型別要求。
 */

class Solution {
public:
    int countMonobit(int n) {
        // std::bit_width 返回整數二進位表示中，從最高位 1 到最後一位的總長度
        return std::bit_width(static_cast<uint32_t>(n + 1));
    }
};
