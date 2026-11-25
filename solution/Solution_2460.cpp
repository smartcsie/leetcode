/**
 * 題目：2460. Apply Operations to an Array (對陣列執行操作)
 * 難度：簡單 (Easy)
 * 描述：執行相鄰元素合併操作，最後將所有 0 移動到陣列末尾。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int fast = 0, slow = 0; fast < n; fast++) {
            // 先對 nums[i] 做這一步操作（與後一個相等就加倍，後一個歸零）
            if(fast + 1 < n && nums[fast] == nums[fast + 1]) {
                nums[fast] *= 2;
                nums[fast + 1] = 0;
            }
            // 操作完 nums[i] 就定案了，非 0 的往前搬到 slow
            if(nums[fast] != 0) swap(nums[slow++], nums[fast]);
        }
        return nums;
    }
};