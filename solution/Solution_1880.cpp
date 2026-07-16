/**
 * 題目：1880. Check if Word Equals Summation of Two Words
 * 難度：簡單 (Easy)
 * 描述：將每個字母映射為對應的數值 ('a'=0, 'b'=1, ..., 'j'=9)，
 *       判斷 firstWord 的數值與 secondWord 的數值之和，是否等於 targetWord 的數值。
 * 
 * 解法思路：
 * 1. 建立一個輔助函數 `wordToNum`，利用 `ans = ans * 10 + (c - 'a')` 的方式，
 *    將字串依序轉換為對應的整數。
 * 2. 分別計算三個字串的數值。
 * 3. 判斷 `first + second == target` 是否成立。
 */

class Solution {
private:
    int wordToNum(std::string s) {
        int ans = 0;
        for (char c : s) {
            // 將字母轉為 0-9 的數字，並進行位數累加
            ans = ans * 10 + (c - 'a');
        }
        return ans;
    }

public:
    bool isSumEqual(std::string firstWord, std::string secondWord, std::string targetWord) {
        return (wordToNum(firstWord) + wordToNum(secondWord)) == wordToNum(targetWord);
    }
};
