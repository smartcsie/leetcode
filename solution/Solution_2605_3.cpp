/**
 * 題目：2605. Form Smallest Number From Two Digit Arrays
 * 難度：簡單 (Easy)
 * 描述：從兩個陣列各取一個數字，組成最小的兩位數或一位數。
 *
 * 時間複雜度：O(N+M)
 * 空間複雜度：O(M)
 *
 * 解法思路：
 * （unordered_set 版）：
 * 用 unordered_set 存 nums2，遍歷 nums1 找公共最小值，無公共值則取各自最小組合。
 */
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        unordered_set set2(nums2.begin(), nums2.end());
        int common_min = INT_MAX;
        for(const int& num : nums1) {
            if(set2.count(num)) common_min = min(common_min, num);
        }
        if(common_min != INT_MAX) return common_min;
        int min1 = *min_element(nums1.begin(), nums1.end());
        int min2 = *min_element(nums2.begin(), nums2.end());
        return min1 > min2 ? min2 * 10 + min1 : min1 * 10 + min2;
    }
};