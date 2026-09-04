/**
 * 題目：1351. Count Negative Numbers in a Sorted Matrix
 * 難度：簡單 (Easy)
 * 描述：給定一個行列均為非遞增排序的矩陣，計算其中負數的個數。
 *
 * 時間複雜度：O(R * logC)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （每列做 Binary Search）：
 * 1. 每一列都是非遞增排序，反向來看（rbegin → rend）是非遞減排序。
 * 2. 對每列用 lower_bound 搜尋第一個 >= 0 的位置（從尾端開始）。
 * 3. 該位置到 rbegin 的距離就是該列負數的個數。
 * 4. 累加每列的負數個數即為答案。
 *
 * 注意：
 * 使用反向迭代器 rbegin/rend，讓非遞增的列變成非遞減，
 * 符合 lower_bound 要求的升序前提。
 * 若改用 O(R+C) 的線性掃描（從右上角出發），空間同樣 O(1) 但實作更簡單。
 */
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for (const vector<int>& row : grid) {
            // 反向迭代器讓非遞增列變成非遞減，符合 lower_bound 前提
            auto it = lower_bound(row.rbegin(), row.rend(), 0);
            count += (it - row.rbegin());  // 到 rbegin 的距離 = 負數個數
        }
        return count;
    }
};