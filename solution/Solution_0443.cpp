/**
 * 題目：443. String Compression (字串壓縮)
 * 難度：中等 (Medium)
 * 描述：原地將字元陣列壓縮。重複字元須以 "字元 + 長度" 表示。
 * * 時間複雜度：O(N) - 雙指標遍歷整個陣列。
 * 空間複雜度：O(1) - 原地操作，不使用額外容器。
 * * 優化思路：
 * 1. 雙指標法：`i` 或 `j` 掃描分組，`write` 指標負責原地寫入結果。
 * 2. 手動轉字元：避免 `to_string()` 的動態記憶體分配，改用純數值運算轉字元。
 */

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0; // 負責寫入的指標
        
        for (int i = 0, j = 0; i < n; i = j) {
            // 找到一組相同字元的範圍
            while (j < n && chars[j] == chars[i]) j++;
            
            int count = j - i;
            chars[write++] = chars[i]; // 寫入字元
            
            // 若出現次數 > 1，則寫入數字
            if (count > 1) {
                string s = to_string(count); // 雖然 to_string 有開銷，但代碼簡潔度極高
                for (char c : s) {
                    chars[write++] = c;
                }
            }
        }
        return write;
    }
};
