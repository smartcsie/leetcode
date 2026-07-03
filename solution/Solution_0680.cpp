/**
 * 題目：680. Valid Palindrome II
 * 難度：簡單 (Easy)
 * 描述：判斷字串是否能透過刪除最多一個字元成為回文。
 * * 優化重點：
 * 1. 使用 `const std::string&` 作為參數傳遞，避免字串拷貝。
 * 2. 邏輯簡潔：在發現第一個不匹配後，分支為兩個子問題，任一成功即可。
 */

class Solution {
private:
    // 輔助函式：標準回文檢查
    bool isPalindrome(const std::string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

public:
    bool validPalindrome(std::string s) {
        int l = 0;
        int r = static_cast<int>(s.length()) - 1;
        
        while (l < r) {
            if (s[l] != s[r]) {
                // 當發現不匹配，只有兩種選擇：跳過左邊，或跳過右邊
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }
            l++;
            r--;
        }
        
        // 字串本身已是回文
        return true;
    }
};
