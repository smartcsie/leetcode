/**
 * 題目：1869. Longer Contiguous Segments of Ones than Zeros
 * 難度：簡單 (Easy)
 * 描述：判斷字串中，連續 1 的最長段長度是否嚴格大於連續 0 的最長段長度。
 * 
 * 解法思路：
 * 1. 同步遍歷字串，維護當前連續 1 的長度 (ones) 與連續 0 的長度 (zeros)。
 * 2. 遇到目標字元時增加對應計數，否則歸零。
 * 3. 隨時記錄歷史最大值 max_ones 與 max_zeros。
 * 4. 最後回傳 max_ones > max_zeros 的布林結果。
 */

class Solution {
public:
    bool checkZeroOnes(string s) {
        int ones = 0, zeros = 0;
        int max_ones = 0, max_zeros = 0;
        for(const char& c : s) {
            ones = (c & 1) ? ones + 1 : 0;
            max_ones = max(max_ones, ones);
            zeros = !(c & 1) ? zeros + 1 : 0;
            max_zeros = max(max_zeros, zeros);
        }
        return max_ones > max_zeros;
        
    }
};

