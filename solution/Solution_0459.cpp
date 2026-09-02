/**
 * 題目：待補充
 * 難度：待補充
 * 描述：待補充
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 字串旋轉與拼接法 (String Slicing Trick)
 * 1. 假設字串 s 是由子字串 t 重複組成 (s = t + t + ... + t)。
 * 2. 如果我們將兩個 s 拼接在一起 (s + s)，那麼在拼接後的字串中，
 * 除去第一個和最後一個字元，中間一定還能完整找回一個原始的 s。
 * 3. 舉例：s = "abcabc"
 * s + s = "abcabcabcabc"
 * 拿掉頭尾後的字串："(b)cabcabcab(c)"
 * 中間依然包含 "abcabc"。
 * 4. 如果 s 不是由重複子字串組成，拼接後拿掉頭尾，則不可能在中間湊出完整的 s。
 */

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        ss.pop_back();
        return ss.find(s, 1) != string::npos;
    }
};
