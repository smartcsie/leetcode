/**
 * 解題思路：頻率統計法 (Frequency Counter)
 * 1. Anagram (異位詞) 的定義：兩個字串包含相同的字元，且每個字元出現的次數也相同。
 * 2. 如果兩個字串長度不同，絕對不可能是 Anagram。
 * 3. 由於字元範圍僅限於小寫英文字母 (a-z)，我們可以使用長度為 26 的陣列來代替 Hash Map，效能更高。
 * 4. 遍歷第一個字串 s，增加對應字母的計數；遍歷第二個字串 t，減少對應字母的計數。
 * 5. 最後檢查陣列中所有位置是否都回歸為 0。
 * 
 * Time Complexity: O(n) - 其中 n 是字串長度。
 * Space Complexity: O(1) - 使用了固定長度 (26) 的陣列，與字串長度無關。
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        short count[26];
        for(char c : s) {
            count[c-'a']++;
        }
        for(char c : t) {
            count[c-'a']--;
        }
        for(int i=0; i< 26; i++) {
            if(count[i] != 0) 
                return false;
        }
        return true;
    }
};
