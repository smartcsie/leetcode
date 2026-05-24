/**
 * 題目：2586. Count the Number of Vowel Strings in Range (統計範圍內的母音字串)
 * 難度：簡單 (Easy)
 * 描述：檢查 words 陣列中 [left, right] 範圍內的單字，是否首尾皆為母音 ('a', 'e', 'i', 'o', 'u')。
 * 
 * 時間複雜度：O(m + k)，其中 m 是區間長度，k 是集合建置開銷（常數級）。
 * 空間複雜度：O(1)，集合固定儲存 5 個字元。
 * 
 * 解法思路：
 * 1. 使用 unordered_set 儲存所有母音，提供 O(1) 的查詢效率。
 * 2. 遍歷從 left 到 right 的索引。
 * 3. 檢查每個單字的 `front()` (第一個字元) 與 `back()` (最後一個字元) 是否都在集合內。
 */

class Solution {
    // 定義為成員函式，避免重複建立 Lambda
    static bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    int vowelStrings(vector<string>& words, int left, int right) {
        // 使用 STL count_if + 迭代器區間
        return count_if(words.begin() + left, words.begin() + right + 1, [](const string& w) {
            return isVowel(w.front()) && isVowel(w.back());
        });
    }
};
