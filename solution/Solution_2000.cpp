/**
 * 題目：Reverse Prefix of Word (反轉單字前綴)
 * 難度：簡單 (Easy)
 * 描述：給定一個字串 s 和一個字元 ch，反轉從字串開頭到 ch 第一次出現位置之間的字串。
 * * 時間複雜度：O(N) - 字串掃描一次。
 * 空間複雜度：O(1) - 原地修改。
 * * 優化思路：
 * 1. 使用 std::reverse：STL 提供的反轉函數是最佳化過的，直接使用可以降低手寫指標錯誤風險。
 */

class Solution {
public:
    string reversePrefix(string word, char ch) {
        size_t pos = word.find(ch);
        if(pos != std::string::npos) {
            reverse(word.begin(), word.begin() + pos + 1);
        }
        return word;
    }
};
