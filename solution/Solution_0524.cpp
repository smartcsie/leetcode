/**
 * 題目：524. Longest Word in Dictionary through Deleting (透過刪除得到字典裡最長的單字)
 * 難度：中等 (Medium)
 * 描述：在 dictionary 中找出最長且字典序最小的單字，使其能由 s 透過刪除某些字元得到。
 * * 時間複雜度：O(D * M)，D 為單字數量，M 為單字平均長度 (不使用 sort 的情況)。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 雙指標驗證：檢查是否為子序列。
 * 2. 最佳化篩選：遍歷時直接更新「最佳候選字」，避免全域排序的成本。
 */

class Solution {
private:
    bool isSubsequence(const string& word, const string& s) {
        int i = 0, n = word.size();
        if (n == 0) return true;
        for (char c : s) {
            if (word[i] == c) {
                if (++i == n) return true;
            }
        }
        return false;
    }

public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string bestWord = "";
        
        for (const string& word : dictionary) {
            // 比較邏輯：
            // 1. 若長度更長，直接更新
            // 2. 若長度相等但字典序更小，更新
            if (isSubsequence(word, s)) {
                if (word.size() > bestWord.size() || 
                   (word.size() == bestWord.size() && word < bestWord)) {
                    bestWord = word;
                }
            }
        }
        return bestWord;
    }
};
