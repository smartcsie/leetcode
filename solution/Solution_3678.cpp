/**
 * 題目：3678. Smallest Absent Positive Greater Than Average (大於平均值的最小缺失正整數)
 * 難度：簡單 (Easy)
 * 描述：找到一個大於數列平均值的最小整數，該數字不在原數列中。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 使用 long long 防止求和溢位。
 * 2. 精確計算平均值（向上取整）。
 */

class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size();
        unordered_set sets(nums.begin(), nums.end());
        int sum  = accumulate(nums.begin(), nums.end(), 0) ;
        int avg = sum <= 0 ? 1 : sum / n + 1;
        for(int x = avg ; ; x++) {
            if(!sets.contains(x)) return x;
        }
        return -1;
    }
};