/**
 * 題目：1446. Consecutive Characters (連續字元)
 * 難度：簡單 (Easy)
 * 描述：找出字串中最長連續相同字元的長度。
 * * 時間複雜度：O(N)，N 為字串長度，只需一次遍歷。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 簡潔邏輯：移除額外的邊界判斷，讓主迴圈自動處理所有情況。
 * 2. 效能優化：減少每次迴圈呼叫 std::max 的次數，只有在字元改變或結束時才更新最大值。
 */

class Solution {
public:
    int maxPower(string s) {
        if(s.size() == 1) return 1;
        int maxLen = 1;
        int localLen = 1;
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == s[i + 1])  localLen++;
            else localLen = 1;
            maxLen = std::max(maxLen, localLen);
        }
        return maxLen;
    }
};
