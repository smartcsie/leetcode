**
 * 題目：1170. Compare Strings by Frequency of the Smallest Character
 * 難度：中等 (Medium)
 * 描述：計算 word 中最小字元出現的頻率 f(s)，並對於每個 query，找出 f(word) > f(query) 的 word 個數。
 * * 優化重點：
 * 1. 預處理：先行計算所有 words 的 f(s) 並排序，以便後續二分搜尋。
 * 2. 效率查詢：使用 upper_bound 尋找第一個大於 f(query) 的位置，直接推算數量。
 */

class Solution {
private:
    // 計算最小字元的出現頻率
    int freq(const std::string& word) {
        const auto& smallest = *std::min_element(word.cbegin(), word.cend());
        return std::count(word.cbegin(), word.cend(), smallest);
    }

public:
    std::vector<int> numSmallerByFrequency(std::vector<std::string>& queries, std::vector<std::string>& words) {
        // 1. 統計所有 words 的 f(s)
        std::vector<int> words_freq;
        words_freq.reserve(words.size());
        for (const std::string& word : words) {
            words_freq.push_back(freq(word));
        }
        
        // 2. 排序以便二分搜尋
        std::sort(words_freq.begin(), words_freq.end());

        // 3. 處理 queries，使用二分搜尋加速
        std::vector<int> res;
        res.reserve(queries.size());
        
        for (const std::string& query : queries) {
            int q_freq = freq(query);
            // 尋找第一個大於 q_freq 的位置
            const auto it = std::upper_bound(words_freq.cbegin(), words_freq.cend(), q_freq);
            // 該位置之後的所有元素皆符合 f(word) > f(query)
            res.emplace_back(std::distance(it, words_freq.cend()));
        }

        return res;
    }
};
