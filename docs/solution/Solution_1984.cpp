/**
 * 題目：1984. Minimum Difference Between Highest and Lowest of K Scores
 * 難度：簡單 (Easy)
 * 描述：在陣列中選出 k 個分數，使得最高分與最低分之差最小。
 * * 時間複雜度：O(N log N) - 受限於排序操作。
 * 空間複雜度：O(1) - 原地排序，僅使用常數空間。
 * * 優化思路：
 * 1. 排序：只有將數字排序，才能讓「選取 k 個數」的極差 (Highest - Lowest) 最小化。
 * 2. 滑動視窗：排序後，長度為 k 的區間內的極差必為 `nums[i + k - 1] - nums[i]`。
 */

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(nums.size() == 1) return 0;
        sort(nums.begin(), nums.end());
        int min = INT_MAX;
        for(int i = 0; i < nums.size() - (k-1); i++) {
            min = std::min(min, nums[i + (k-1)] - nums[i]);
        }
        return min;
    }
};
