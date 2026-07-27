/**
 * 題目：884. Uncommon Words from Two Sentences (兩句話中的不常見單字)
 * 難度：簡單 (Easy)
 * 描述：回傳所有在其中一句只出現一次，且在另一句沒出現過的單字。
 * * 時間複雜度：O(N + M)，其中 N 和 M 分別是兩個句子的長度。
 * 空間複雜度：O(N + M)，用來儲存所有唯一的單字。
 * * 優化思路：
 * 將兩個字串合併視為一個字串流，統計單字出現的總次數，頻率為 1 即為不常見單字。
 */

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;

        auto countWords = [&](const string& s) {
            stringstream ss(s);
            string word;
            while (ss >> word) {
                wordCount[word]++;
            }
        };
    
        countWords(s1);
        countWords(s2);

        vector<string> res;
        for(const auto& [word, count] : wordCount) {
            if(count == 1) res.push_back(word);
        }
        return res;
    }
};
