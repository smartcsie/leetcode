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
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        for(int fast = 0 , slow = 0; fast < nums.size(); fast++) {
            if(nums[fast] != 0) {
                swap(nums[fast], nums[slow]);
                slow++;
            }
        }
        return nums;
    }
};
