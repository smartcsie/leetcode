/**
 * 題目：383. Ransom Note (贖金信)
 * 難度：簡單 (Easy)
 * 描述：判斷 ransomNote 是否能由 magazine 中的字母組成。
 * * 時間複雜度：O(M + N) - M 為 magazine 長度，N 為 ransomNote 長度。
 * 空間複雜度：O(1) - 陣列大小固定為 26，屬於常數空間。
 * * 優化思路：
 * 使用 `int count[26]` 取代 `unordered_map`，減少雜湊計算開銷，
 * 對於小範圍字元集（26個字母），陣列存取速度快於 Map。
 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0};
        for(const char& c :  magazine) {
            count[c-'a']++;
        }
        for(const char& c :  ransomNote) {
            if(count[c-'a'] == 0) return false;
            count[c-'a']--;
        }
        return true;
    }
};
