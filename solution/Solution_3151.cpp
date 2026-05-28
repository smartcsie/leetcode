/**
 * 題目：3151. Special Array I (特殊陣列 I)
 * 難度：簡單 (Easy)
 * 描述：如果陣列中每一對相鄰元素的奇偶性皆不同，則稱為特殊陣列。
 * * 時間複雜度：O(N) - 遍歷陣列一次。
 * 空間複雜度：O(1) - 僅使用常數空間。
 */

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        // 陣列長度為 1 時直接返回 true，邏輯正確
        if (n <= 1) return true;

        for (int i = 0; i < n - 1; i++) {
            // 優化思路：
            // 兩數奇偶性相同代表 (num1 % 2) == (num2 % 2)
            // 即 (num1 & 1) == (num2 & 1)
            // 這裡直接判斷若相鄰兩數 parity 相等，即為 false
            if (((nums[i] ^ nums[i + 1]) & 1) == 0) {
                return false;
            }
        }
        return true;
    }
};
