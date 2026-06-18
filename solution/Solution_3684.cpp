/**
 * 題目：3684. Maximize Sum of At Most K Distinct Elements (最大化最多 K 個不重複元素的總和)
 * 難度：簡單 (Easy)
 * 描述：在陣列中挑選最多 K 個不重複的數字，使其總和最大化。
 * * 時間複雜度：O(N log N)，由排序主導。
 * 空間複雜度：O(N)，用於儲存去重後的結果。
 * * 優化思路：
 * 1. 簡化邏輯：使用 sort 後反向遍歷，避免手動計算邊界索引。
 * 2. 安全性：直接使用 vector::rbegin() 反向選取前 K 個。
 */

class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()) , nums.end());
        int count = min(static_cast<int>(nums.size()), k);
        vector<int> res;
        res.reserve(count);
        for(auto it = nums.rbegin(); it != nums.rbegin() + count; it++) {
            res.push_back(*it);
        }
        return res;
    }
};
