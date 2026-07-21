/**
 * 題目：Minimum Swaps to Move Zeros to End
 * 描述：給定一個整數陣列 nums，請透過最少次數的元素交換，
 *       將陣列中所有的 0 移動到陣列的結尾處，並返回所需的最小交換次數。
 * 
 * 解法思路：
 * 1. 使用雙指標（Two Pointers），分別從陣列最左邊（left）與最右邊（right）開始。
 * 2. left 指標負責向右尋找第一個「等於 0」的元素。
 * 3. right 指標負責向左尋找第一個「不等於 0」的元素。
 * 4. 當找到一左一右不合規定的元素時，將其進行 `swap` 交換，並將交換次數 `count` 加 1。
 * 5. 重複直到 left 與 right 指標相遇為止。
 */

class Solution {
public:
    int minimumSwaps(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int count = 0;
        while (left < right) {
            // left 向右尋找不等於 0 的元素（代表它卡在前面，需要被換到後面）
            // （註：原程式碼邏輯為尋找 nums[left] != 0 的位置準備與右邊的 0 交換）
            while (left < right && nums[left] != 0) {
                left++;
            }
            // right 向左尋找等於 0 的元素（代表它卡在後面，需要被換到前面）
            // （註：原程式碼邏輯為尋找 nums[right] == 0 的位置準備與左邊的非 0 交換）
            while (left < right && nums[right] == 0) {
                right--;
            }
            // 若雙指標未交錯，執行交換並累加計數
            if (left < right) {
                std::swap(nums[left++], nums[right--]);
                count++;
            }
        }
        return count;
    }
};
