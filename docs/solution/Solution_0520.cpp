/**
 * 題目：520. Detect Capital (檢測大寫字母)
 * 難度：簡單 (Easy)
 * 描述：判斷一個單字的大小寫格式是否正確（全大寫、全小寫、或僅首字母大寫）。
 * * 時間複雜度：O(N) - 遍歷字串一次。
 * 空間複雜度：O(1) - 僅使用整數計數器。
 * * 優化思路：
 * 將問題抽象為統計字串中大寫字母的數量 (count)：
 * 1. 若 count == 0，代表全小寫（符合）。
 * 2. 若 count == word.size()，代表全大寫（符合）。
 * 3. 若 count == 1 且 word[0] 為大寫，代表僅首字母大寫（符合）。
 */

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for(const char& c : word) {
            if(isupper(c)) count++;
        }
        return (count == 0) || (count == word.size()) || (count == 1 && isupper(word[0]));
    }
};
