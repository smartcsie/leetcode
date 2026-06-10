/**
 * 題目：917. Reverse Only Letters (反轉僅有的字母)
 * 難度：簡單 (Easy)
 * 描述：在字串中反轉所有英文字母，並保持非字母字元的位置不變。
 * * 時間複雜度：O(N) - 每個字元最多被檢查兩次。
 * 空間複雜度：O(1) - 原地操作，不使用額外容器。
 * * 優化思路：
 * 1. 雙指標：left 從頭開始，right 從尾開始，遇到非字母直接跳過。
 * 2. 標頭函式：使用 isalpha(char) 簡化大小寫判斷。
 */

class Solution {
public:
    string reverseOnlyLetters(string s) {
        if(s.size() == 1) return s;
        int left = 0;
        int right = n -1;
        while(left < right) {
            while(left < right && !isalpha(s[left])) left++;
            while(left < right && !isalpha(s[right])) right--;
            swap(s[left++], s[right--]);
        }
        return s;
    }
};
