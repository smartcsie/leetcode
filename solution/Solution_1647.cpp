/**
 * 題目：1647. Minimum Deletions to Make Character Frequencies Unique
 * 難度：中等 (Medium)
 * 描述：調整字元頻率使其皆唯一，計算最少的刪除字元數。
 * * 時間複雜度：O(N + K log K) - N 為字串長度，K 為字母總數 (26)。
 * 空間複雜度：O(K)。
 * * 解法思路：
 * 1. 使用陣列統計每個字元的頻率。
 * 2. 將頻率進行排序，以便由大到小檢查重複性。
 * 3. 利用 Hash Set 記錄已出現的頻率，若發生衝突，則遞減當前頻率直到唯一或歸零。
 */

class Solution {
public:
    int minDeletions(string s) {
        vector<int> counts(26, 0);
        for(const char& c : s ) {
            counts[c - 'a']++;
        }
        sort(counts.begin(), counts.end());
        int deletes = 0;
        unordered_set<int> freqs;
        for(int i = 25; i >= 0; i--) {
            if(counts[i] == 0) continue;
            while(freqs.count(counts[i]) && counts[i] > 0) {
                counts[i]--;
                deletes++;
            }
            freqs.insert(counts[i]);
        }
        return deletes;
    }
};
