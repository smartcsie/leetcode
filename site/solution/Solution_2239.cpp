/**
 * 題目：2239. Find Closest Number to Zero (找到最接近 0 的數字)
 * 難度：簡單 (Easy)
 * 描述：在陣列中找到絕對值最小的數。若有多個，回傳最大值。
 * * 時間複雜度：O(N) - 遍歷陣列一次。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 設計思路：
 * 1. 使用 `closest` 記錄目前最小的絕對值。
 * 2. 使用 `res` 記錄該絕對值對應的數值。
 * 3. 遍歷過程中更新最小絕對值；若絕對值相同，則保留兩者間較大者。
 */

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int min_val = INT_MAX;
        for(const int& num : nums) {
            if(num == 0) return 0;
            else if(abs(num) < abs(min_val)) min_val = num;
            else if(abs(num) == abs(min_val) && num > 0) min_val = num;
        }
        return min_val;
    }
};
