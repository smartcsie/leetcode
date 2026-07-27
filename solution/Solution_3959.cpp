/**
 * 題目：3959. Check Good Integer (檢查好整數)
 * 難度：簡單 (Easy)
 * 描述：計算數字 n 的每一位數位 d，判斷 sum(d * (d - 1)) 是否 >= 50。
 * * 時間複雜度：O(log N)，即 n 的位數。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 邏輯簡潔化：維持原有的累加邏輯，確保在累加過程中隨時檢查門檻。
 */

class Solution {
public:
    bool checkGoodInteger(int n) {
        // 如果 n 為負數，依題目定義處理，通常取絕對值
        if (n < 0) n = -n;
        
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            // 運算邏輯：d * (d - 1)
            sum += digit * (digit - 1);
            
            // 提前判斷：若已達標，直接返回 true，無需繼續計算剩餘數位
            if (sum >= 50) return true;
            
            n /= 10;
        }
        
        return false;
    }
};
