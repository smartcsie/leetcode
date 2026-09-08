/**
 * 題目：1790. Check if One String Swap Can Make Strings Equal
 * 難度：簡單 (Easy)
 * 描述：判斷最多一次字元交換後兩字串是否相等。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （對撞雙指針）：
 * 找到第一個不同位置 left 和最後一個不同位置 right，交換後驗證是否相等。
 */
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        int left = 0;
        int right = s1.size() - 1;
        while(left < right) {
            while(left < right && s1[left] == s2[left]) left++;
            while(left < right && s1[right] == s2[right]) right--;
            if(left < right) {
                swap(s1[left++] , s1[right--]);
                return s1 == s2;
            }
        }
        return s1 == s2;
    }
};