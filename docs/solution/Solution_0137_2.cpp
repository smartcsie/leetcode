/**
 * 題目：137. Single Number II (只出現一次的數字 II)
 * 難度：中等 (Medium)
 * 描述：在每個元素都出現三次的陣列中，找出唯一出現一次的數字。
 * * 解題思路 (逐位統計法)：
 * 1. 將整數視為 32 個獨立的位元 (bit)。
 * 2. 對於每一個位元位置 i (0 到 31)，計算陣列中所有數字在該位元為 1 的總次數。
 * 3. 由於除了目標數字外，其餘數字皆出現三次，因此該位元位置上的總和 sum 必定為 (3 * N + target_bit)。
 * 4. 將總和對 3 取餘數 (sum % 3)，留下來的值即為目標數字在該位元的狀態。
 * 5. 將結果組合成最終的整數。
 * * 時間複雜度：O(N)，實際為 O(32 * N)，常數級別。
 * 空間複雜度：O(1)，僅使用常數空間。
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
        int sum = 0;
        for (const int num : nums)
            sum += num >> i & 1;
            sum %= 3;
            ans |= sum << i;
        }
        return ans;
    }
};
