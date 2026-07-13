/**
 * 題目：2062. Count Vowel Substrings of a String
 * 難度：簡單 (Easy)
 * 描述：計算字串中所有「僅包含母音且包含全部五種母音」的子字串數量。
 * * 優化重點：
 * 1. O(N) 時間：避免 substr 造成的 O(N^3) 開銷。
 * 2. 狀態記錄：僅用一個位元遮罩記錄當前窗口內的母音種類。
 */

class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            int mask = 0;
            for(int j = i; j < n; j++) {
                mask |= 1 << (word[j] - 'a' + 1);
                if(mask == 2130466) count++;
            }
        }
        return count;
    }
};
