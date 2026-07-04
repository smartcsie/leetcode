/**
 * 題目：648. Replace Words
 * 難度：中等 (Medium)
 * 描述：使用字典中最短的前綴替換句子中的單字。
 * * 優化策略：
 * 1. 預處理：將字典依首字母分桶並按長度由短到長排序，確保搜尋到的第一個匹配即為最短前綴。
 * 2. 高效匹配：利用 `string::compare` 進行字串頭部匹配，避免無效的全字串比對。
 */

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        istringstream ss(sentence);
        string word;
        string res = "";

        vector<vector<string>> dic(26);
        for(const string& word : dictionary) {
            dic[word[0] - 'a'].push_back(word);
        }

        for(int i = 0; i < 26; i++) {
            sort(dic[i].begin(), dic[i].end(), [](const string& a, const string& b) {
                return a.size() < b.size();
            });
        }

        while(ss >> word) {
            if(! res.empty()) res.append(" ");
            string replace = word;
            for(const string& prefix : dic[word[0] - 'a']) {
                if(word.compare(0, prefix.size(), prefix) == 0) {
                    replace = prefix;
                    break;
                }
            }
            res.append(replace);
        }
        return res;
    }
};
