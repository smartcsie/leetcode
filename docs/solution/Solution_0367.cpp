/**
 * 題目：367. Valid Perfect Square (有效的完全平方數)
 * 難度：簡單 (Easy)
 * 描述：給定一個正整數 num，若 num 是一個完全平方數，則回傳 true，否則回傳 false。
 * * 時間複雜度：O(log N) - 二分搜尋的搜尋空間為 [1, num]。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 設計思路：
 * 透過二分搜尋法尋找整數解。由於平方計算可能超出 32 位元整數範圍，
 * 使用 long long 進行中介計算以防止溢位。
 */

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 1) return false;
        int left = 1, right = num;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // 使用 1LL 強制轉型為 long long，避免 mid * mid 溢位
            long long square = 1LL * mid * mid;
            
            if (square == num) {
                return true;
            } else if (square < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};
