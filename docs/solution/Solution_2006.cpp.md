# Solution_2006

```cpp
/**
 * 題目：2006. Count Number of Pairs With Absolute Difference K
 * 描述：給你一個整數陣列 nums 和一個整數 k，請你返回數組中滿足 |nums[i] - nums[j]| == k 的數對 (i, j) 的數量，
 *       其中 0 <= i < j < nums.length。
 * 
 * 解法思路：
 * 1. 雜湊表頻率統計（Frequency Map）：
 *    - 使用 `std::unordered_map` 記錄每個數字在陣列中出現過的次數。
 * 2. 邊走訪邊查詢（Single-Pass Lookup）：
 *    - 當我們掃描到當前數字 `x` 時，`map` 內剛好只存放「在 `x` 之前出現過的數字」。
 *    - 根據絕對差定義 $\vert{}x - y\vert{} == k$，數字 `y` 只可能為 `x - k` 或 `x + k`。
 *    - 我們直接從 `map` 中累加 `x - k` 與 `x + k` 過去出現的次數到答案中。
 * 3. 避免重複與自體比較：
 *    - 查詢完畢後，再將當前數字 `x` 放入 `map` 中（`countMap[x]++`），完美避免自我比較或重複計算。
 * 時間複雜度：O(N) - hash map 記錄每個數字頻率，遍歷查詢 num+k 和 num-k。
 * 空間複雜度：O(N) - hash map 大小為 N。

 */

class Solution {
public:
    int countKDifference(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> countMap;
        int ans = 0;
        
        for (int x : nums) {
            // 檢查前面出現過的數字中，有沒有與 x 相差 k 的 (x - k 或 x + k)
            if (countMap.count(x - k)) {
                ans += countMap[x - k];
            }
            if (countMap.count(x + k)) {
                ans += countMap[x + k];
            }
            
            // 將當前數字加入 map 中，供後續的數字進行查詢
            countMap[x]++;
        }
        
        return ans;
    }
};

```
