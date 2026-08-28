/**
 * 題目：Reverse Prefix of Word (反轉單字前綴)
 * 難度：簡單 (Easy)
 * 描述：給定一個字串 s 和一個字元 ch，反轉從字串開頭到 ch 第一次出現位置之間的字串。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 使用 std::reverse：STL 提供的反轉函數是最佳化過的，直接使用可以降低手寫指標錯誤風險。
 */

class Solution {
public:
    string reversePrefix(string word, char ch) {
        size_t idx = word.find(ch);
        if(idx != string::npos) {
            int left = 0;
            int right = idx;
            while(left < right) swap(word[left++], word[right--]);
        }
        return word;
    }
};
