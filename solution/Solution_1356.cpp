/**
 * 題目：1356. Sort Integers by The Number of 1 Bits (根據數字二進位中 1 的個數排序)
 * 難度：簡單 (Easy)
 * 描述：將整數陣列排序，優先依照二進位中 1 的數量（升序），若數量相同則依照數值大小（升序）。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(1)
 *
 * 設計思路：
 * 1. 1. 使用 __builtin_popcount 快速取得二進位 1 的個數。
 * 2. 2. 在自定義 sort 比較函式中，先比較位元數量，平手時再比較數值。
 */

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int bitsA = __builtin_popcount(a);
            int bitsB = __builtin_popcount(b);
            return bitsA != bitsB ? bitsA < bitsB : a < b;
        });
        return arr;
    }
};
