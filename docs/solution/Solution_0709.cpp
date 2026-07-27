/**
 * 題目：709. To Lower Case (轉換為小寫字母)
 * 難度：簡單 (Easy)
 * 描述：將字串中的所有大寫字母轉換為小寫。
 * * 時間複雜度：O(N) - 遍歷字串一次。
 * 空間複雜度：O(1) - 原地修改。
 * * 優化思路：
 * 直接利用 ASCII 特性，大寫字母加上 32 (或進行 OR 0x20 位元操作) 
 * 即可變為小寫，這比呼叫 `tolower()` 函式更快，因為省去了檢查 locale 的開銷。
 */

class Solution {
public:
    string toLowerCase(string s) {
        for (char& c : s) {
            // ASCII 中 'A' 是 65 (01000001)，'a' 是 97 (01100001)
            // 將第 6 位元設為 1 (即 OR 32)，即可將大寫轉小寫
            if (c >= 'A' && c <= 'Z') {
                c |= 32; 
            }
        }
        return s;
    }
};
