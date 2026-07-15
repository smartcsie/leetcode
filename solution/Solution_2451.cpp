/**
 * 題目：2451. Odd String Difference
 * 難度：簡單 (Easy)
 * 描述：找出 words 陣列中唯一的「差異字串」。差異字串是指其差異陣列（相鄰字元之差）與其他字串不同的字串。
 * 
 * 解法思路：
 * 1. 定義輔助函數 getDiff：計算相鄰字元的 ASCII 差值並轉為字串。
 * 2. 使用 unordered_multimap 紀錄 {差異陣列: 原字串} 的映射關係。
 * 3. 遍歷 map，找到計數為 1 的那個差異陣列，即為目標字串。
 */

class Solution {
private:
    string getDiff(string s) {
        string ans;
        for(int i = 1; i < s.size(); i++) {
            ans.push_back((s[i] - s[i - 1] + 25));
        }
        return ans;
    }
public: 
    string oddString(vector<string>& words) {
        unordered_map<string, vector<string>> map;
        for(const string& word : words) {
            map[getDiff(word)].push_back(word);
        }
        for(const auto& [diff, strs]: map) {
           if(strs.size() == 1) return strs[0];
        }
        return "";
    }
};
