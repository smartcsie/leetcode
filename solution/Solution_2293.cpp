/**
 * 題目：2293. Min Max Game
 * 描述：給定一個長度為 2 的冪次的整數陣列 nums。
 *       重覆以下步驟直到 nums 長度為 1：
 *       - 建立一個新陣列 newNums，長度為一半。
 *       - 對於每個偶數索引 i，newNums[i] = min(nums[2 * i], nums[2 * i + 1])。
 *       - 對於每個奇數索引 i，newNums[i] = max(nums[2 * i], nums[2 * i + 1])。
 *       返回最後剩下的唯一數字。
 * 
 * 解法思路：
 * 1. 使用 while 迴圈持續執行，直到 nums.size() == 1。
 * 2. 宣告一個 `minmax` 複製當前的 nums 狀態作為讀取來源。
 * 3. 將原 `nums` 透過 `resize()` 縮減為原來的一半大小。
 * 4. 透過迴圈每次跳 2 格（i += 2），根據 `(i / 2)` 的奇偶性決定填入最小值或最大值。
 * 5. 迴圈結束後，nums[0] 即為最終留下的唯一答案。
 */

class Solution {
public:
    int minMaxGame(std::vector<int>& nums) {
        while (nums.size() > 1) {
            // 複製一份當前的狀態供對照讀取
            std::vector<int> minmax = nums;
            
            // 將 nums 調整為新的一半大小
            nums.resize(minmax.size() / 2, 0);
            
            // 兩兩一組進行 min / max 運算
            for (int i = 0; i < minmax.size(); i += 2) {
                if ((i / 2) % 2 == 0) {
                    nums[i / 2] = std::min(minmax[i], minmax[i + 1]);
                } else {
                    nums[i / 2] = std::max(minmax[i], minmax[i + 1]);
                }
            }
        }
        
        return nums[0];
    }
};
