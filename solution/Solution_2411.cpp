/**
 * 題目：2411. Smallest Subarrays With Maximum Bitwise OR (最大按位或子陣列的最小長度)
 * 難度：中等 (Medium)
 * 描述：給定陣列 nums，對每個索引 i，找出以 i 為起點的最短子陣列，
 *       使其所有元素的按位或（OR）結果，等於「以 i 為起點的所有子陣列」中能得到的最大 OR 值。
 *       回傳每個索引對應的最短長度所組成的陣列。
 *
 * 時間複雜度：O(N×30) - 對每個索引，固定掃描 30 個位元位置，視為 O(N)。
 * 空間複雜度：O(30) - closest 陣列固定大小 30，不隨輸入規模成長。
 *
 * 解法思路：
 * 1. 逐位元追蹤最近出現位置 (Track Closest Bit Position)：
 *    - 從陣列尾端往前掃描，用 closest[j] 記錄「目前為止（含當前位置往右）最接近的、
 *      第 j 個位元為 1 的索引」。
 * 2. 由後往前遞推 (Backward Traversal)：
 *    - 因為要找「以 i 為起點」的最短子陣列，從右往左掃描時，
 *      每個位元的 closest 值只會隨著往左移動而更新或維持不變，天然符合遞推方向。
 * 3. 每個位元決定所需延伸長度：
 *    - 對於索引 i 的答案，需要延伸到「涵蓋所有曾經出現過的位元」，
 *      即取所有 closest[j] - i + 1 的最大值，才能保證 OR 結果達到最大。
 * 4. 更新目前位元的最近位置：
 *    - 若 nums[i] 的第 j 位為 1，代表從 i 開始就能立刻涵蓋這個位元，
 *      將 closest[j] 更新為 i，供左側（更早）的索引使用。
 */
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        constexpr int kMaxBit = 30;
        vector<int> ans(nums.size(), 1);
        // closest[j] := the closest index i s.t. the j-th bit of nums[i] is 1
        vector<int> closest(kMaxBit);
        for (int i = nums.size() - 1; i >= 0; --i)
        for (int j = 0; j < kMaxBit; ++j) {
            if (nums[i] >> j & 1)
                closest[j] = i;
            ans[i] = max(ans[i], closest[j] - i + 1);
        }
        return ans;
    }
};
