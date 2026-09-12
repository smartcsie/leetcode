/**
 * 題目：3314. Construct the Minimum Bitwise Array I
 * 難度：簡單 (Easy)
 * 分類主題：bit-manipulation
 * 描述：給定一個質數陣列 nums，對每個 nums[i]，求最小的 ans[i]，使得
 * `ans[i] | (ans[i]+1) == nums[i]`；找不到就回傳 -1。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （位元技巧：找出「最低位的 0 在哪裡」，這是這題的核心）：
 * 1. **特例**：`nums[i] == 2`（二進位 `10`）時無解，回傳 -1——因為
 *    2 是唯一的偶質數，它的最低位是 0，不符合下面推導出來的規則
 *    （其他質數都是奇數，最低位一定是 1）。
 * 2. **核心觀察**：對一個奇數 `p`，如果 `x = p` 扣掉「p 的二進位表示
 *    法裡，從最低位往上數，第一段連續 1 那一段的最高位元」，這個 x
 *    會滿足 `x | (x+1) == p`，而且是滿足這個條件的最小值。
 * 3. 舉例：`p=7`（`111`），最低位開始的連續 1 是 bit0、1、2（值 1、
 *    2、4），這段的最高位是 4，`x = 7 - 4 = 3`（`011`），驗證：
 *    `3 | 4 = 7`，成立。
 * 4. **`lowestZeroBit = ~nums[i] & -~nums[i]`** 這行是關鍵：
 *    `x & -x` 是經典技巧，能取出整數 `x` 二進位裡「最低位的 1」；
 *    這裡不是對 `nums[i]` 本身用，而是對它的反相 `~nums[i]` 用——
 *    `nums[i]` 哪裡是 0，`~nums[i]` 那裡就是 1，所以「`~nums[i]`
 *    最低位的 1」剛好對應「`nums[i]` 最低位的 0」。這一行位元運算
 *    直接算出「連續 1 那一段的下一個位置（第一個 0 的位置）」，
 *    效果等同原本用 `while` 迴圈逐位往上找的過程，只是不用迴圈。
 * 5. `lowestZeroBit >> 1` 把這個「第一個 0 的位置」往右移一位，
 *    剛好對應到「連續 1 那一段的最高位元」，`nums[i]` 扣掉這個值
 *    就是答案。
 */
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0; i < n ;i++) {
            if (nums[i] == 2) {
                ans[i] = -1;
                continue;
            }
            int lowestZeroBit = 1;
            while ((nums[i] & lowestZeroBit) != 0) lowestZeroBit <<= 1;
            ans[i] = nums[i] - (lowestZeroBit >> 1);
        }
        return ans;
    }
};