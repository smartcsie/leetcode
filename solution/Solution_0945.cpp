/**
 * 題目：945. Minimum Increment to Make Array Unique
 * 難度：中等 (Medium)
 * 描述：透過增加陣列元素值，使所有元素互不相同。
 * 優化重點：
 * 1. 貪心策略：排序後，若後一個數字小於等於前一個數字的最小可用值，則補足差額。
 * 2. 空間效率：原地計算，僅需 O(1) 額外空間。
 * 3. 溢位防護：使用 long long 處理累積增量 (ans)，防止極大測資下的溢位。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ans = 0;
        int minAvailable = 0;
        sort(nums.begin(), nums.end());
        for(const int& x : nums) {
            ans += max(minAvailable - x, 0);
            minAvailable = max(minAvailable, x) + 1;
        }
        return ans;
    }
};