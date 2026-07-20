/**
 * 題目：2357. Make Array Zero by Subtracting Equal Amounts
 * 描述：給定一個非負整數陣列 nums。每次操作你可以選擇一個大於 0 的整數 x，
 *       並將陣列中所有大於或等於 x 的元素減去 x。
 *       求出將陣列中所有元素都變成 0 所需的最少操作次數。
 * 
 * 解法思路：
 * 1. 每次操作都是減去當前的最小非零值，這代表每一個不同的正整數都需要剛好一次操作來被消去。
 * 2. 使用 std::unordered_set 收集陣列中所有不重複的數字，並自動進行去重。
 * 3. 最終的操作次數，就是「不重複正整數的個數」。
 *    - 如果 set 中包含 0，則需要減去 0 的存在（即 `unique.count(0)`）。
 *    - 總次數 = `unique.size() - unique.count(0)`。
 */

class Solution {
public:
    int minimumOperations(std::vector<int>& nums) {
        std::unordered_set<int> unique;
        
        // 將所有數字放入 set 中以進行去重
        for (const int& num : nums) {
            unique.insert(num);
        }
        
        // 總操作次數 = 不重複的元素個數 - 0 的個數（因為 0 不需要被減去）
        return unique.size() - unique.count(0);
    }
};
