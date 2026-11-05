/**
 * 題目：532. K-diff Pairs in an Array
 * 難度：中等 (Medium)
 * 描述：給定一個整數陣列和整數 k，找出所有絕對差為 k 的不重複數對 (a, b)
 * 其中 a <= b，回傳數對的數量。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （Hash Map 計數）：
 * 1. 用 unordered_map 統計每個數字出現的次數。
 * 2. 遍歷 map，分兩種情況處理：
 *    - k == 0：數對為 (x, x)，需要 x 出現兩次以上才算一個有效數對。
 *    - k > 0：數對為 (x, x+k)，只需檢查 x+k 是否存在於 map 中。
 * 3. 因為遍歷 map 的 key 本身不重複，答案自然不會有重複數對。
 */
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        int ans = 0;
        for (const int& x : nums) counts[x]++;
        for (const auto& [x, count] : counts) {
            if (k == 0) {
                if (count > 1) ans++;          // (x, x) 需出現兩次以上
            } else {
                if (counts.contains(x + k)) ans++;  // 檢查 x+k 是否存在
            }
        }
        return ans;
    }
};