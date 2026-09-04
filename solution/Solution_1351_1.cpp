/**
 * 題目：1351. Count Negative Numbers in a Sorted Matrix
 * 難度：簡單 (Easy)
 * 描述：給定一個行列均為非遞增排序的矩陣，計算其中負數的個數。
 *
 * 時間複雜度：O(R * logC)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （每列做 Binary Search，找第一個負數位置）：
 * 1. 每一列為非遞增排序，正數在左、負數在右。
 * 2. 對每列用 Binary Search 找「第一個負數的 index」（即 left bound）。
 * 3. 條件：row[mid] < 0 → 第一個負數可能更左，right = mid - 1。
 *          row[mid] >= 0 → 第一個負數在右側，left = mid + 1。
 * 4. 迴圈結束時 left 指向第一個負數的位置，負數個數為 n - left。
 * 5. 累加每列的負數個數即為答案。
 */
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid[0].size();
        for (const vector<int>& row : grid) {
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (row[mid] < 0) right = mid - 1;  // 負數，往左找
                else              left  = mid + 1;   // 非負數，往右找
            }
            count += n - left;  // left 即為第一個負數的 index
        }
        return count;
    }
};