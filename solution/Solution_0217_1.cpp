/**
 * 題目：217. Contains Duplicate
 * 難度：簡單 (Easy)
 * 描述：判斷陣列中是否有重複元素。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （unordered_set 去重）：
 * 把所有元素放入 unordered_set，若 set 大小小於原陣列大小，代表有重複。
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uniqueSet(nums.begin(), nums.end());
        return nums.size() != uniqueSet.size();
    }
};