/**
 * 解題思路：哈希表記錄最後出現位置 (Hash Map)
 * 1. 題目要求尋找是否存在兩個索引 i, j，使得 nums[i] == nums[j] 且 abs(i - j) <= k。
 * 2. 我們使用 unordered_map<int, int>，其中：
 *    - Key: 數字的值。
 *    - Value: 該數字「最近一次」出現的索引位置。
 * 3. 遍歷陣列時：
 *    - 如果當前數字已存在於 map 中，檢查「當前索引 i」與「上次出現索引 map[num]」的差值。
 *    - 如果差值 <= k，代表找到符合條件的對數，回傳 true。
 *    - 無論是否符合差值，都要更新 map[num] 為最新的索引 i（因為越後面的索引，離未來的數字越近，越容易滿足 <= k）。
 * 
 * Time Complexity: O(n) - 遍歷陣列一次。
 * Space Complexity: O(min(n, k)) - 哈希表最多存儲 n 個元素；若用滑動窗口邏輯實作則為 k。
 */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i = 0 ; i < nums.size(); i++) {
            if(map.find(nums[i]) != map.end() && i-map[nums[i]] <= k) return true;
            map[nums[i]] = i;
        }
        return false;
    }
};
