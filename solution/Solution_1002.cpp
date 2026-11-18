/**
 * 題目：1002. Find Common Characters (查找共用字元)
 * 難度：簡單 (Easy)
 * 描述：找出所有字串中共同出現的字元，包含重複字元。
 *
 * 時間複雜度：O(N*K)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        array<uint8_t, 26> commons{};
        array<uint8_t, 26> current{};
        vector<string> ans;
        for(const char& c : words[0]) commons[c - 'a']++;
        for(int i = 1; i < words.size(); i++) {
            current.fill(0);
            for(const char& c : words[i]) {
                current[c - 'a']++;
            }
            for(int i = 0; i < 26; i++) {
                commons[i] = min(commons[i], current[i]);
            }
        }
        for(int i = 0; i < 26; i++) {
            while(commons[i]-- > 0) ans.push_back(string(1, 'a' + i));
        }
        return ans;
    }
};