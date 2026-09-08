/**
 * 題目：217. Contains Duplicate
 * 難度：簡單 (Easy)
 * 描述：判斷陣列中是否有重複元素。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(logN)
 *
 * 解法思路：
 * （排序 + std::unique）：
 * 排序後用 unique 找到第一個重複元素的位置，若不在 end() 代表有重複。
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        ranges::sort(nums);
        if(unique(nums.begin(), nums.end()) != nums.end()) return true;
        return false;
    }
};