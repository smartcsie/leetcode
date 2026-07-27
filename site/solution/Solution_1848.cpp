/**
 * 題目：1848. Minimum Distance to the Target Element (到目標元素的最短距離)
 * 難度：簡單 (Easy)
 * 描述：在陣列 nums 中找出等於 target 的元素，使其與 start 的絕對距離最小。
 * * 時間複雜度：O(N) - 最壞情況下仍需遍歷陣列。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 1. 雙向搜尋：從 start 開始向左右兩側擴展，一旦發現目標，該距離必然是最小距離。
 */

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = static_cast<int>(nums.size());
        // 雙向擴展搜尋：距離從小到大 (0, 1, 2...)
        for (int dist = 0; dist < n; ++dist) {
            // 檢查左側：start - dist
            if (start - dist >= 0 && nums[start - dist] == target) {
                return dist;
            }
            // 檢查右側：start + dist
            if (start + dist < n && nums[start + dist] == target) {
                return dist;
            }
        }
        return -1; // 題目保證必有解，此處為防禦性回傳
    }
};
