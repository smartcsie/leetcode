/**
 * 題目：1758. Minimum Changes To Make Alternating Binary String (生成交替二進位字串的最小操作數)
 * 難度：簡單 (Easy)
 * 描述：計算將字串變為 "0101..." 或 "1010..." 所需的最少翻轉次數。
 * * 時間複雜度：O(N) - 遍歷一次字串。
 * 空間複雜度：O(1) - 僅使用常數空間。
 */

class Solution {
public:
    int minOperations(string s) {
        int startOne = 0;
        for(int i =0 ; i < s.size(); i++) {
            if(i % 2 ==0  && s[i] != '1') {
                startOne++;
            } if(i % 2 ==1 &&　s[i] != '0') {
                startOne++;
            }
        }
        // 變數 startOne 是變成 "1010..." 需要的次數
        // 變數 (s.size() - startOne) 則是變成 "0101..." 的次數
        return min(startOne, (int) s.size() - startOne);
    }
};
