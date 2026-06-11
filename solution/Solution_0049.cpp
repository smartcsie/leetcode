/**
 * 題目：49. Group Anagrams (字母異位詞分組)
 * 難度：中等 (Medium)
 * 描述：給定一個字串陣列，將所有互為字母異位詞的字串分組在一起。
 * * 時間複雜度：O(N * K) - N 為字串數量，K 為平均字串長度。
 * 空間複雜度：O(N * K) - 用於儲存分組後的結果。
 * * 優化思路：
 * 1. 頻率陣列：利用 `array<int, 26>` 作為 Key，直接對應字母出現次數，避免排序的時間成本 O(K log K)。
 * 2. 轉移語意：使用 `std::move` 減少字串陣列的拷貝。
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 使用 map 以 array<int, 26> 為鍵，記錄每個字母出現的頻率分佈
        map<array<int, 26>, vector<string>> groups;
        
        for (const string& s : strs) {
            array<int, 26> count = {0};
            for (char c : s) {
                count[c - 'a']++;
            }
            groups[count].push_back(s);
        }
        
        vector<vector<string>> res;
        res.reserve(groups.size()); // 預先分配空間避免擴容
        
        for (auto& [key, vec] : groups) {
            // 使用 std::move 避免複製整個 vector，提升效率
            res.push_back(std::move(vec));
        }
        
        return res;
    }
};
