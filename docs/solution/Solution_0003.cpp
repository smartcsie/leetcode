/**
 * 題目：3. Longest Substring Without Repeating Characters (無重複字元的最長子字串)
 * 難度：中等 (Medium)
 * 描述：在字串中找出沒有重複字元的最長子字串長度。
 * * 時間複雜度：O(N) - right 指標掃描一次。
 * 空間複雜度：O(1) - 使用固定大小 128 的陣列 (ASCII 範圍)。
 * * 優化思路：
 * 將 freq 陣列用途改為儲存「字元最後出現的位置 + 1」。
 * 這樣當發現重複時，可以直接將 left 指標跳到上一個該字元位置的下一個位置。
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 使用陣列儲存字元對應的「下一個起始位置」
        // 初始化為 0，代表還未出現過
        int last_seen[128] = {0};
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.size(); right++) {
            // 如果該字元之前出現過，且位置在當前視窗內
            // 將 left 跳躍至該字元上一次出現位置的右側
            if (last_seen[s[right]] > left) {
                left = last_seen[s[right]];
            }
            
            // 更新 maxLength
            maxLength = max(maxLength, right - left + 1);
            
            // 記錄該字元「下一個」出現的起點 (位置 + 1)
            last_seen[s[right]] = right + 1;
        }
        
        return maxLength;
    }
};
