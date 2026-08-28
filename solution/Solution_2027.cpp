/**
 * 題目：2027. Minimum Moves to Convert String
 * 難度：簡單 (Easy)
 * 描述：計算將所有 'X' 轉換為 'O' 的最少翻轉次數。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    int minimumMoves(string s) {
        int count = 0;
        int n = s.size();
        int i = 0;
        while(i < n) {
            while(i < n && s[i] == 'O') i++;
            if(s[i] == 'X') {
                i += 3;
                count++;
            }
        }
        return count;
    }
};
