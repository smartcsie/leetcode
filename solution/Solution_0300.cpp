/**
 * 題目：300. Longest Increasing Subsequence (最長遞增子序列)
 * 難度：中等 (Medium)
 * 描述：給你一個整數陣列 nums，找到其中最長嚴格遞增子序列的長度。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(N)
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) {
                tails.push_back(x);
            } else {
                *it = x;
            }
        }
        return tails.size();
    }
};
