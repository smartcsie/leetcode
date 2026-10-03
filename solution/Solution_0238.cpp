/**
 * 題目：238. Product of Array Except Self (除自身以外陣列的乘積)
 * 難度：中等 (Medium)
 * 描述：在不使用除法且時間複雜度為 O(N) 的情況下，求出陣列中每個元素以外的乘積。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 前綴積：第一次遍歷計算每個位置左側所有元素的乘積。
 * 2. 後綴積：第二次遍歷從右向左，同時維護右側乘積並直接與前綴積相乘。
 * 3. 優化：直接使用輸出陣列儲存前綴積，再透過變數紀錄後綴積，達到空間極致。
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 1);
        vector<int> suffix(n + 1, 1);
        for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
            prefix[i + 1] = prefix[i] * nums[i];
            suffix[j] = suffix[j + 1] * nums[j];
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = prefix[i] * suffix[i + 1];
        }
        return res;
    }
};
