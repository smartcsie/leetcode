/**
 * 題目：896. Monotonic Array (單調陣列)
 * 難度：簡單 (Easy)
 * 描述：檢查一個陣列是否為單調陣列（單調遞增或單調遞減）。
 * * 時間複雜度：O(N) - 遍歷陣列一次。
 * 空間複雜度：O(1) - 僅使用兩個布林變數。
 * * 解法思路：
 * 1. 定義兩個旗標 (flags) `isIncrease` 與 `isDecrease`，初始化皆為 true。
 * 2. 遍歷陣列，比較相鄰元素：
 * - 若發現 `nums[i] > nums[i+1]`，則陣列不可能為遞增，將 `isIncrease` 設為 false。
 * - 若發現 `nums[i] < nums[i+1]`，則陣列不可能為遞減，將 `isDecrease` 設為 false。
 * 3. 最後，若陣列維持單調性，則至少會有一個旗標保持為 true。
 */

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIncrease = true;
        bool isDecrease = true;
        
        // 遍歷陣列比較相鄰元素
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            if (nums[i] > nums[i+1]) {
                isIncrease = false; // 破壞遞增性質
            }
            if (nums[i] < nums[i+1]) {
                isDecrease = false; // 破壞遞減性質
            }
        }
        
        // 只要符合其中一種性質，即為單調陣列
        return isIncrease || isDecrease;
    }
};
