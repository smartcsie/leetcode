/**
 * 題目：238. Product of Array Except Self (除自身以外陣列的乘積)
 * 難度：中等 (Medium)
 * 描述：在不使用除法且時間複雜度為 O(N) 的情況下，求出陣列中每個元素以外的乘積。
 * * 時間複雜度：O(N) - 兩次線性掃描。
 * 空間複雜度：O(1) - 除了回傳陣列外，僅使用常數空間。
 * * 優化思路：
 * 1. 前綴積：第一次遍歷計算每個位置左側所有元素的乘積。
 * 2. 後綴積：第二次遍歷從右向左，同時維護右側乘積並直接與前綴積相乘。
 * 3. 優化：直接使用輸出陣列儲存前綴積，再透過變數紀錄後綴積，達到空間極致。
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        
        // 第一次遍歷：res[i] 儲存 nums[0...i-1] 的乘積
        res[0] = 1;
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        
        // 第二次遍歷：維護 suffix product 並直接更新結果
        // 變數 right 用於儲存 nums[i+1...n-1] 的乘積
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= right; // 當前結果 = 前綴積 * 後綴積
            right *= nums[i]; // 更新後綴積，為下一個循環準備
        }
        
        return res;
    }
};
