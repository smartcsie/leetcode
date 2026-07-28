# Solution_0078_1

```cpp
/**
 * 題目：78. Subsets
 * 難度：待補充
 * 描述：給你一個含不同元素的整數陣列 nums，請你返回該陣列所有可能的子集（冪集）。
 * 解集不能包含重複的子集。你可以按任意順序返回解集。
 *
 * 時間複雜度：O(N * 2^N) - 枚舉所有子集，共 2^N 個，每個子集長度最多 N。
 * 空間複雜度：O(N) - 遞迴深度與當前子集各佔 O(N)。
 *
 * 解法思路：
 * （位元遮罩窮舉法 Bitmask Exhaustion）：
 * 1. 冪集的總數：
 * - 一個長度為 `n` 的集合，其子集總數為 $2^n$ 個。我們可以用一個整數 `mask` 從 `0` 窮舉到 `2^n - 1`。
 * 2. 利用位元對應元素選擇：
 * - 對於每一個 `mask`，其二進位的第 `i` 位若為 `1`，代表將 `nums[i]` 選入當前的子集 `cur` 中；若為 `0` 則不選。
 * 3. 收集結果：
 * - 將每一個建構好的子集 `cur` 放入結果矩陣 `res` 中，直到所有 $2^n$ 種組合遍歷完畢。
 */

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> res;
        // 總共有 2^n 種選擇組合 (從 0 到 2^n - 1)
        for (int mask = 0; mask < (1 << n); mask++) {
            std::vector<int> cur;
            // 檢查 mask 的每一個位元，決定是否將 nums[i] 納入子集
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cur.push_back(nums[i]);
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};

```
