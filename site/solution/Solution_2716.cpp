/**
 * 題目：2716. Minimize String Length (最小化字串長度)
 * 難度：簡單 (Easy)
 * 描述：透過選擇兩個索引 i 和 j，若 s[i] == s[j]，可移除其中一個。重複操作直到無法再移除。
 * * 時間複雜度：O(N) - N 為字串長度，遍歷一次即可。
 * 空間複雜度：O(1) - 使用固定大小的 bitset (常數空間)。
 * * 優化思路：
 * 1. 唯一性：題目本質是求「不同字元的數量」。
 * 2. Bit Manipulation：使用 bitset<26> 高效記錄出現過的字元，並直接計算已設位元的總數。
 */

class Solution {
public:
    int minimizedStringLength(string s) {
        bitset<26> bits;
        for(const char& c : s) {
            bits.set(c - 'a');
        }
        return static_cast<int>(bits.count());
    }
};
