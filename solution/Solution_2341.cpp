/**
 * 題目：2341. Maximum Number of Pairs in Array
 * 描述：給你一個整數陣列 nums。在一步操作中，你可以：
 *       - 從 nums 中選擇兩個相等的整數，並將它們從陣列中刪除。
 *       請你返回一個長度為 2 的陣列 [answer₀, answer₁]，其中：
 *       - answer₀ 是最多可以刪除多少對相等的整數。
 *       - answer₁ 是經過所有刪除操作後，陣列中剩下的數字個數。
 * 
 * 解法思路：
 * 1. 根據題目的測資範圍，nums 中的數字通常介於 0 到 100 之間。
 * 2. 宣告一個大小為 101 的計數陣列 `counts` 來統計每一個數字出現的頻率。
 * 3. 走訪 `counts` 陣列中的每一個數字：
 *    - 該數值可以形成的對數為 `counts[i] / 2`，累加至答案的第 0 個位置（`ans[0]`）。
 *    - 該數值剩下無法成對的落單個數為 `counts[i] % 2`，累加至答案的第 1 個位置（`ans[1]`）。
 * 4. 返回組裝好的 `ans` 陣列。
 */

class Solution {
public:
    std::vector<int> numberOfPairs(std::vector<int>& nums) {
        // 根據常見測資範圍（0 到 100），宣告大小為 101 的頻率統計陣列
        std::vector<int> counts(101, 0);
        
        // 1. 統計每個數字出現的次數
        for (const int& num : nums) {
            counts[num]++;
        }

        // 2. 計算總對數與剩餘落單數
        std::vector<int> ans(2, 0);
        for (int i = 0; i <= 100; i++) {
            if (counts[i] == 0) continue;
            
            ans[0] += counts[i] / 2; // 可形成的對數
            ans[1] += counts[i] % 2; // 剩下的落單數
        }

        return ans;
    }
};
