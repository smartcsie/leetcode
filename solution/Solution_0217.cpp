/**
 * 解題思路：利用 Hash Set 進行查重
 * 1. 建立一個 unordered_set<int> 用來存儲已經遍歷過的數字。
 * 2. 遍歷陣列中的每個數字：
 *    - 如果該數字已經存在於 set 中，代表重複，回傳 true。
 *    - 如果不存在，則將該數字放入 set 中。
 * 3. 若遍歷結束都沒發現重複，回傳 false。
 * 
 * 注意：雖然排序後檢查相鄰元素也是一種 $O(n \log n)$ 的解法，
 * 但使用 Hash Set 可以達到更優的 $O(n)$ 平均時間複雜度。
 * 
 * Time Complexity: O(n) - 遍歷陣列一次，Set 的查找與插入平均為 O(1)。
 * Space Complexity: O(n) - 最壞情況下（無重複）需要存儲所有數字。
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int num : nums) {
            if(set.contains(num)) {
                return true;
            } else {
                set.insert(num);
            }
        }
        return false;
    }
};
