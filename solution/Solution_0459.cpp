/**
 * 解題思路：字串旋轉與拼接法 (String Slicing Trick)
 * 1. 假設字串 s 是由子字串 t 重複組成 (s = t + t + ... + t)。
 * 2. 如果我們將兩個 s 拼接在一起 (s + s)，那麼在拼接後的字串中，
 *    除去第一個和最後一個字元，中間一定還能完整找回一個原始的 s。
 * 3. 舉例：s = "abcabc"
 *    s + s = "abcabcabcabc"
 *    拿掉頭尾後的字串："(b)cabcabcab(c)"
 *    中間依然包含 "abcabc"。
 * 4. 如果 s 不是由重複子字串組成，拼接後拿掉頭尾，則不可能在中間湊出完整的 s。
 * 
 * Time Complexity: O(n) - string::find 的平均複雜度與拼接字串長度成正比。
 * Space Complexity: O(n) - 建立了一個兩倍長度的暫時字串。
 */

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) < s.size();
    }
};
