/**
 * 題目：1365. How Many Numbers Are Smaller Than the Current Number
 * 難度：待補充
 * 描述：給你一個陣列 nums，對於其中每個元素 nums[i]，請你計算陣列中有多少個數字小於它。
 * 以陣列形式返回答案。
 *
 * 時間複雜度：O(N + K) - 計數排序，K 為值域範圍。
 * 空間複雜度：O(K) - 計數陣列大小為 K。
 *
 * 解法思路：
 * （計數排序與前綴和思想）：
 * 1. 數值範圍限制：
 * - 觀察題目限制，`nums[i]` 的數值通常很小（此題最大不超過 100）。這非常適合使用「桶排序 / 計數排序」的概念。
 * 2. 頻率統計（Frequency Count）：
 * - 宣告一個大小為 101 的 `counts` 陣列，統計每個數字出現的次數。
 * 3. 累積和轉換（Prefix Sum）：
 * - 將 `counts` 陣列向後累加（`counts[i] += counts[i - 1]`）。此時 `counts[i]` 代表「小於或等於 i 的數字總共有幾個」。
 * 4. 構造答案：
 * - 對於原本 `nums` 中的每個數字 `num`，如果 `num == 0`，則小於它的數量為 0；否則，小於它的數量就是 `counts[num - 1]`（即小於該數的累計次數）。
 */

class Solution {
public:
    std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
        constexpr int maxNum = 100;
        std::vector<int> ans;
        std::vector<int> counts(maxNum + 1, 0);
        
        // 步驟 1：統計每個數字出現的頻率
        for (const int& num : nums) {
            counts[num]++;
        }
        
        // 步驟 2：計算前綴和（累積小於或等於當前數字的個數）
        for (int i = 1; i <= 100; i++) {
            counts[i] += counts[i - 1]; 
        }
        
        // 步驟 3：查表取得小於當前數字的個數
        for (const int& num : nums) {
            ans.push_back(num == 0 ? 0 : counts[num - 1]);
        }
        
        return ans;
    }
};
