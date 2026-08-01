/**
 * 題目：5. Longest Palindromic Substring (最長回文子字串)
 * 難度：中等 (Medium)
 * 描述：給定字串 s，回傳 s 中最長的回文子字串。
 *
 * 時間複雜度：O(N²) - 最壞情況下（例如整串都是同一個字元）仍需逐一擴展比對，
 *             但實務上因為跳過連續重複字元與提前剪枝，平均表現通常遠優於此。
 * 空間複雜度：O(1) - 只使用常數個變數，不需額外配置記憶體（不含輸出字串本身）。
 *
 * 解法思路：
 * 1. 提前剪枝，跳過不可能超越目前最佳解的位置 (Early Pruning)：
 *    - 若剩餘字串長度 (n - i) 已經小到不可能產生比目前 max_len 更長的回文
 *      （n - i <= max_len / 2），直接跳出迴圈，不再繼續嘗試。
 * 2. 中心擴展法 (Expand Around Center)：
 *    - 以 i 為起點，先向右擴展跳過所有連續相同字元（例如 "aaa" 直接一次跳到底），
 *      這一步同時處理了奇數長度與偶數長度回文的中心點。
 * 3. 跳過已處理過的重複字元區間 (Skip Duplicate Run)：
 *    - 將外層迴圈的 i 直接跳到 right + 1，避免對同一段連續重複字元重複掃描，
 *      這是這個解法比單純中心擴展法更快的關鍵優化。
 * 4. 左右對稱擴展 (Symmetric Expansion)：
 *    - 從目前的 [left, right] 範圍，持續向左右對稱擴展，
 *      只要兩側字元相同就繼續擴大回文範圍。
 * 5. 更新最佳解：
 *    - 每次擴展完成後，若目前長度大於 max_len，就更新最大長度與起始位置。
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;

        int max_len = 1;
        int start = 0;

        for (int i = 0; i < n; ) {
            if (n - i <= max_len / 2) break;

            int left = i, right = i;
            while (right < n - 1 && s[right + 1] == s[right]) {
                ++right;
            }
            i = right + 1;
            while (left > 0 && right < n - 1 && s[left - 1] == s[right + 1]) {
                --left;
                ++right;
            }
            int curr_len = right - left + 1;
            if (curr_len > max_len) {
                max_len = curr_len;
                start = left;
            }
        }
        return s.substr(start, max_len);
    }
};
