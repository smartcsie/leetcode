/**
 * 題目：219. Contains Duplicate II (存在重複元素 II)
 * 難度：簡單 (Easy)
 * 描述：檢查陣列中是否有兩個不同的索引 i 和 j，滿足 nums[i] == nums[j] 且 |i - j| <= k。
 * * 時間複雜度：O(N) - 每個元素最多被插入與刪除一次。
 * 空間複雜度：O(K) - 視窗大小最大為 K。
 */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        
        for (int i = 0; i < nums.size(); i++) {
            // 1. 如果視窗超過大小 k，移除最左邊的元素
            // i 是當前索引，若視窗維持大小為 k，則左邊界為 i - k - 1
            if (i > k) {
                window.erase(nums[i - k - 1]);
            }
            
            // 2. 檢查當前元素是否已存在視窗中
            // 如果存在，代表在距離 k 內找到了重複
            if (window.count(nums[i])) {
                return true;
            }
            
            // 3. 將當前元素加入視窗
            window.insert(nums[i]);
        }
        
        return false;
    }
};
