/**
 * 題目：16. 3Sum Closest (最接近的三數之和)
 * 難度：中等 (Medium)
 * 描述：在陣列中找出三個數字，使其和最接近 target。
 * * 時間複雜度：O(N^2) - 排序 O(N log N)，外層迴圈 O(N)，內層雙指標 O(N)。
 * 空間複雜度：O(1) - 若不計排序所需的堆疊空間。
 * * 解法思路：
 * 1. 先將陣列排序，這有利於使用雙指標快速收斂目標值。
 * 2. 遍歷每一個元素 `nums[i]` 作為第一個數。
 * 3. 使用 `left = i + 1` 和 `right = n - 1` 作為雙指標。
 * 4. 計算 `sum = nums[i] + nums[left] + nums[right]`：
 * - 若 `sum` 更接近 `target`，則更新 `closest`。
 * - 若 `sum < target`，因為陣列已排序，將 `left` 右移以增大總和。
 * - 若 `sum > target`，將 `right` 左移以減小總和。
 * - 若 `sum == target`，直接回傳，這是最接近的狀態。
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] + nums[i+1] + nums[i+2] > target) {
                if (abs(nums[i] + nums[i+1] + nums[i+2] - target) < abs(closest - target)) {
                    closest = nums[i] + nums[i+1] + nums[i+2];
                }
                break; 
            }
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target) return sum; // 找到完美匹配，直接返回
                if (abs(target - sum) < abs(target - closest)) {
                    closest = sum;
                }
                if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return closest;
    }
};
