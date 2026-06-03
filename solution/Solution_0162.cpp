/**
 * 題目：162. Find Peak Element (尋找峰值元素)
 * 難度：中等 (Medium)
 * 描述：峰值元素是指其值大於左右相鄰元素的元素。給定一個陣列，找出其中一個峰值。
 * * 時間複雜度：O(log N) - 二分搜尋，每次排除一半範圍。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 比較 `mid` 與 `mid + 1` 的值。如果 `nums[mid] < nums[mid + 1]`，
 * 說明右側一定存在一個峰值；反之，左側一定存在。
 */

#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        // 進行二分搜尋
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // 比較 mid 和 mid + 1 的值
            if (nums[mid] < nums[mid + 1]) {
                // 如果右邊比較大，說明峰值在右側 (不包含 mid)
                left = mid + 1;
            } else {
                // 如果左邊比較大或相等，說明峰值在左側 (包含 mid)
                right = mid;
            }
        }
        
        // 當 left == right 時，即為峰值的位置
        return left;
    }
};
