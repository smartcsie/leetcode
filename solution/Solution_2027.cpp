/**
 * 題目：2027. Minimum Moves to Convert String
 * 難度：簡單 (Easy)
 * 描述：計算將所有 'X' 轉換為 'O' 的最少翻轉次數。
 */

class Solution {
public:
    int minimumMoves(std::string s) {
        int count = 0;
        int n = s.size();
        
        for (int i = 0; i < n; ) {
            // 快速跳過所有 'O'
            while (i < n && s[i] == 'O') {
                i++;
            }
            
            // 如果找到 'X'，執行一次操作並跳過 3 個單位
            if (i < n && s[i] == 'X') {
                i += 3;
                count++;
            }
        }
        
        return count;
    }
};
