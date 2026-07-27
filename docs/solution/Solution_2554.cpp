/**
 * 題目：2554. Maximum Number of Integers to Choose From a Range I
 * 描述：給你一個整數陣列 banned、一個整數 n 和一個整數 maxSum。
 *       你需要從範圍 [1, n] 中選擇整數，並滿足以下條件：
 *       1. 所選的整數不能在 banned 中。
 *       2. 所選整數的總和不超過 maxSum。
 *       3. 每個整數最多只能被選擇一次。
 *       返回符合條件的最多可選擇整數個數。
 * 
 * 解法思路：
 * 1. 雜湊集合優化尋找：
 *    - 將 `banned` 陣列中的所有元素放入 `std::unordered_set` 中，使後續檢查某個數是否被禁用的時間複雜度降低至 O(1)。
 * 2. 貪心策略（Greedy Selection）：
 *    - 從數字 1 開始依序檢查到 n。
 *    - 如果該數字存在於 `bannedSet` 中，則跳過（`continue`）。
 *    - 如果將該數字加入總和後（`sum + i`）沒有超過 `maxSum`，則將其計入總和並將計數器 `count` 加 1。
 *    - 一旦總和超限或迴圈結束，返回累計的個數 `count`。
 */

class Solution {
public:
    int maxCount(std::vector<int>& banned, int n, int maxSum) {
        // 將 banned 轉為 unordered_set，以便 O(1) 快速檢查
        std::unordered_set<int> bannedSet(banned.begin(), banned.end());
        
        int count = 0;
        int sum = 0;
        
        // 從 1 到 n 依序走訪
        for (int i = 1; i <= n; ++i) {
            // 若該數字被禁止，跳過
            if (bannedSet.count(i)) {
                continue;
            }
            
            // 貪心累加：確保加上當前數字後不超過 maxSum
            if ((sum + i) <= maxSum) {
                sum += i;
                count++;
            } else {
                // 如果加上當前數字會超標，因為後面的數字更大，直接結束迴圈
                break;
            }
        }
        
        return count;
    }
};
