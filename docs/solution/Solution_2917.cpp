/**
 * 題目：2917. Find the K-or of an Array (陣列的 K-or 值)
 * 難度：簡單 (Easy)
 * 描述：給定一個整數陣列 nums 和一個整數 k。K-or 值的定義為：若某個位元在 nums 中
 * 至少出現 k 次，則該位元在 K-or 值中也為 1，否則為 0。
 * * 時間複雜度：O(N * 32) = O(N)，其中 N 是陣列長度。
 * 空間複雜度：O(1)。
 * * 解法思路：
 * 1. 由於整數最大為 32 位元，我們可以遍歷從 0 到 31 的每一個位元位置。
 * 2. 對於每一個位元 i，遍歷整個陣列統計該位元為 1 的總次數 (count)。
 * 3. 若 `count >= k`，表示該位元滿足 K-or 條件，使用 `ans |= (1 << i)` 將其寫入答案。
 */

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        
        // 對於 32 個 bit 位中的每一個進行統計
        for (int i = 0; i < 32; i++) {
            int count = 0;
            // 遍歷所有數字，檢查第 i 個 bit 是否為 1
            for (int num : nums) {
                if ((num >> i) & 1) {
                    count++;
                }
            }
            
            // 若滿足 K 次以上，則該 bit 在結果中為 1
            if (count >= k) {
                ans |= (1 << i);
            }
        }
        
        return ans;
    }
};
