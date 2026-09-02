/**
 * 題目：2559. Count Vowel Strings in Ranges (統計範圍內的母音字串數)
 * 難度：中等 (Medium)
 * 描述：計算在給定查詢區間 [L, R] 內，首尾皆為母音的單字個數。
 *
 * 時間複雜度：O(N+Q)
 * 空間複雜度：O(N)
 */

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n + 1, 0);
        for(int i = 0; i <  words.size(); i++) {
            bool front = (0x104111 >> (words[i].front() - 'a')) & 1 ;
            bool back = (0x104111 >> (words[i].back() - 'a')) & 1;
            prefix[i + 1] = (front && back) ? prefix[i] + 1 : prefix[i];
        }
        vector<vector<int>>& q = queries;
        vector<int> ans(q.size());
        for(int i = 0; i <  q.size(); i++) {
            ans[i] = prefix[q[i][1] + 1] - prefix[q[i][0]];
        }
        return ans;
    }
};
