/**
 * 題目：1470. Shuffle the Array (重新排列陣列)
 * 難度：簡單 (Easy)
 * 描述：給定長度為 2n 的陣列，將其重排為 [x1, y1, x2, y2, ..., xn, yn]。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 使用 `res.reserve(2 * n)` 預先配置記憶體，減少動態陣列擴充的開銷。
 */

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(n * 2);
        for(int i = 0 ; i < n;  i++) {
            ans[i * 2] = nums[i];
            ans[i * 2 + 1] = nums[i + n];
        }
        return ans;
    }
};
