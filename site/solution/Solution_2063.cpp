/**
 * 題目：2063. Vowels of All Substrings
 * 難度：中等 (Medium)
 * 描述：計算字串 word 所有子字串中母音出現的總次數。
 * * 優化重點：
 * 1. 數學法：O(N) 時間複雜度，遠優於 O(N^2) 的暴力枚舉。
 * 2. 位元運算：用 bitmask 快速判斷母音，精簡且高效。
 */

class Solution {
public:
    long long countVowels(std::string word) {
        long long count = 0;
        long long n = word.size();
        
        for (int i = 0; i < n; i++) {
            // 位元遮罩判斷: 2130466 對應母音位置
            if ((2130466 >> (word[i] - 'a' + 1)) & 1) {
                // 每個母音貢獻 = (左側可選長度) * (右側可選長度)
                count += (i + 1) * (n - i);
            }
        }
        
        return count;
    }
};
