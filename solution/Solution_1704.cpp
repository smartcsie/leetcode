/**
 * 題目：1704. Determine if String Halves Are Alike
 * 難度：簡單 (Easy)
 * 描述：判斷字串前後兩半的母音數量是否相等。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 定義母音檢查函式：利用位元運算，將 'a', 'e', 'i', 'o', 'u' 映射到 26 位元整數中。
 * 2. 使用 `count_if` 對前後兩半字串分別統計母音數量。
 * 3. 比較兩者數量是否相等。
 */


class Solution {
public:
    bool halvesAreAlike(string s) {
        int left = 0;
        int right = s.size() - 1;
        int count = 0;
        while(left < right) {
            if((0x104111 >> ((s[left++] | 32) - 'a')) & 1) count++;
            if((0x104111 >> ((s[right--] | 32) - 'a')) & 1) count--;
        }
        return count == 0;
    }
};