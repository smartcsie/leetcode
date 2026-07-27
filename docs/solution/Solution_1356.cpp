/**
 * 題目：1356. Sort Integers by The Number of 1 Bits (根據數字二進位中 1 的個數排序)
 * 難度：簡單 (Easy)
 * 描述：將整數陣列排序，優先依照二進位中 1 的數量（升序），若數量相同則依照數值大小（升序）。
 * * 時間複雜度：O(N log N) - 主要開銷在於排序。
 * 空間複雜度：O(1) - 若不考慮排序遞迴所需的堆疊空間。
 * * 設計思路：
 * 1. 使用 __builtin_popcount 快速取得二進位 1 的個數。
 * 2. 在自定義 sort 比較函式中，先比較位元數量，平手時再比較數值。
 */

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // 使用 lambda 進行排序，將邏輯封裝在內部提升封裝性
        sort(arr.begin(), arr.end(), [](const int &a, const int &b) {
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            
            // 優先比較位元數，若不同則回傳位元數較小的
            if (countA != countB) {
                return countA < countB;
            }
            // 位元數相同，回傳數值較小的
            return a < b;
        });
        
        return arr;
    }
};
