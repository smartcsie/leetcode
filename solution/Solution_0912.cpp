/**
 * 題目：912. Sort an Array (排序陣列)
 * 難度：中等 (Medium)
 * 描述：給你一個整數陣列 nums，請你將該陣列升序排列。
 * 
 * 時間複雜度：平均 O(n log n)，最壞 O(n^2)（但在取中間值或隨機 pivot 下極難發生）。
 * 空間複雜度：O(log n) - 遞迴產生的棧空間。
 * 
 * 解法思路：
 * 採用快速排序 (Quick Sort) 的 Hoare Partition 實作：
 * 1. 選擇 Pivot：這裡選擇中間位置的元素 nums[(left + right) / 2]。
 * 2. 雙指標碰撞：i 從左向右找 >= pivot 的數，j 從右向左找 <= pivot 的數。
 * 3. 交換：若 i < j 則交換，確保左側都較小，右側都較大。
 * 4. 遞迴：以 j 為分界點，切分為 [left, j] 與 [j + 1, right] 兩部分繼續排序。
 */

class Solution {
public:
    void quick_sort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int i = left - 1, j = right + 1;
        int x = nums[(left + r) >> 1];
        while (i < j) {
            do i++; while (nums[i] < x);
            do j--; while (nums[j] > x);
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        quick_sort(nums, left, j);
        quick_sort(nums, j + 1, right);
    };
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};
