/**
 * 題目：2828. Check if a String Is an Acronym of Words (檢查字串是否為單字的首字母縮寫)
 * 難度：簡單 (Easy)
 * 描述：判斷字串 s 是否為陣列 words 中所有單字的首字母組成的縮寫。
 * 
 * 時間複雜度：O(n)，其中 n 為 words 的個數，每個單字只需要存取首字元。
 * 空間複雜度：O(1)，不需要額外的儲存空間。
 * 
 * 解法思路：
 * 1. 若單字數量與縮寫字串長度不相等，直接返回 false。
 * 2. 遍歷 words 陣列，檢查每個單字的第一個字元 (words[i][0]) 是否與 s[i] 相等。
 * 3. 若有任何位置不符，返回 false；否則返回 true。
 */

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        // 優化：縮寫長度必須與單字個數相同
        if (words.size() != s.size()) {
            return false;
        }
        
        // 逐一比對首字母
        for (int i = 0; i < words.size(); i++) {
            if (words[i][0] != s[i]) {
                return false;
            }
        }
        
        return true;
    }
};
