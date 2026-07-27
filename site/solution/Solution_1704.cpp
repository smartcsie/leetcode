/**
 * 題目：1704. Determine if String Halves Are Alike
 * 難度：簡單 (Easy)
 * 描述：判斷字串前後兩半的母音數量是否相等。
 * * 時間複雜度：O(N) - N 為字串長度，需遍歷兩次（前後半各一次）。
 * 空間複雜度：O(1) - 僅需常數空間檢查母音。
 * * 解法思路：
 * 1. 定義母音檢查函式：利用位元運算，將 'a', 'e', 'i', 'o', 'u' 映射到 26 位元整數中。
 * 2. 使用 `count_if` 對前後兩半字串分別統計母音數量。
 * 3. 比較兩者數量是否相等。
 */

class Solution {
private:
    // 位元遮罩技巧：將 'a'...'u' 對應到整數的特定 bit
    bool isVowel(char c) {
        c = c | 0x20; // 轉為小寫：ASCII 字母 'A'(0x41) 與 'a'(0x61) 位元差為 0x20
        return (2130466 >> (c - 'a' + 1)) & 1;
    }

    int countVowels(std::string s) {
        return std::count_if(s.begin(), s.end(), [&](char c) {
            return isVowel(c);
        });
    }

public:
    bool halvesAreAlike(std::string s) {
        int mid = s.size() / 2;
        return countVowels(s.substr(0, mid)) == countVowels(s.substr(mid));
    }
};
