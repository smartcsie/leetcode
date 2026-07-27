# Solution_0532

```cpp
/**
 * 題目：532. K-diff Pairs in an Array
 * 描述：給你一個整數陣列 nums 和一個整數 k，請你在陣列中找出所有不重複的 k-diff 數對，
 *       並返回這些數對的數量。
 *       k-diff 數對定義為整數對 (nums[i], nums[j])，滿足：
 *       - 0 <= i < j < nums.length
 *       - |nums[i] - nums[j]| == k
 * 
 * 解法思路（雙雜湊集合法 Dual Hash Sets）：
 * 1. 為什麼不能直接存 `pair`：
 *    - C++ 的 `std::unordered_set` 沒有內建 `std::pair` 的 Hash 函數，若直接宣告會導致編譯失敗。
 * 2. 巧妙的數字化去重策略：
 *    - 我們可以利用兩個 `unordered_set`：
 *      - `visited`：記錄所有已經掃描過的數字，用來快速檢查是否有符合 `num - k` 或 `num + k` 的配對存在。
 *      - `ans`：專門用來記錄「已經成功配對的較小基準數」（當 $k > 0$ 時）或是配對數。利用 `set` 自動去重的特性，確保相同的數對不會被重複計算。
 * 時間複雜度：O(N log N) - 排序後雙指針或二分搜尋。
 * 空間複雜度：O(N) - 排序空間 O(log N)，set O(N)。

 */

class Solution {
public:
    int findPairs(std::vector<int>& nums, int k) {
        std::unordered_set<int> visited, ans;
        
        for (const int& num : nums) {
            // 檢查是否存在 num - k，若存在代表 (num - k, num) 形成一對
            if (visited.count(num - k)) {
                ans.insert(num - k); // 記錄較小的數字以避免重複
            }
            // 檢查是否存在 num + k，若存在代表 (num, num + k) 形成一對
            if (visited.count(num + k)) {
                ans.insert(num); // 記錄此時較小的數字
            }
            // 將當前數字加入已訪問集合
            visited.insert(num);
        }
        
        return ans.size();
    }
};

```
