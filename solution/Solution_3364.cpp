/**
 * 題目：3364. Minimum Positive Sum Subarray
 * 描述：尋找長度在 [l, r] 之間的子陣列，使得其總和 > 0，並求出所有符合條件的總和中的最小值。
 *       若不存在任何正數總和的子陣列，則回傳 -1。
 * 
 * 解法思路：
 * 1. 前綴和 (Prefix Sum)：子陣列和可以用 psum[i] - psum[j] 來表示（其中 i - j 介於 [l, r] 之間）。
 * 2. 轉換為不等式：我們希望 psum[i] - psum[j] > 0 且盡量小，也就是希望 psum[j] < psum[i]，
 *    並且讓 psum[j] 越接近 psum[i] 越好。
 * 3. 滑動視窗 + Multiset：利用 std::multiset 維護符合長度限制的 psum[j]，
 *    並透過 lower_bound 快速尋找小於且最接近 psum[i] 的前綴和。
 */

class Solution {
public:
    int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
        int n = nums.size();
        // 1. 建立前綴和陣列，psum[i] 代表前 i 個元素的總和
        std::vector<int> psum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            psum[i] = psum[i - 1] + nums[i - 1];
        }
        
        int minSum = INT_MAX;
        std::multiset<int> window;
        
        // 2. 以 i 作為子陣列的結束位置（從 l 到 n）
        for (int i = l; i <= n; i++) {
            // 將符合長度下限 (i - l) 的前綴和加入視窗
            window.insert(psum[i - l]);
            
            // 若視窗大小超過長度上限 (r)，將過期的前綴和移除
            if (i > r) {
                window.erase(window.find(psum[i - r - 1]));
            }
            
            // 3. 在視窗中尋找大於或等於 psum[i] 的第一個元素
            auto it = window.lower_bound(psum[i]);
            // 我們需要嚴格小於 psum[i] 的值（確保 psum[i] - psum[j] > 0）
            if (it != window.begin()) {
                int bestK = *(--it); // 取得小於且最接近 psum[i] 的前綴和
                minSum = std::min(minSum, psum[i] - bestK);
            }
        }
        
        // 若 minSum 未被更新，代表沒有符合條件的正數總和子陣列，回傳 -1
        return minSum == INT_MAX ? -1 : minSum;
    }
};
