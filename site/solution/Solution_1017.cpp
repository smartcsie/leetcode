/**
 * 題目：1017. Convert to Base -2 (負二進位轉換)
 * 難度：中等 (Medium)
 * 描述：將一個整數轉換為 -2 進位的字串表示。
 * * 時間複雜度：O(log N) - 每次運算將 n 大致減半。
 * 空間複雜度：O(1) - 不考慮結果字串空間。
 * * 優化思路：
 * 在負基數轉換中，若餘數出現負值，我們需要透過「借位」將其調整為正值（0 或 1）。
 * 數學技巧：n = (n - remainder) / -2。
 * 經簡化後，等價於 `n = -(n >> 1)`，這完美處理了餘數調整與除法。
 */

class Solution {
public:
    string baseNeg2(int n) {
        if(n == 0) return "0";
        string res = "";
        while(n != 0) {
            res = to_string(n & 1) + res;
            n = -(n>>1);
        }
        return res;
    }
};
