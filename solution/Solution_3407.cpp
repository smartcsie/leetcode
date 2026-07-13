/**
 * 題目：3407. Substring Matching Pattern
 * 難度：簡單 (Easy)
 * 描述：判斷字串 s 是否匹配帶有單一 '*' 萬用字元的模式 p。
 * * 優化重點：
 * 1. find API：利用 string::find(str, pos) 指定搜索起點，簡化邏輯。
 * 2. 邊界檢查：利用 string::npos 檢查是否成功匹配。
 */

class Solution {
public:
    bool hasMatch(std::string s, std::string p) {
        // 1. 找到 '*' 的位置
        size_t starPos = p.find('*');
        
        // 2. 分割為 prefix 與 suffix
        std::string prefix = p.substr(0, starPos);
        std::string suffix = p.substr(starPos + 1);
        
        // 3. 在 s 中搜尋 prefix
        size_t prePos = s.find(prefix);
        if (prePos == std::string::npos) return false;
        
        // 4. 在 prefix 之後搜尋 suffix
        // 注意：搜索起點為 prePos + prefix.length()
        size_t sufPos = s.find(suffix, prePos + prefix.size());
        
        return (sufPos != std::string::npos);
    }
};
