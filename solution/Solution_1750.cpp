/**
 * 題目：1750. Minimum Length of String After Deleting Similar Ends
 * 難度：中等 (Medium)
 * 描述：重複刪除字串兩端相等的連續字元。
 *
 * 時間複雜度：O(N) - 每個字元最多被訪問一次。
 * 空間複雜度：O(1)。
 */

class Solution {
public:
    int minimumLength(string s) {
        if(s.size() == 1) return 1;
        int left = 0;
        int right = s.size() - 1;
        while(left < right && s[left] == s[right]) {
            char c = s[left];
            while(left <= right && s[left] == c) left++;
            while(left <= right && s[right] == c) right--;
        }
        return right - left + 1;
    }
};
