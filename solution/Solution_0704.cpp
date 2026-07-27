/**
 * 題目：704. Binary Search (二分搜尋)
 * 難度：簡單 (Easy)
 * 描述：在一個已排序的整數陣列中，尋找目標值 target 的索引，若不存在則回傳 -1。
 * * 時間複雜度：O(log N) - 每次迭代排除一半的搜尋範圍。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 設計思路：
 * 利用陣列的有序性，透過中間節點 mid 將搜尋範圍縮小。
 */

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        // 區間閉合 [left, right]，因此使用 <=
        while (left <= right) {
            // 使用位元運算避免 (left + right) 超過 int 最大值 (overflow)
            int mid = left + ((right - left) >> 1);
            
            if (nums[mid] == target) {
                return mid; // 找到目標
            } else if (nums[mid] > target) {
                right = mid - 1; // 目標在左半區
            } else {
                left = mid + 1; // 目標在右半區
            }
        }
        
        return -1; // 找不到
    }
};
