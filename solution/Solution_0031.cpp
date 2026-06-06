/**
 * 題目：31. Next Permutation (下一個排列)
 * 難度：中等 (Medium)
 * 描述：將陣列重排為字典序中的下一個排列，若已是最大則循環至最小。
 * * 時間複雜度：O(N) - 兩次線性掃描。
 * 空間複雜度：O(1) - 原地操作，無額外記憶體開銷。
 * * 設計思路：
 * 1. 從右向左找到第一個 `nums[i] < nums[i + 1]` 的位置，這代表序列不再遞增。
 * 2. 若存在此位置，在 `i` 的右側找到第一個比 `nums[i]` 大的元素進行交換。
 * 3. 最後，將 `i` 右側的序列反轉，使其變成最小排列。
 */

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // 1. 尋找轉折點：找到第一個逆序對，nums[i] < nums[i+1]
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }

        // 2. 若找到轉折點，尋找交換對象
        if (i >= 0) {
            int j = n - 1;
            // 尋找第一個大於 nums[i] 的元素，因為右側已遞減，由右往左找即可
            while (nums[j] <= nums[i]) {
                --j;
            }
            std::swap(nums[i], nums[j]);
        }

        // 3. 反轉 i 之後的所有元素，將遞減序列變為遞增序列
        // 這是因為 i 之後原本是遞減的，反轉後是該位置能達到的最小值
        int left = i + 1;
        int right = n - 1;
        while (left < right) {
            std::swap(nums[left++], nums[right--]);
        }
    }
};
