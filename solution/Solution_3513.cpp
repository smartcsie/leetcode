/**
 * 題目：3513. Number of Unique XOR Triplets I
 * 描述：給你一個長度為 n 的整數陣列 nums（為 1 到 n 的排列），
 *       求所有滿足 i <= j <= k 的三元組 (i, j, k)，其 nums[i] ^ nums[j] ^ nums[k] 
 *       所能產生的「不同 XOR 數值」總共有多少種。
 * 
 * 解法思路：
 * 1. 若陣列長度 n 小於 3，透過數學規律或直接枚舉可知其產生的獨特 XOR 結果數量剛好為 n。
 * 2. 當 n >= 3 時，透過排列 XOR 的線性空間性質，其可生成的數值範圍取決於 n 的最高有效位元。
 * 3. 我們透過一個 while 迴圈計算 n 的位元長度：
 *    - 每次將 temp 右移（temp >>= 1），同時將答案左移（ans <<= 1）。
 *    - 這相當於找出大於或等於 n 的最小二進位區間邊界（即 2^(bit_length)）。
 * 4. 返回計算出來的 ans 即為所有可能的獨特 XOR 結果總數。
 */

class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        int n = nums.size();
        // 若長度小於 3，直接回傳 n
        if (n < 3) {
            return n;
        }
        int ans = 1;
        int temp = n;
        // 計算 n 的位元長度，並推算出可覆蓋的 XOR 總數空間
        while (temp > 0) {
            temp >>= 1;
            ans <<= 1;
        }
        return ans;
    }
};
