/**
 * 題目：378. Kth Smallest Element in a Sorted Matrix (有序矩陣中第 K 小的元素)
 * 難度：中等 (Medium)
 * 描述：在一個 n x n 的矩陣中，每一行和每一列均按升序排列，找出第 k 小的元素。
 * * 時間複雜度：O(N * log(max - min)) - N 為矩陣寬度。
 * 空間複雜度：O(1) - 不使用額外空間。
 * * 優化思路：
 * 本題不能直接對矩陣進行常規二分查找，因此改為對「數值範圍 [min, max]」進行二分查找。
 * 核心在於 search_less_equal 函式：利用矩陣有序的特性，從左下角開始進行 Staircase Search (樓梯搜尋)
 * 以 O(N) 的時間統計出矩陣中有多少元素小於或等於目標值。
 */

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            // 統計有多少元素 <= mid
            if (countLessEqual(matrix, mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

private:
    int countLessEqual(const vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int count = 0;
        int row = n - 1; // 從左下角開始
        int col = 0;
        
        while (row >= 0 && col < n) {
            if (matrix[row][col] <= target) {
                // 若當前值 <= target，則該行此列及以上的所有元素皆符合 (共 row + 1 個)
                count += (row + 1);
                col++;
            } else {
                // 若當前值 > target，則向上移動一列
                row--;
            }
        }
        return count;
    }
};
