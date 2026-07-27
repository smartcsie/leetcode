/**
 * 題目：451. Sort Characters By Frequency (根據字元出現頻率排序)
 * 難度：中等 (Medium)
 * 描述：根據字元出現的頻率由高到低排序字串。
 * * 時間複雜度：O(N) - N 為字串長度，統計頻率與遍歷桶子皆為線性。
 * 空間複雜度：O(N) - 儲存字元頻率 Map 與桶子空間。
 * * 優化思路：
 * 1. 使用 unordered_map 統計每個字元的頻率。
 * 2. 使用 buckets (vector<string>) 將字元依據頻率進行分組。
 * 3. 從高頻率桶子開始倒序遍歷並拼湊結果，確保最優效能。
 */

class Solution {
public:
    string frequencySort(string s) {
        if (s.empty()) return "";

        // 1. 統計頻率
        unordered_map<char, int> freq;
        int max_freq = 0;
        for (char c : s) {
            max_freq = max(max_freq, ++freq[c]);
        }
        
        // 2. 建立桶子：索引 i 代表出現次數為 i，內容存儲所有出現該次數的字元
        vector<string> buckets(max_freq + 1);
        for (auto const& [ch, count] : freq) {
            buckets[count].push_back(ch);
        }
        
        // 3. 拼湊結果：從最大頻率桶子開始遍歷
        string res;
        res.reserve(s.size()); // 預留空間，避免動態擴容開銷
        
        for (int i = max_freq; i > 0; --i) {
            // 如果該頻率桶子內有字元，依序加入 result
            for (char c : buckets[i]) {
                res.append(i, c); // 將 char c 重複 i 次追加到字串尾端
            }
        }
        
        return res;
    }
};
