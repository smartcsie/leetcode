/**
 * 題目：1576. Replace All ?'s to Avoid Consecutive Repeating Characters
 * 難度：簡單 (Easy)
 * 描述：將字串中的 '?' 替換為合法字元，保證相鄰字元不重複。
 * * 優化重點：
 * 1. 簡化邏輯：不需要額外的 `candidate` 函式，直接在迴圈內處理以減少呼叫開銷。
 * 2. 邊界條件：利用 'a', 'b', 'c' 三個字元即可涵蓋所有相鄰衝突，邏輯簡單且保證一定能找到合法字元。
 */

class Solution {
public:
    string modifyString(string s) {
        if(s.size() == 1 && s[0] == '?') {
            s[0] = 'a';
            return s;
        }
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '?') {
                for(char c = 'a'; c <= 'c'; c++) {
                    if(i > 0 && s[i - 1] == c) continue;
                    if(i < s.size() && s[i + 1] == c) continue;
                    s[i] = c;
                    break;
                }
            }
        }
        return s;
    }
};
