/**
 * 題目：49. Group Anagrams
 * 難度：中等 (Medium)
 * 描述：給定一個字串陣列，將所有字母異位詞（Anagram）分組後回傳。
 *
 * 時間複雜度：O(N*L)
 * 空間複雜度：O(N*L)
 *
 * 解法思路：
 * （字元頻率作為 key 的 Hash Map）：
 * 1. 對每個字串建立長度 26、初始值為 0 的字串作為 key，
 *    key[c - 'a']++ 記錄每個字母出現的次數。
 * 2. 相同字母組成的字串會產生相同的 key，歸入同一個 group。
 * 3. 最後把所有 group 的 vector 收集起來回傳。
 *
 * 與排序法的比較：
 * - 排序法：對每個字串排序作為 key，O(N * L log L)
 * - 此解法：字元頻率作為 key，O(N * L)，不需要排序，更快
 *
 * 注意：
 * key 是長度 26 的字串，內容是 char（非可見字元），
 * 但作為 unordered_map 的 key 完全合法，只要 hash 能處理即可。
 * res.push_back(move(vec)) 用 move 語意避免複製整個 vector。
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string& s : strs) {
            string key(26, 0);
            for (char c : s) key[c - 'a']++;
            groups[key].push_back(s);
        }
        vector<vector<string>> res;
        res.reserve(groups.size());
        for (auto& [key, vec] : groups)
            res.push_back(move(vec));
        return res;
    }
};