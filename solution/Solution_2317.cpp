/**
 * 題目：2317. Maximum XOR After Operations (操作後的最大 XOR 值)
 * 難度：中等 (Medium)
 * 描述：你可以對陣列中的任意元素 nums[i] 執行操作：nums[i] = nums[i] XOR (nums[i] & AND)，
 *      其中 AND 是陣列中任意數目的元素進行按位與 (bitwise AND) 的結果。
 *      目標是讓所有元素的 XOR 值最大化。
 * 
 * 解法思路：
 * 1. 觀察操作：nums[i] = nums[i] XOR (nums[i] & ANY_AND_RESULT)
 *    本質上，這個操作允許我們將 nums[i] 的任意位元「置為 0」。
 * 2. 最終目標是讓所有數的 XOR 和最大。
 * 3. 數學推導：
 *    只要某個位元在陣列中至少有一個數該位元為 1，我們就可以透過 XOR 操作，
 *    將其他數的該位元調整為 0，從而使得最終的 XOR 結果在該位元上為 1。
 * 4. 因此，最終的最大 XOR 和等於陣列中所有數字進行按位或 (OR) 的結果。
 * 
 * 時間複雜度：O(n) - 遍歷陣列一次。
 * 空間複雜度：O(1) - 僅使用一個整數記錄結果。
 */

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int res = 0;
        // 只要陣列中任意數的位元為 1，OR 操作就會保留該位元
        for (int num : nums) {
            res |= num;
        }
        return res;
    }
};
