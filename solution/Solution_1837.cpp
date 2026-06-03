/**
 * 題目：1837. Sum of Digits in Base K (K 進位下的數字總和)
 * 難度：簡單 (Easy)
 * 描述：將整數 n 轉換為 K 進位，並計算其位數總和。
 * * 時間複雜度：O(logK N) - 每次除以 K，位數長度為 logK N。
 * 空間複雜度：O(1) - 僅使用常數額外空間。
 * * 優化思路：
 * 無需將數字轉為字串或儲存每一位，直接在轉換過程中將餘數累加即可。
 */

class Solution {
public:
    int sumBase(int n, int k) {
        int sum = 0;
        
        // 核心：持續取餘數 (當前位數值) 並將數字除以 K (移位)
        while (n > 0) {
            sum += (n % k); // 累加當前 K 進位的最後一位
            n /= k;         // 移除最後一位
        }
        
        return sum;
    }
};
