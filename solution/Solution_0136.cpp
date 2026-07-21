

/**
 * 解題思路：利用 XOR (互斥或) 運算的特性
 * 1. a ^ a = 0 (相同的數字異或結果為 0)
 * 2. a ^ 0 = a (任何數與 0 異或結果不變)
 * 3. 異或運算滿足交換律與結合律
 * 
 * 由於陣列中除了一個數字外，其餘都成對出現，
 * 將所有數字連在一起做 XOR，成對的數字會互相抵銷變成 0，
 * 最後剩下的結果就是那個只出現一次的數字。
 * 
 * Time Complexity: O(n) - 只需要遍歷陣列一次。
 * Space Complexity: O(1) - 僅使用一個額外的整數變數，不隨輸入規模增加空間。
 */


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return reduce(nums.begin(), nums.end(), 0 , bit_xor<int>());
    }
};
