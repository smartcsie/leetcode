/**
 * 題目：1351. Count Negative Numbers in a Sorted Matrix
 * 難度：簡單 (Easy)
 * 描述：計算矩陣中負數的總數量。
 * * 時間複雜度：O(R log C) - 每行進行一次二分搜尋。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 1. 每一行進行二分搜尋：找出第一個小於 0 的元素位置。
 * 2. 累加計數：該位置後的元素數量即為該行負數個數。
 */

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid[0].size();
        
        for (const auto& row : grid) {
            // 在每一行中搜尋第一個小於 0 的元素
            int left = 0, right = n - 1;
            int firstNegativeIdx = n; // 預設為 n (代表該行無負數)
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (row[mid] < 0) {
                    firstNegativeIdx = mid;
                    right = mid - 1; // 繼續往左找，確認是否還有更早的負數
                } else {
                    left = mid + 1;
                }
            }
            
            // 該行負數數量為 (總長度 - 第一個負數的索引)
            count += (n - firstNegativeIdx);
        }
        
        return count;
    }
};
