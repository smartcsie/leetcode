/**
 * 題目：2937. Make Three Strings Equal (使三個字串相等)
 * 難度：簡單 (Easy)
 * 描述：三個字串若沒有共同前綴則回傳 -1，否則計算刪除字元使三者相等所需的最少次數。
 *
 * 時間複雜度：O(min(L1,L2,L3)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 邏輯簡化：直接計算出共同前綴長度 `i`，總操作數即為總長度減去 3 倍的共同前綴長度。
 */

class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int len = 0;
        int m = s1.size();
        int n = s2.size();
        int o = s3.size();
        for( int i = 0; i < min({m , n , o}); i++) {
            if(s1[i] == s2[i] && s2[i] == s3[i]) len++;
            else break;
        }
        return  len == 0 ? -1 : m + n + o - 3 * len;
    }
};
