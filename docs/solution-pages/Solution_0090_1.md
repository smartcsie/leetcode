# Solution_0090_1

```cpp
/**
 * 題目：90. Subsets II
 * 描述：給你一個可能包含重複元素的整數陣列 nums，請你返回該陣列所有可能的子集（冪集）。
 *       解集不能包含重複的子集。你可以按任意順序返回解集。
 * 
 * 解法思路（位元遮罩窮舉 + 排序去重 Bitmask + Sorting + Hash Set）：
 * 1. 陣列排序（Sorting）：
 *    - 先對 `nums` 進行排序，確保相同的元素會相鄰排列。雖然本解法透過 `std::set` 進行去重，但排序有助於讓相同組成的子集順序一致。
 * 2. 透過 Bitmask 窮舉所有子集：
 *    - 沿用 78 題的概念，透過從 `0` 到 `2^n - 1` 的整數位元遮罩，組合出所有可能被選取的子集。
 * 3. 利用 `std::set` 過濾重複組合：
 *    - 由於原始陣列含有重複元素，不同的位元選擇組合可能會產生內容完全相同的子集。利用 `set::insert` 的回傳值（`.second` 代表是否成功插入新元素），自動過濾掉重複出現的子集，並將唯一結果存入 `res` 矩陣中。
 * 時間複雜度：O(N * 2^N) - 枚舉所有子集，去重後仍為 2^N 個。
 * 空間複雜度：O(N) - 遞迴深度與當前子集各佔 O(N)。

 */

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end()); // 排序陣列，讓重複元素相鄰
        
        std::set<std::vector<int>> seen; // 利用 set 自動去除重複的子集
        std::vector<std::vector<int>> res;
        
        // 透過 2^n 種位元遮罩窮舉所有子集
        for (int mask = 0; mask < (1 << n); mask++) {
            std::vector<int> cur;
            
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cur.push_back(nums[i]);
                }
            }
            
            // 若該子集尚未出現過，則成功插入並加入結果集
            if (seen.insert(cur).second) {
                res.push_back(cur);
            }
        }
        
        return res;
    }
};

```
