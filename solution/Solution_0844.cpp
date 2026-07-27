/**
 * 題目：844. Backspace String Compare (退格字串比較)
 * 難度：簡單 (Easy)
 * 描述：比較兩個包含 '#' 的字串處理後是否相等。
 * * 時間複雜度：O(N + M) - 每個字元最多被遍歷一次。
 * 空間複雜度：O(1) - 僅使用常數空間。
 */

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) {
            // 處理 S 的回退邏輯
            while (i >= 0) {
                if (s[i] == '#') { skipS++; i--; }
                else if (skipS > 0) { skipS--; i--; }
                else break;
            }
            // 處理 T 的回退邏輯
            while (j >= 0) {
                if (t[j] == '#') { skipT++; j--; }
                else if (skipT > 0) { skipT--; j--; }
                else break;
            }

            // 比較當前有效的字元
            if (i >= 0 && j >= 0 && s[i] != t[j]) return false;
            
            // 檢查是否一個已經到底，另一個還有字元
            if ((i >= 0) != (j >= 0)) return false;
            
            i--; j--;
        }
        return true;
    }
};
