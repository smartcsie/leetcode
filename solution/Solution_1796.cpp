/**
 * 題目：1796. Second Largest Digit in a String (字串中第二大的數字)
 * 難度：簡單 (Easy)
 * 描述：在字串 s 中找到第二大的數位，若不存在則回傳 -1。
 * * 時間複雜度：O(N)，N 為字串長度。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 減少標頭檔依賴：直接使用 -1 作為未初始化的標記。
 * 2. 邏輯清晰化：嚴格區分「更新最大值」與「更新第二大值」的條件。
 */

class Solution {
public:
    int secondHighest(string s) {
        int largest = -1;
        int second = -1;
        for(char c : s) {
            if(isdigit(c)) {
                int num = c - '0';
                if(num > largest) {
                    second = largest;
                    largest = num;
                } else if(num > second && num < largest) {
                    second = num;
                }
            }
        }
        return second ;
    }
};
