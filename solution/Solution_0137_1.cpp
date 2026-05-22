/**
 * 題目：137. Single Number II (只出現一次的數字 II)
 * 難度：中等 (Medium)
 * 描述：除了某個元素只出現一次以外，其餘每個元素都恰出現三次。找出那個元素。
 * 
 * 時間複雜度：O(n) - 遍歷陣列並插入 Hash Set，再遍歷 Set。
 * 空間複雜度：O(n) - 使用 Hash Set 存儲所有不重複的數字。
 * 
 * 解法思路 (數學公式法)：
 * 1. 設出現一次的數字為 x，重複三次的數字集為 S。
 * 2. 原始陣列總和 sum_all = x + 3 * sum(S)。
 * 3. Hash Set 中存儲的是所有不重複的數字，其總和 sum_unique = x + sum(S)。
 * 4. 推導公式：
 *    3 * sum_unique = 3 * x + 3 * sum(S)
 *    3 * sum_unique - sum_all = (3 * x + 3 * sum(S)) - (x + 3 * sum(S))
 *    3 * sum_unique - sum_all = 2 * x
 *    x = (3 * sum_unique - sum_all) / 2
 * 
 * 注意：由於運算過程中涉及乘法與加總，數字極大時可能導致 int 溢位，
 *      因此必須使用 long long 型別。
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 使用 long long 防止計算過程中的整數溢位 (int 可能會超過範圍)
        long long sum_all = 0;
        unordered_set<long long> s;
        
        for (int num : nums) {
            sum_all += num;
            s.insert(num);
        }
        
        long long sum_unique = 0;
        for (long long num : s) {
            sum_unique += num;
        }
        
        // 根據公式 target = (3 * sum_unique - sum_all) / 2
        // 強制將所有運算轉為 long long 進行，最後再轉回 int 返回
        return (int)((3 * sum_unique - sum_all) / 2);
    }
};
