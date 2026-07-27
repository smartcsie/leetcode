/**
 * 題目：1287. Element Appearing More Than 25% In Sorted Array
 * 難度：簡單 (Easy)
 * 描述：在已排序的陣列中，找出出現次數嚴格大於 25% 的元素。
 * * 時間複雜度：O(N) - 遍歷一次陣列。
 * 空間複雜度：O(1) - 原地比較，無額外空間使用。
 * * 優化思路：
 * 1. 數學窗口：若某元素出現超過 25%，則在距離為 n/4 的位置必定重疊。
 * 2. 視窗檢測：檢查 `arr[i]` 是否等於 `arr[i + n/4]`。
 */

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        // 如果長度小於 4，直接回傳第一個元素（根據題目限制，此類題目必有解）
        if (n == 1) return arr[0];
        
        int span = n / 4;
        
        // 遍歷陣列，檢查間距為 span 的兩個點
        // 只要 arr[i] == arr[i + span]，該數出現次數必 > 25%
        for (int i = 0; i < n - span; i++) {
            if (arr[i] == arr[i + span]) {
                return arr[i];
            }
        }
        
        return -1; // 理論上題目保證必有解
    }
};
