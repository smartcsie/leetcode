/*
 * 題目：2828. Check if a String Is an Acronym of Words
 * 連結：https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/
 * 難度：Easy
 * 分類主題：Array, String
 * 技巧：accumulate 累加字串
 * 描述：給定字串陣列 words 和字串 s，判斷 s 是否為 words 的縮寫
 *       （依序取出每個單字的第一個字元組成的字串是否等於 s）。
 * 時間複雜度：O(N)，N 為 words 中所有字元總數（accumulate 會走訪每個字串一次，
 *            但只取第一個字元，實際上是 O(words.size())）
 * 空間複雜度：O(M)，M 為 s 的長度，用來存放中間組合出的字串 t
 * 解法思路：
 *   1. 先做長度檢查：words 的單字數量必須等於 s 的長度，否則不可能是縮寫，直接回傳 false。
 *   2. 用 accumulate 走訪 words，把每個單字的第一個字元 s[0] 依序 push_back
 *      進一個累加字串 t，最終 t 就是「words 的縮寫」。
 *   3. 比較 t 是否等於 s，相等代表 s 確實是 words 的縮寫。
 */
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        // 縮寫字串長度必須等於單字個數，長度不符直接排除
        if (words.size() != s.size()) return false;

        // 用 accumulate 依序取出每個單字的首字元，組成縮寫字串 t
        // lambda 參數 truncate 為累加中的結果（初始值為空字串 ""）
        string t = accumulate(words.begin(), words.end(), string(""),
            [](string truncate, const string& s) {
                truncate.push_back(s[0]);  // 取當前單字的第一個字元
                return truncate;
            });

        // 比較組合出的縮寫是否與 s 相同
        return t == s;
    }
};