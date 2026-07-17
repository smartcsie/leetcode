/**
 * 題目：3926. Count Valid Word Occurrences
 * 難度：中等 (Medium)
 * 描述：識別「Joiner Hyphen」並將其視為單字的一部分，將其他非連接符號視為分隔符，統計 Query 出現次數。
 * 
 * 解法思路：
 * 1. 預處理：將所有非 Joiner Hyphen 的字元替換為空白，使字串能夠直接透過 istringstream 切割。
 * 2. 判斷規則：'-' 僅在前後皆為小寫字母時才視為 Joiner Hyphen。
 * 3. 統計：利用 unordered_map 儲存所有合法 Word 的出現次數。
 */

class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s;
        for(const string word : chunks) s += word;
        for(int i = 0; i < s.size(); i++) {
            if(i == 0 && s[i] == '-') s[i] = ' ';
            else if( s[i] == '-' && (!isalpha(s[i - 1]) || !isalpha(s[i + 1]))) s[i] = ' ';
            else if(i == (s.size() - 1) && s[i] == '-') s[s.size() - 1] = ' '; 
        }
        unordered_map<string, int> map;
        istringstream ss(s);
        string word;
        while(ss >> word) {
            map[word]++;
        }
        vector<int> ans;
        for(const string& query: queries) {
            ans.push_back(map[query]);
        }
        return ans;
    }
};
