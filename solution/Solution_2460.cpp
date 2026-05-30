/**
 * 題目：2460. Apply Operations to an Array (對陣列執行操作)
 * 難度：簡單 (Easy)
 * 描述：執行相鄰元素合併操作，最後將所有 0 移動到陣列末尾。
 * * 時間複雜度：O(N) - 兩次線性掃描。
 * 空間複雜度：O(1) - 原地操作 (In-place)。
 */

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        
        // 第一階段：模擬操作，處理相鄰元素
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        
        // 第二階段：原地將所有非零元素移至陣列前端 (雙指標法)
        // pos 記錄下一個非零元素要存放的位置
        int pos = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                // 將非零元素交換到前面
                swap(nums[pos], nums[i]);
                pos++;
            }
        }
        
        return nums;
    }
};
