/**
 * 題目：1877. Minimize Maximum Pair Sum in Array
 * 描述：一個陣列的數對和（Pair Sum）是指陣列中任意兩個元素相加的和。
 *       給你一個長度為偶數的整數陣列 nums，請你將 nums 中的元素分成 n / 2 個數對，
 *       使得所有數對和中的「最大值」達到最小。返回這個最小的最大數對和。
 * 
 * 解法思路：
 * 1. 貪心策略（Greedy Strategy）：為了避免出現過大的「數對和」，我們必須利用「極大配極小」的原則。
 *    把全陣列由小到大排序後，讓最左邊（最小的元素）與最右邊（最大的元素）相加，以此類推。
 * 2. 使用 `ranges::sort`（C++20）將 `nums` 進行原地排序。
 * 3. 設置左右雙指針 `left = 0` 與 `right = nums.size() - 1`。
 * 4. 在 `left < right` 的迴圈中，計算當前雙指針相加的和 `val = nums[left++] + nums[right--]`。
 * 5. 用 `maxVal` 動態記錄並更新所有配對中的最大值，迴圈結束後返回 `maxVal`。
 */

class Solution {
public:
    int minPairSum(std::vector<int>& nums) {
        // 1. 將陣列由小到大排序
        std::ranges::sort(nums);
        int maxVal = 0;
        int left = 0;
        int right = nums.size() - 1;
        // 2. 利用雙指針「頭尾配對」
        while (left < right) {
            int val = nums[left++] + nums[right--];
            maxVal = std::max(maxVal, val);
        }
        return maxVal;
    }
};
