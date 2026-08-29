/**
 * 題目：3684. Maximize Sum of At Most K Distinct Elements (最大化最多 K 個不重複元素的總和)
 * 難度：簡單 (Easy)
 * 描述：在陣列中挑選最多 K 個不重複的數字，使其總和最大化。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 簡化邏輯：使用 sort 後反向遍歷，避免手動計算邊界索引。
 * 2. 安全性：直接使用 vector::rbegin() 反向選取前 K 個。
 */

class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<>());
        auto it = unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());
        if(nums.size() > k) nums.resize(k);
        return nums;
    }
};