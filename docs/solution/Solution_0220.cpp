/**
 * 題目：220. Contains Duplicate III
 * 難度：困難 (Hard)
 * 描述：判斷陣列中是否存在兩個索引 i 和 j，使得 |nums[i] - nums[j]| <= valueDiff 且 |i - j| <= indexDiff。
 * * 時間複雜度：O(N log(min(N, k))) - k 為 indexDiff，在視窗內進行樹狀搜尋。
 * 空間複雜度：O(min(N, k)) - 維護一個大小為 k 的滑動視窗。
 * * 優化思路：
 * 1. 使用 `std::set` 維護滑動視窗，其底層為紅黑樹，支援 O(log K) 範圍搜尋。
 * 2. 每次窗口大小超過 `indexDiff`，移除最舊的元素。
 * 3. 搜尋 `[nums[i] - valueDiff, nums[i] + valueDiff]` 的元素。
 */

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        // 使用 set 紀錄視窗內的元素
        set<long long> s;
        
        for (int i = 0; i < nums.size(); ++i) {
            // 保持視窗大小，移除最舊的元素
            if (i > indexDiff) {
                s.erase((long long)nums[i - indexDiff - 1]);
            }
            
            // 在 set 中尋找第一個大於等於 (nums[i] - valueDiff) 的元素
            auto it = s.lower_bound((long long)nums[i] - valueDiff);
            
            // 若找到且滿足絕對值差 <= valueDiff，則存在符合條件的數對
            if (it != s.end() && *it <= (long long)nums[i] + valueDiff) {
                return true;
            }
            
            // 加入當前元素
            s.insert((long long)nums[i]);
        }
        
        return false;
    }
};
