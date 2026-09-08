/**
 * 題目：2785. Sort Vowels in a String
 * 難度：中等 (Medium)
 * 描述：只對字串中的母音按 ASCII 排序，子音保持原位。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （收集母音排序後放回）：
 * 用 bitmask 0x104111 判斷母音，收集後排序，再依序放回原母音位置。
 */
class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for(const char& c : s) {
            if( (0x104111 >> (c | 32) - 'a') & 1) vowels.push_back(c);
        }
        sort(vowels.begin(), vowels.end());
        int idx = 0;
        for(char& c : s) {
            if( (0x104111 >> (c | 32) - 'a') & 1) c = vowels[idx++];
        }
        return s;
    }
};