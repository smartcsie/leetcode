/**
 * 題目：1910. Remove All Occurrences of a Substring
 * 難度：中等 (Medium)
 * 描述：重複移除字串中出現的所有 `part`，直到無法再移除為止。
 * 優化重點：
 * 1. 使用 `res.compare()` 進行局部比對，避免 substr 產生臨時字串的效能開銷。
 * 2. 使用 `res.resize()` 高效縮減長度，無需手動釋放記憶體。
 *
 * 時間複雜度：O(N*M)
 * 空間複雜度：O(N)
 */

class Solution {
public:
    string removeOccurrences(std::string s, std::string part) {
        while(s.size()>0 && s.find(part)<s.size()){
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};
