/**
 * 題目：152. Maximum Product Subarray
 * 難度：中等 (Medium)
 * 描述：給定一個整數陣列，找出乘積最大的連續子陣列，回傳其最大乘積。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （Kadane 變體，同時維護最大值和最小值）：
 * 乘積因為有負數，負負得正，所以需要同時追蹤：
 * - mx：以當前元素結尾的最大乘積
 * - mn：以當前元素結尾的最小乘積（負數，遇到負數時可翻轉成最大）
 *
 * 每步對三個候選值取 min/max：
 * - x        → 拋棄前面，從當前元素重新開始
 * - x * mx   → 延續最大乘積
 * - x * mn   → 負負得正，最小值乘以負數變最大
 *
 * 比起 swap(mn, mx) 的寫法，直接列出三個候選值更直觀易記。
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int mx = nums[0];
        int mn = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int x = nums[i];
            auto [newMn , newMx] = minmax({mn * x, x , mx * x});
            mn = newMn;
            mx = newMx;
            ans = max(mx, ans);
        }
        return ans;
    }
};