/**
 * 題目：1961. Check If String Is a Prefix of Array
 * 難度：待補充
 * 描述：判斷字串 s 是否為陣列 words 中前 k 個字串連接後形成的字串。
 *
 * 時間複雜度：O(S) - S 為所有 words 字元總和，拼接後與 s 比較前綴。
 * 空間複雜度：O(S) - 拼接字串大小為 S。
 *
 * 解法思路：
 * 1. 宣告一個空字串 sub 來存放累積的結果。
 * 2. 遍歷 words 陣列，將單字逐一加入 sub。
 * 3. 終止條件：當 sub 的長度達到或超過 s 的長度時停止。
 * 4. 比對：檢查最終組成的 sub 是否與 s 完全相等。
 */

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string sub;
        for(int i = 0; i < words.size() && sub.size() < s.size(); i++) {
            sub += words[i];
        }
        return s == sub;
    }
};
