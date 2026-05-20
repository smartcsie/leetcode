/**
 * 題目：1. Two Sum (兩數之和)
 * 難度：簡單 (Easy)
 * 描述：給定一個整數陣列 nums 和一個目標值 target，找出和為目標值的兩個整數並回傳索引。
 * 
 * 時間複雜度：O(n) - 僅需遍歷陣列一次，雜湊表查詢平均為 O(1)。
 * 空間複雜度：O(n) - 最壞情況下需將 n-1 個元素存入雜湊表。
 * 
 * 解法思路：
 * 1. 使用一個 unordered_map 紀錄 {數值 : 索引}。
 * 2. 遍歷 nums[i] 時，計算所需的補數 complement = target - nums[i]。
 * 3. 檢查 complement 是否已存在於 map 中：
 *    - 若存在，代表找到了配對，回傳 {map[complement], i}。
 *    - 若不存在，將當前 nums[i] 存入 map，供後續元素配對。
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0 ; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(map.contains(complement)) {
                return {map[complement] , i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
