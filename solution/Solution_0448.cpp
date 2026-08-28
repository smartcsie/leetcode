
/**
 * 題目：待補充
 * 難度：待補充
 * 描述：待補充
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 原地標記法 (In-place Marking)
 * 1. 題目要求找出 [1, n] 範圍內哪些數字沒有出現在長度為 n 的陣列中。
 * 2. 限制：不使用額外空間（O(1) space），且時間複雜度為 O(n)。
 * 3. 策略：
 * - 遍歷陣列，將每個數字對應的索引位置（nums[abs(x)-1]）標記為負數。
 * - 標記完成後，再次遍歷陣列。
 * - 如果某個位置 nums[i] 仍然是正數，代表數字 (i+1) 從未出現過。
 */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            if(nums[idx] > 0) nums[idx] *= -1;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) ans.push_back(i + 1);
        }
    }
};
