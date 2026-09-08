/**
 * 題目：49. Group Anagrams
 * 難度：中等 (Medium)
 * 描述：將字串陣列中互為字母異位詞的字串分組。
 *
 * 時間複雜度：O(N*KlogK)
 * 空間複雜度：O(N*K)
 *
 * 解法思路：
 * （排序作為 key）：
 * 將每個字串排序後作為 hash map 的 key，相同 key 的字串歸為同一組。
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for(const string& str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            groups[s].push_back(str);
        }
        vector<vector<string>> res;
        res.reserve(groups.size());
        for(const auto& [key, vec] : groups) {
            res.push_back(vec);
        }
        return res;
    }
};