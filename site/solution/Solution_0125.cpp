
/**
 * 題目：125. Valid Palindrome (驗證回文串)
 * 難度：簡單 (Easy)
 * 描述：在考慮所有大寫字元轉換為小寫字元，並移除所有非字母數字字元後，
 *      判斷該字串是否為回文。
 * 
 * 時間複雜度：O(n) - 雖然有兩次遍歷（轉小寫與雙指標），但仍為線性時間。
 * 空間複雜度：O(1) - 在原地修改字串，沒有使用額外的資料結構（若不計輸入字串）。
 * 
 * 解法思路：
 * 1. 預處理：遍歷字串，利用 tolower 將所有字元轉為小寫。
 * 2. 雙指標法：
 *    - left 從頭開始，right 從尾開始。
 *    - 內部使用 while 迴圈跳過非字母數字的字元（isalnum）。
 *    - 比較 left 與 right 的字元，若不等則回傳 false。
 *    - 兩指標向中間移動，直到重合。
 */

class Solution {
public:
    bool isPalindrome(string s) {
        for(char &c : s) {
            c =tolower((unsigned char)c);
        }
        int left = 0;
        int right = s.size() - 1;
        while(left < right) {
            while(left < right && !isalnum(s[left])) left++;
            while(left < right && !isalnum(s[right])) right--;
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
