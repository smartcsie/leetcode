/*
 * 題目：49. Group Anagrams
 * 難度：Medium
 * 描述：給定字串陣列 strs，把互為字母異位詞（字母組成相同、順序不同）的字串分在同一組，回傳所有分組，組的順序不限。
 * 分類主題：hash-table-mapping
 * 技巧：排序後的字串當 key, 雜湊表分組, reserve 預先配置, move 避免複製
 * 時間複雜度：O(n × k log k)，n 為字串數量，k 為單一字串的最大長度
 * 空間複雜度：O(n × k)（雜湊表與輸出）
 * 解法思路：
 *   1. 互為異位詞的字串，字母排序後會得到同一個字串，因此排序後的字串可以當作分組依據
 *   2. 對每個字串複製一份當 key，排序後放進 unordered_map，原字串加入該 key 對應的 vector
 *   3. 走訪完後，每個 key 對應的 vector 就是一個分組
 *   4. 輸出時先 reserve 群組數量，再用 move 把整個 vector 搬進結果，避免複製所有字串
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // key：排序後的字串；value：所有排序後等於該 key 的原字串
        unordered_map<string, vector<string>> groups;

        for(const string& s : strs) {
            string key = s;
            // 將字串內部字母按字典序排列，作為分組依據
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }

        // 將雜湊表中的所有分組轉存至二維陣列回傳
        vector<vector<string>> result;
        result.reserve(groups.size());  // 預先配置空間，減少記憶體重新分配

        for(auto& pair : groups) {
            result.push_back(move(pair.second));    // 使用 std::move 避免不必要的字串複製
        }

        return result;
    }
};