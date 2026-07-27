/**
 * 題目：324. Wiggle Sort II (搖擺排序 II)
 * 難度：困難 (Hard)
 * 描述：重排陣列使 nums[0] < nums[1] > nums[2] < nums[3] ...
 * * 時間複雜度：O(N) - nth_element 平均時間為 O(N)，三向切分也為 O(N)。
 * 空間複雜度：O(1) - 原地操作。
 * * 優化思路：
 * 1. 找中位數：使用 nth_element 快速找到陣列中位數。
 * 2. 虛擬映射：將陣列視為一個循環的虛擬結構，索引映射公式為 (1 + 2 * i) % (n | 1)。
 * 3. 三向切分 (Dutch National Flag problem)：根據中位數將陣列分為大、中、小三部分。
 */

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        // 1. 找到中位數
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;

        // 2. 虛擬映射函數：將邏輯索引映射到實際陣列位置
        auto getIndex = [&](int i) {
            return (1 + 2 * i) % (n | 1);
        };

        // 3. 三向切分 (Dutch National Flag)
        int left = 0, current = 0, right = n - 1;
        while (current <= right) {
            if (nums[getIndex(current)] > mid) {
                swap(nums[getIndex(left)], nums[getIndex(current)]);
                left++;
                current++;
            } else if (nums[getIndex(current)] < mid) {
                swap(nums[getIndex(current)], nums[getIndex(right)]);
                right--;
            } else {
                current++;
            }
        }
    }
};
