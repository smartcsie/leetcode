/**
 * 題目：2966. Divide Array Into Arrays With Max Difference
 * 描述：給你一個整數陣列 nums 和一個整數 k。請將 nums 分割成大小為 3 的陣列，
 *       使得每個子陣列中任意兩數之差都不大於 k。若無法做到則返回空陣列。
 * 
 * 解法思路：
 * 1. 將 nums 陣列進行由小到大的排序。
 * 2. 排序後，每 3 個連續元素（nums[i], nums[i+1], nums[i+2]）會形成一組。
 * 3. 由於已經排序，該組的最大值為 nums[i+2]，最小值為 nums[i]。
 *    因此只要檢查 `nums[i + 2] - nums[i] <= k`，就能保證該組內所有元素兩兩之差皆不大於 k。
 * 4. 若符合條件則推入 ans；若有任何一組不符合，直接返回空陣列 `{}`。
 */

class Solution {
public:
    std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k) {
        // 1. 將數字排序
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        std::vector<std::vector<int>> ans;
        
        // 2. 每 3 個一組進行區段檢查
        for (int i = 0; i < n; i += 3) {
            // 因為已排序，只需檢查最大值與最小值的差是否 <= k
            if (nums[i + 2] - nums[i] <= k) {
                ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
            } else {
                return {}; // 不符合條件，無法完成分割
            }
        }
        
        return ans;
    }
};
