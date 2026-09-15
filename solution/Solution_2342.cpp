/**
 * 題目：2342. Max Sum of a Pair With Equal Sum of Digits
 * 難度：中等 (Medium)
 * 描述：找到數位和相等的兩個數字，並使它們的和最大化。
 * 優化重點：
 * 1. 一次遍歷：在遍歷過程中即時更新最大和與分組最大值，無需二次排序。
 * 2. 映射表：利用 Hash Map 以 O(1) 平均時間查找該數位和之前的最大值。
 *
 * 時間複雜度：O(N*logM)
 * 空間複雜度：O(N)
 */

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<vector<int>> mx(82,vector<int>(2, 0));
        int ans = -1;
        for(const int& num : nums) {
            int x = num;
            int d = 0;
            while(x > 0) {
                d += x % 10;
                x /= 10;
            }
            if(num > mx[d][0]) {
                mx[d][1] = mx[d][0];
                mx[d][0] = num;
            } else if(num > mx[d][1]) {
                 mx[d][1] = num;
            }
            if(mx[d][1] != 0) ans = max(ans, mx[d][1] + mx[d][0]);
        }
        return ans;
    }
};