/**
 * 題目：1539. Kth Missing Positive Number (第 k 個缺失的正整數)
 * 難度：簡單 (Easy)
 * 描述：在嚴格遞增的數組中尋找第 k 個缺失的正整數。
 * * 時間複雜度：O(log N) - 二分搜尋法。
 * 空間複雜度：O(1) - 原地操作。
 * * 優化思路：
 * 在數組中，arr[i] 之前的缺失數字數量為 `arr[i] - (i + 1)`。
 * 我們使用 `lower_bound` 找出第一個「缺失數數量 >= k」的索引 `it`。
 * 最終結果為 `(索引位置) + k`。
 */

#include <vector>
#include <algorithm>

class Solution {
public:
    int findKthPositive(std::vector<int>& arr, int k) {
        // 使用 lower_bound 尋找第一個滿足 arr[i] - (i + 1) >= k 的位置
        // 注意：這裡使用 lambda 來定義自訂比較條件
        auto it = std::lower_bound(arr.begin(), arr.end(), k, 
            [&](int val, int target) {
                // 將索引轉為 distance
                int idx = &val - &arr[0]; // 或者使用 std::distance(arr.data(), &val)
                return (val - (std::distance(arr.data(), &val) + 1)) < target;
            });
            
        // 根據二分查找結果，答案為 (最終位置索引) + k
        return std::distance(arr.begin(), it) + k;
    }
};
