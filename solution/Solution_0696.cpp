/**
 * 題目：696. Count Binary Substrings
 * 難度：簡單 (Easy)
 * 描述：計算所有出現 0 和 1 次數相等且連續的子字串。
 * 優化重點：
 * 1. 空間 O(1)：直接在遍歷時累計並計算，無需額外陣列空間。
 * 2. 邏輯簡潔：利用相鄰分組的長度限制，將問題轉化為 min(prev, curr) 的累加。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    int countBinarySubstrings(string s) {
        int pre = 0;
        int cur = 1;
        int ans = 0;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1]) {
                cur++;
            } else {
                ans += min(pre, cur);
                pre = cur;
                cur = 1;
            }
        }
        return ans + min(pre, cur);
    }
};