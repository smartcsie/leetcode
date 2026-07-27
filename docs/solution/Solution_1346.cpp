/**
 * 題目：1346. Check If N and Its Double Exist (檢查整數及其兩倍數是否存在)
 * 難度：簡單 (Easy)
 * 描述：給你一個整數陣列 arr，請檢查是否存在兩個下標 i 和 j，使得 arr[i] == 2 * arr[j]。
 * 
 * 時間複雜度：O(n) - 遍歷陣列一次，Hash Set 插入與查詢皆為 O(1)。
 * 空間複雜度：O(n) - 最壞情況下將所有元素存入 Set。
 * 
 * 解法思路：
 * 1. 遍歷陣列，對於每個數 num：
 *    - 檢查 set 中是否已經存過 `num * 2` (因為 `num` 的兩倍就是目標)。
 *    - 檢查 set 中是否已經存過 `num / 2` (因為 `num` 的一半就是目標)。
 * 2. 特別注意：只有當 `num` 為偶數時，檢查 `num / 2` 才有意義。
 * 3. 0 的處理：如果 `num` 是 0，`num * 2` 和 `num / 2` 都是 0，
 *    Set 可以幫我們判斷是否之前已經出現過另一個 0。
 */

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;
        for (int num : arr) {
            if (seen.count(num * 2) || (num % 2 == 0 && seen.count(num / 2))) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};
