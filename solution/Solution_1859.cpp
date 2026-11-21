/**
 * 題目：1859. Sorting the Sentence (將句子排序)
 * 難度：簡單 (Easy)
 * 描述：將包含數字結尾的單字句子，依據數字順序還原句子。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 利用單字結尾數字 (1-9) 作為陣列索引，直接將單字放入對應的 bucket 中，
 * 避免了使用 sort() 進行比較排序的 O(N log N) 成本。
 */

class Solution {
public:
    string sortSentence(string s) {
        string_view sv = s;
        array<pair<int, int>, 10> idxs;
        idxs.fill({-1, -1});
        int n = s.size();
        for(int i = 0, start = 0; i <= n; i++) {
            if(i == n || s[i] == ' ') {
                int idx = s[i - 1] - '0';
                idxs[idx] = {start, i - start - 1};
                start = i + 1;
            }
        }
        string ans;
        ans.reserve(n); 
        for(int i = 1; i <= 9; i++) {
            if(idxs[i].first == -1) continue;
            if(!ans.empty()) ans.push_back(' ');
            ans += sv.substr(idxs[i].first, idxs[i].second);
        }
        return ans;
    }
};