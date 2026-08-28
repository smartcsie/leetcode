/**
 * 題目：3541. Find Most Frequent Vowel and Consonant (找出最高頻的母音與子音)
 * 難度：簡單 (Easy)
 * 描述：統計字串中出現頻率最高的母音與子音次數，並回傳其總和。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 分離邏輯：先完整統計頻率，再遍歷陣列尋找極大值，避免在迴圈內頻繁呼叫函式。
 * 2. 移除冗餘判斷：直接在判斷時展開母音邏輯，減少分支預測開銷。
 */

class Solution {
public:
    int maxFreqSum(string s) {
        int maxVowel = 0;
        int maxConsonants = 0;
        vector<int> counts(26, 0);
        for(const char& c : s) {
            int idx = c - 'a';
            counts[idx]++;
            if((0x104111 >> (idx)) & 1) {
                maxVowel = max(maxVowel, counts[idx]);
            } else {
                maxConsonants = max(maxConsonants, counts[idx]);
            }
        }
        return maxVowel + maxConsonants;
    }
};