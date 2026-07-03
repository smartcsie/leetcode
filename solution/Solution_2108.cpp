**
 * 題目：2108. Find First Palindromic String in the Array
 * 難度：簡單 (Easy)
 * 描述：找出陣列中第一個回文字串。
 * * 優化重點：
 * 1. 將回文檢查邏輯內嵌，減少函式呼叫開銷。
 * 2. 使用 std::equal 搭配 reverse_iterator，達到更簡潔且高效的檢查。
 */

class Solution {
private:
    bool isPalindrome(const string& word) {
        int left = 0;
        int right = word.size() - 1;
        while(left < right) {
            if(word[left++] != word[right--]) return false;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(const string& word : words) {
            if(isPalindrome(word)) return word;
        }
        return "";
    }
};

