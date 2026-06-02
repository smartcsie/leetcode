/**
 * 題目：540. Single Element in a Sorted Array (有序陣列中的單一元素)
 * 難度：中等 (Medium)
 * 描述：在一個已排序的陣列中，除了一個元素外，其他元素均出現兩次，找出該元素。
 * * 時間複雜度：O(log N) - 二分搜尋法。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 1. 利用陣列已排序特性：在單一元素出現前，成對的元素滿足 (even, odd) 下標關係。
 * 2. 透過二分搜尋判斷中間元素的奇偶特性，縮小搜尋範圍。
 */

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // 確保 mid 位於偶數位置，方便檢查下一位是否相同
            // 如果 mid 是奇數，就把它變成前一個偶數
            if (mid % 2 == 1) mid--;
            
            // 檢查這一對是否匹配
            if (nums[mid] == nums[mid + 1]) {
                // 如果匹配，代表單一元素在右半邊
                left = mid + 2;
            } else {
                // 如果不匹配，代表單一元素在左半邊或就是 mid
                right = mid;
            }
        }
        
        return nums[left];
    }
};
