/**
 * 題目：1470. Shuffle the Array (重新排列陣列)
 * 難度：簡單 (Easy)
 * 描述：給定長度為 2n 的陣列，將其重排為 [x1, y1, x2, y2, ..., xn, yn]。
 * * 時間複雜度：O(N) - 遍歷一次陣列。
 * 空間複雜度：O(N) - 建立新的結果陣列。
 * * 優化思路：
 * 使用 `res.reserve(2 * n)` 預先配置記憶體，減少動態陣列擴充的開銷。
 */

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        // 優化點：預先配置記憶體，避免 push_back 時反覆擴容
        res.reserve(2 * n);
        
        for (int i = 0; i < n; i++) {
            res.push_back(nums[i]);
            res.push_back(nums[i + n]);
        }
        
        return res;
    }
};
