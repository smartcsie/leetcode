/**
 * 題目：3084. Count Substrings Starting and Ending with Given Character
 * 難度：簡單 (Easy)
 * 描述：計算以特定字元開頭與結尾的子字串數量。
 * * 時間複雜度：O(N) - N 為字串長度，需遍歷一次以計算頻率。
 * 空間複雜度：O(1)。
 * * 解法思路：
 * 1. 計算目標字元 c 在字串 s 中出現的總次數 freq。
 * 2. 滿足條件的子字串數量等於從 freq 個字元中選出 2 個位置的組合數（包含選同一個位置），即：
 *    - 若選取兩個不同位置：C(freq, 2) = freq * (freq - 1) / 2
 *    - 若選取相同位置：freq
 *    - 總和：freq * (freq - 1) / 2 + freq = freq * (freq + 1) / 2
 */

class Solution {
public:
    long long countSubstrings(std::string s, char c) {
        // 使用 C++20 ranges::count 高效計算出現頻率
        long long freq = std::ranges::count(s, c);
        
        // 使用組合公式 n * (n + 1) / 2
        // 使用 long long 以避免乘法溢位
        return freq * (freq + 1) / 2;
    }
};
