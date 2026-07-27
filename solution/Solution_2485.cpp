/**
 * 題目：2485. Find the Pivot Integer (找出中樞整數)
 * 難度：簡單 (Easy)
 * 描述：找到一個整數 x，滿足 1...x 之和等於 x...n 之和。
 * * 時間複雜度：O(1) - 透過數學運算直接得出結果。
 * 空間複雜度：O(1) - 不依賴額外儲存空間。
 * * 優化思路：
 * 1. 數學推導：由 Sum(1, x) = Sum(x, n) 推導得 x^2 = Sum(1, n)。
 * 2. 驗證：僅需檢查 Sum(1, n) 是否為完全平方數，x 即為其平方根。
 */

#include <cmath>

class Solution {
public:
    int pivotInteger(int n) {
        // 1 到 n 的總和公式: n * (n + 1) / 2
        int totalSum = n * (n + 1) / 2;
        
        // 取總和的平方根，轉為整數
        int x = static_cast<int>(std::sqrt(totalSum));
        
        // 檢查 x 是否為完全平方根，若是則 x 即為樞紐整數
        // 否則表示不存在滿足條件的整數，回傳 -1
        return (x * x == totalSum) ? x : -1;
    }
};
