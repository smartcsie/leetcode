/**
 * 題目：581. Shortest Unsorted Continuous Subarray (最短無序連續子陣列)
 * 難度：中等 (Medium)
 * 描述：給定一個整數陣列 nums，找出一個最短的連續子陣列，
 *       如果將這個子陣列由小到大排序，那麼整個陣列就會變成由小到大排序。
 *       請回傳這個最短子陣列的長度。
 *
 * 時間複雜度：O(N log N) - 主要成本來自對 nums 複製後排序，排序需要 O(N log N)。
 * 空間複雜度：O(N) - 需要額外的 sortedNums 陣列儲存排序後的結果。
 *
 * 解法思路：
 * 1. 對照排序後結果 (Compare with Sorted Version)：
 *    - 先複製一份 nums 並排序成 sortedNums，正確答案的邊界就是原陣列與排序後陣列開始不同的地方。
 * 2. 從左找第一個不同的位置：
 *    - 用 left 從陣列開頭開始，只要 nums[left] 跟 sortedNums[left] 相同就往右移動，
 *      直到找到第一個不一致的位置，這就是無序區間的左邊界。
 * 3. 從右找第一個不同的位置：
 *    - 同理，用 right 從陣列尾端開始，只要 nums[right] 跟 sortedNums[right] 相同就往左移動，
 *      直到找到第一個不一致的位置，這就是無序區間的右邊界。
 * 4. 計算長度：
 *    - 如果 right < left，代表整個陣列本來就是排序好的，回傳 0；
 *      否則回傳 right - left + 1 作為最短無序子陣列的長度。
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        int n = nums.size();
        int left = 0, right = n -1;
        while(left < n && nums[left]== sortedNums[left]) left++;
        while(right  > 0 && nums[right] == sortedNums[right]) right--;
        return (right < left) ? 0 : (right - left + 1);
    }
};
