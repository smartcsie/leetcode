/**
 * 題目：1608. Special Array With X Elements Greater Than or Equal X
 * 難度：簡單 (Easy)
 * 描述：找出 x 使得陣列中恰好有 x 個元素大於或等於 x。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （排序 + Binary Search）：
 * 排序後對 x 做二分搜尋，用 lower_bound 計算大於等於 x 的元素數量是否等於 x。
 */
class Solution {
public:
    int specialArray(vector<int>& nums) {
        // 1. 先排序，這樣後面才能用 std::lower_bound 快速找出大於等於某數的數量
        ranges::sort(nums);
        int n = nums.size();
        
        // 2. 對可能的答案 x 進行二分搜尋
        // x 的可能範圍是 0 到 n
        int left = 0, right = n;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // 計算 nums 中「大於或等於 mid」的元素個數
            // lower_bound 會回傳第一個「大於或等於 mid」的位置
            auto it = ranges::lower_bound(nums, mid);
            int count = nums.end() - it; // 剩餘的元素個數就是大於等於 mid 的數量
            
            if (count == mid) {
                return mid; // 找到符合條件的 X！
            } else if (count > mid) {
                left = mid + 1; // 數量太多了，試試看更大的 x
            } else {
                right = mid - 1; // 數量太少了，試試看更小的 x
            }
        }
        
        return -1; // 找不到
    }
};