/**
 * 題目：424. Longest Repeating Character Replacement (替換後的最長重複字元)
 * 難度：中等 (Medium)
 * 描述：在字串中最多替換 k 個字元，求能得到的最長連續重複字元長度。
 * * 時間複雜度：O(N) - 每個字元被 left 和 right 指針訪問一次。
 * 空間複雜度：O(1) - 陣列大小為 26，固定空間。
 * * 設計思路：
 * 1. 視窗長度：right - left + 1。
 * 2. 替換所需次數 = 視窗長度 - 視窗內出現頻率最高的字元次數。
 * 3. 若替換次數 > k，表示窗口非法，縮小左邊界。
 */

class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int left = 0, max_freq = 0, max_len = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            // 更新當前視窗內字元出現的最高頻率
            max_freq = max(max_freq, ++count[s[right] - 'A']);
            
            // 視窗長度減去最高頻率字元數，即為需翻轉的字元數
            // 若大於 k，視窗非法，左邊界右移
            if (right - left + 1 - max_freq > k) {
                count[s[left] - 'A']--;
                left++;
            }
            
            // max_len 維持當前合法的最大窗口長度
            max_len = right - left + 1;
        }
        
        return max_len;
    }
};
