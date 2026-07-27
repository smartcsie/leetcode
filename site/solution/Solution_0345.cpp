/**
 * 題目：345. Reverse Vowels of a String (反轉字串中的元音字母)
 * 難度：簡單 (Easy)
 * 描述：將字串中的所有元音字母（a, e, i, o, u，不分大小寫）反轉。
 * * 時間複雜度：O(N) - 每個字元最多被訪問一次。
 * 空間複雜度：O(1) - 原地修改字串。
 * * 優化思路：
 * 使用兩個指標分別從頭尾向中間掃描，遇到元音則暫停並交換。
 * 透過字串的 find 方法作為元音表，減少邏輯判斷的複雜度。
 */

class Solution {
private:
    bool isVowel(char ch) {
        return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'
            || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1; 
        while(left < right) {
            while(left < right && !isVowel(s[left])) left++;
            while(left < right && !isVowel(s[right])) right--;
            if(left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};
