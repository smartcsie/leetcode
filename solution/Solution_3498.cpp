/**
 * 題目：3498. Reverse Degree of a String (字串的反轉度)
 * 難度：簡單 (Easy)
 * 描述：計算字串的「反轉度」。對於字串中的每個字元，其貢獻值為：
 *      (反轉後的對應數值) * (1-based 索引)。
 *      例如：'z' 對應 1, 'a' 對應 26。
 * 
 * 時間複雜度：O(n) - 遍歷整個字串一次。
 * 空間複雜度：O(1) - 僅使用一個整數變數儲存累積結果。
 * 
 * 解法思路：
 * 1. 為了讓 'a' 對應 26，'z' 對應 1：
 *    計算方式為 `'z' - s[i] + 1`。
 * 2. 索引為 1-based：
 *    使用 `i + 1`。
 * 3. 遍歷累加即可得到總反轉度。
 */

class Solution {
public:
    int reverseDegree(string s) {
        int product = 0;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            // 計算當前字元的反轉數值
            int reverse_val = 'z' - s[i] + 1;
            // 累加貢獻值：(反轉數值) * (索引位置)
            product += reverse_val * (i + 1);
        }
        
        return product;
    }
};
