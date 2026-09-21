/**
 * 題目：1758. Minimum Changes To Make Alternating Binary String (生成交替二進位字串的最小操作數)
 * 難度：簡單 (Easy)
 * 描述：計算將字串變為 "0101..." 或 "1010..." 所需的最少翻轉次數。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    int minOperations(string s) {
        int count = 0;
        int n = s.size();
        for(int i = 0; i < s.size(); i++) {
            if((s[i] - '0') != (i & 1)) count++;
        }
        return min(count, n - count);
    }
};
