/**
 * 題目：3090. Maximum Length Substring With Two Occurrences
 * 難度：簡單 (Easy)
 * 描述：找到最長子字串，其中每個字元出現頻率不超過 2 次。
 * * 優化重點：
 * 1. O(N) 時間複雜度：透過滑動視窗，每個字元最多被存取兩次。
 * 2. 空間複雜度 O(1)：固定大小的頻率陣列。
 */

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        std::vector<int> count(26, 0);
        int left = 0, res = 0;
        for(int right = 0; right < n; right++) {
            char c = s[right] - 'a';
            count[c]++;
            while(count[c] > 2) {
                count[s[left] - 'a']--;
                left++;
            }
            res = std::max(res, right - left + 1);
        }   
        return res;
    }
};
