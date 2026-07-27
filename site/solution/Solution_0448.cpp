
/**
 * 解題思路：原地標記法 (In-place Marking)
 * 1. 題目要求找出 [1, n] 範圍內哪些數字沒有出現在長度為 n 的陣列中。
 * 2. 限制：不使用額外空間（O(1) space），且時間複雜度為 O(n)。
 * 3. 策略：
 *    - 遍歷陣列，將每個數字對應的索引位置（nums[abs(x)-1]）標記為負數。
 *    - 標記完成後，再次遍歷陣列。
 *    - 如果某個位置 nums[i] 仍然是正數，代表數字 (i+1) 從未出現過。
 * 
 * Time Complexity: O(n) - 總共遍歷兩次陣列。
 * Space Complexity: O(1) - 除了回傳結果外，不使用額外空間。
 */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 第一遍：標記出現過的數字
        for (int i = 0; i < nums.size(); i++) {
            // 找到該數字應該對應的索引
            int index = abs(nums[i]) - 1;
            // 如果該位置還是正數，將其轉為負數（標記為「已存在」）
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        
        vector<int> ans;
        // 第二遍：尋找未被標記（仍為正數）的位置
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                // 索引 i 對應的數字是 i + 1
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};
