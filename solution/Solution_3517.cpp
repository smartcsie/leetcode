/**
 * 題目：3517. Smallest Palindromic Rearrangement I (最小回文排列 I)
 * 難度：中等 (Medium)
 * 描述：返回字串 s 按字典序排列的最小回文排列。
 * * 時間複雜度：O(N) - 統計頻率、重建前半段、鏡像後半段各為線性掃描。
 * 空間複雜度：O(1) - 使用長度為 26 的固定陣列儲存頻率。
 * * 優化思路：
 * 1. 僅統計前半段字元頻率，因為回文的後半段由前半段鏡像決定。
 * 2. 使用計數陣列 (Counting Sort) 代替 std::sort，將複雜度從 O(N log N) 降至 O(N)。
 * 3. 避免所有字串拼接與記憶體分配，直接在原字串 s 上操作。
 */

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int counts[26] = {0};
        
        // 1. 統計前半段字元頻率
        for(int i = 0; i < n / 2; ++i) {
            counts[s[i] - 'a']++;
        }
        
        // 2. 原地重建前半段：依序填入字母，保證字典序最小
        int idx = 0;
        for(int i = 0; i < 26; ++i) {
            while(counts[i] > 0) {
                s[idx++] = (char)(i + 'a');
                counts[i]--;
            }
        }
        
        // 3. 鏡像複製：將前半段鏡像至後半段
        // 若長度為奇數，中間字元不動
        for(int i = 0; i < n / 2; ++i) {
            s[n - 1 - i] = s[i];
        }
        
        return s;
    }
};
