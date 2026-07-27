/**
 * 題目：3174. Clear Digits (清除數字)
 * 難度：簡單 (Easy)
 * 描述：移除字串中的所有數字，且每個數字需同時移除其左側最近的字母。
 * * 時間複雜度：O(N)，僅需遍歷一次字串。
 * 空間複雜度：O(N)，最壞情況下 stack 中會儲存所有字元。
 * * 優化思路：
 * 1. 記憶體預留：使用 `reserve` 預先配置空間，避免動態擴張開銷。
 * 2. 型別安全：直接使用字串作為 stack 操作，減少轉型次數。
 */

class Solution {
public:
    string clearDigits(string s) {
        string res = "";
        for(const char& ch : s) {
            if(isdigit(ch)) {
                if(!s.empty()) {
                  res.pop_back();
                }
            } else  {
                res.push_back(ch);
            }
        }
        return res;
    }
};
