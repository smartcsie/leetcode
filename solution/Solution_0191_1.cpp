/**
 * 題目：191. Number of 1 Bits
 * 難度：簡單 (Easy)
 * 描述：計算無號整數的二進位表示中 1 的個數（Hamming Weight）。
 *
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （C++20 std::popcount）：
 * 直接使用標準庫函式，對應 CPU 的 POPCNT 指令，最快速的寫法。
 */
class Solution {
public:
    int hammingWeight(int n) {
        return popcount(static_cast<unsigned int>(n));
    }
};