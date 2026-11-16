/**
 * 題目：884. Uncommon Words from Two Sentences
 * 難度：簡單 (Easy)
 * 描述：找出兩個句子中只出現一次的單字（在兩個句子合併後恰好出現一次）。
 *
 * 時間複雜度：O(N+M)
 * 空間複雜度：O(N+M)
 *
 * 解法思路：
 * （string_view + unordered_map 計數）：
 * 1. 用 string_view 對 s1、s2 做手動字串分割，避免 substr 複製字串。
 * 2. 以 string_view 作為 map 的 key，直接指向原字串的子段，不額外配置記憶體。
 * 3. 統計兩個句子所有單字的出現次數。
 * 4. 出現次數恰好為 1 的單字即為答案。
 *
 * 與 istringstream 版的差異：
 * istringstream 版程式碼更簡潔，string_view 版避免字串複製，
 * 理論上記憶體配置更少，但需注意 s1、s2 的生命週期必須比 counts 長。
 *
 * 注意：回傳時需將 string_view 轉回 string。
 */
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string_view, int> counts;
        string_view sv1(s1);
        string_view sv2(s2);

        for (int i = 0, start = 0; i <= (int)sv1.size(); i++) {
            if (sv1[i] == ' ' || i == (int)sv1.size()) {
                if (i > start) counts[sv1.substr(start, i - start)]++;
                start = i + 1;
            }
        }
        for (int i = 0, start = 0; i <= (int)sv2.size(); i++) {
            if (sv2[i] == ' ' || i == (int)sv2.size()) {
                if (i > start) counts[sv2.substr(start, i - start)]++;
                start = i + 1;
            }
        }

        vector<string> ans;
        ans.reserve(counts.size());
        for (const auto& [s, count] : counts)
            if (count == 1) ans.push_back(string(s));
        return ans;
    }
};