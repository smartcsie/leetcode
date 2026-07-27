/**
 * 題目：3541. Find Most Frequent Vowel and Consonant (找出最高頻的母音與子音)
 * 難度：簡單 (Easy)
 * 描述：統計字串中出現頻率最高的母音與子音次數，並回傳其總和。
 * * 時間複雜度：O(N)，遍歷一次字串計算頻率，再遍歷一次頻率陣列。
 * 空間複雜度：O(1)，頻率陣列大小固定為 26。
 * * 優化思路：
 * 1. 分離邏輯：先完整統計頻率，再遍歷陣列尋找極大值，避免在迴圈內頻繁呼叫函式。
 * 2. 移除冗餘判斷：直接在判斷時展開母音邏輯，減少分支預測開銷。
 */

class Solution {
private:
    bool isVowel(const char& c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int maxFreqSum(string s) {
        vector<int> counts(26, 0);
        int maxVowel = 0;
        int maxConsonant = 0;
        for(const char& c : s) {
            counts[c - 'a']++;
            if(isVowel(c)) {
                maxVowel = max(maxVowel, counts[c - 'a']);
            } else {
                maxConsonant = max(maxConsonant, counts[c - 'a']);
            }
        }
        return maxVowel + maxConsonant;
    }
};
