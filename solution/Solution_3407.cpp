/**
 * 題目：3407. Substring Matching Pattern
 * 難度：簡單 (Easy)
 * 描述：判斷字串 s 是否匹配帶有單一 '*' 萬用字元的模式 p。
 * 優化重點：
 * 1. find API：利用 string::find(str, pos) 指定搜索起點，簡化邏輯。
 * 2. 邊界檢查：利用 string::npos 檢查是否成功匹配。
 *
 * 時間複雜度：O(N+M)
 * 空間複雜度：O(M)
 */

class Solution {
public:
    bool hasMatch(std::string s, std::string p) {
        int starPos = p.find('*');
        string prefix = p.substr(0, starPos);
        string suffix = p.substr(starPos + 1);
        size_t prePos = s.find(prefix);
        if(prePos == string::npos) return false;
        size_t suffPos = s.find(suffix, prePos + prefix.size());
        return suffPos!= string::npos;
    }
};
