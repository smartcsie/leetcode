/**
 * 題目：2586. Count the Number of Vowel Strings in Range (統計範圍內的母音字串)
 * 難度：簡單 (Easy)
 * 描述：檢查 words 陣列中 [left, right] 範圍內的單字，是否首尾皆為母音 ('a', 'e', 'i', 'o', 'u')。
 *
 * 時間複雜度：O(M+K)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 使用 unordered_set 儲存所有母音，提供 O(1) 的查詢效率。
 * 2. 遍歷從 left 到 right 的索引。
 * 3. 檢查每個單字的 `front()` (第一個字元) 與 `back()` (最後一個字元) 是否都在集合內。
 */

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;
        for(int i = left; i <= right; i++) {
            char c1 = words[i][0];
            char c2 = words[i].back();
            if( (0x104111 >> (c1 - 'a')) & 1  && (0x104111 >> (c2 - 'a')) & 1) ans++;
        }
        return ans;
    }
    }
};
