/**
 * 題目：1876. Substrings of Size Three with Distinct Characters (長度為三且各字元不同的子字串)
 * 難度：簡單 (Easy)
 * 描述：找出字串中所有長度為 3 且字元皆相異的子字串數量。
 * * 時間複雜度：O(N) - 遍歷字串一次。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 直接枚舉長度為 3 的視窗，因為 k 固定且很小，直接進行三個字元的比較是最快的方法，
 * 避免了使用額外的哈希表或集合帶來的記憶體開銷。
 */

class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        if(s.size() < 3) return 0;
        for(int i = 0 ; i < s.size() - 2; i ++) {
            if(s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2] ) count++;
        }
        return count;
    }
};
