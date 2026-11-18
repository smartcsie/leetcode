/**
 * 題目：819. Most Common Word
 * 難度：簡單 (Easy)
 * 描述：找出段落中未被禁用的最常用單詞。
 *
 * 時間複雜度：O(M+N)
 * 空間複雜度：O(M+N)
 */

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string_view> bannedSet(banned.begin(), banned.end());
        unordered_map<string_view, int> counts;
        string_view all = paragraph, ans;       // 指向 paragraph 的緩衝區，下面原地修改也沒問題
        int mx = 0, n = paragraph.size();

        for (int i = 0, start = 0; i <= n; i++) {
            if (i < n && isalpha((unsigned char)paragraph[i])) {
                paragraph[i] |= 32;             // 字母一律轉小寫（'A'|32 == 'a'，小寫不變）
                continue;                        // 還在單字中，繼續往後
            }
            // 走到這裡：遇到非字母或字串結尾，單字結束
            if (start < i) {
                string_view word = all.substr(start, i - start);
                if (!bannedSet.contains(word)) {
                    int& c = ++counts[word];     // 只查一次雜湊
                    if (c > mx) { mx = c; ans = word; }
                }
            }
            start = i + 1;
        }
        return string(ans);
    }
};