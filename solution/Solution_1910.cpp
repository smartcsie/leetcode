/**
 * 題目：1910. Remove All Occurrences of a Substring
 * 難度：中等 (Medium)
 * 描述：重複移除字串中出現的所有 `part`，直到無法再移除為止。
 * * 優化重點：
 * 1. 使用 `res.compare()` 進行局部比對，避免 substr 產生臨時字串的效能開銷。
 * 2. 使用 `res.resize()` 高效縮減長度，無需手動釋放記憶體。
 */

class Solution {
public:
    std::string removeOccurrences(std::string s, std::string part) {
        std::string res;
        // 預分配空間可以減少 push_back 時的記憶體重分配
        res.reserve(s.size());
        
        size_t k = part.size();
        
        for (char c : s) {
            res.push_back(c);
            
            // 當長度足夠時檢查尾部是否匹配 part
            // 使用 compare 方法：compare(pos, len, str)
            if (res.size() >= k && res.compare(res.size() - k, k, part) == 0) {
                res.resize(res.size() - k);
            }
        }
        
        return res;
    }
};
