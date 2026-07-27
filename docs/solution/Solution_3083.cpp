/**
 * 題目：3083. Existence of a Substring in a String and Its Reverse
 * 難度：簡單 (Easy)
 * 描述：判斷字串中是否存在某個長度為 2 的子字串，其反轉字串也存在於原字串中。
 * * 時間複雜度：O(N) - 僅需遍歷一次字串。
 * 空間複雜度：O(1) - 使用固定大小為 26*26 的陣列，與輸入長度無關。
 * * 優化思路：
 * 1. 使用固定大小陣列：避免動態記憶體分配。
 * 2. 直接尋址：透過 ASCII 減法直接定址，存取速度為常數級 O(1)。
 */

class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.size();
        bool seen[26][26] = {false};
        for(int i = 0 ; i < n - 1; i++ ) {
            int ch1 = s[i] - 'a';
            int ch2 = s[i + 1] - 'a';
            seen[ch1][ch2] = true;
            if(seen[ch2][ch1]) return true;
        }
        return false;
    }
};
