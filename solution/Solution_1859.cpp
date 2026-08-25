/**
 * 題目：1859. Sorting the Sentence (將句子排序)
 * 難度：簡單 (Easy)
 * 描述：將包含數字結尾的單字句子，依據數字順序還原句子。
 *
 * 時間複雜度：O(N) - N 為字串長度，只需遍歷一次。
 * 空間複雜度：O(N) - 用於儲存分割後的單字。
 *
 * 解法思路：
 * 利用單字結尾數字 (1-9) 作為陣列索引，直接將單字放入對應的 bucket 中，
 * 避免了使用 sort() 進行比較排序的 O(N log N) 成本。
 */

class Solution {
public:
    string sortSentence(string s) {
        istringstream iss(s);
        string word;
        vector<string> words(9);
        int  n = 0;
        while(iss >> word) {
            int idx = word.back() - '0' - 1;
            word.pop_back();
            words[idx] = word;
            n++;
        }
        string ans;
        for(int i = 0; i < n ; i++) {
            ans += words[i];
            if(i != n - 1) ans.push_back(' ');
        }
        return ans;
    }
};
