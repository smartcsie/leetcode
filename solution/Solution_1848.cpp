/**
 * 題目：1848. Minimum Distance to the Target Element (到目標元素的最短距離)
 * 難度：簡單 (Easy)
 * 描述：在陣列 nums 中找出等於 target 的元素，使其與 start 的絕對距離最小。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 雙向搜尋：從 start 開始向左右兩側擴展，一旦發現目標，該距離必然是最小距離。
 */

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        for(int d = 0; d < n; d++) {
            if(start - d >=0 && nums[start - d] == target) return d;
            if(start + d < n && nums[start + d] == target) return d;
        }
        return -1;
    }
};
