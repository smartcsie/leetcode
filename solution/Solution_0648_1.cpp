/**
 * 題目：648. Replace Words (替換單詞)
 * 難度：中等 (Medium)
 * 描述：使用字典中最短的前綴替換句子中的單字。
 *
 * 時間複雜度：O((M + N) * L) - M 為字典大小、N 為句子單字數，L 為平均字串長度；
 *             排序每個字母桶約 O(M log M * L)，比對每個單字約 O(L)。
 * 空間複雜度：O(M * L) - 26 個桶總共儲存 M 個字典字串。
 *
 * 解法思路：
 * 1. 依首字母分桶 (Bucket by First Letter)：
 *    - 建立 26 個桶（對應 a~z），把字典中每個字依首字母分類存入對應桶中。
 * 2. 每個桶內依長度排序 (Sort by Length Within Bucket)：
 *    - 確保同一個桶內，越短的前綴排在越前面，這樣第一個比對成功的前綴，
 *      就保證是「最短」的合法前綴。
 * 3. 逐字比對前綴 (Prefix Matching)：
 *    - 對句子中每個單字，只需在對應首字母的桶內，依序嘗試 string::compare
 *      比對開頭是否吻合，找到第一個吻合的就直接採用（因為已經照長度排序）。
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
