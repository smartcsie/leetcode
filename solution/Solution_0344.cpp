/**
 * 題目：344. Reverse String
 * 難度：簡單 (Easy)
 * 描述：原地反轉字元陣列。
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while(left < right) swap(s[left++], s[right--]);
    }
};