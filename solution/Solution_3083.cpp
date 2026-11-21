/**
 * 題目：3083. Existence of a Substring in a String and Its Reverse
 * 難度：簡單 (Easy)
 * 描述：判斷字串中是否存在某個長度為 2 的子字串，其反轉字串也存在於原字串中。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 使用固定大小陣列：避免動態記憶體分配。
 * 2. 直接尋址：透過 ASCII 減法直接定址，存取速度為常數級 O(1)。
 */

class Solution {
public:
    bool isSubstringPresent(string s) {
        bitset<26> seen[26];
        int n = s.size();
        if(n == 1) return false;
        for( int i = 1; i < n; i++) {
            seen[s[i - 1] - 'a'][s[i] - 'a'] = 1;
        }
        for( int i = n - 1; i >= 1; i--) {
            if(seen[s[i] - 'a'][s[i - 1] - 'a']) return true;
        }
        return false;
    }
};