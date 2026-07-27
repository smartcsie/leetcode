/**
 * 題目：2154. Keep Multiplying Found Values by Two (將找到的值持續乘以 2)
 * 難度：簡單 (Easy)
 * 描述：給你一個整數陣列 nums 和一個整數 original。
 *      如果在 nums 中找到了 original，將其乘以 2 並繼續在陣列中尋找新的數值。
 *      重複此過程直到在陣列中找不到該數值為止，最後回傳該數值。
 * 
 * 時間複雜度：O(n) - 建立哈希集合需要 O(n)，隨後的迴圈次數極少（對數級別）。
 * 空間複雜度：O(n) - 需要額外的空間來儲存哈希集合。
 * 
 * 解法思路：
 * 1. 為了避免在每次查詢時都遍歷一次陣列（那樣會變成 O(n^2)），我們先將所有數字放入 unordered_set 中。
 * 2. 使用 while 迴圈檢查當前的 res 是否存在於集合中。
 * 3. 利用 unordered_set 的 contains 方法（C++20）進行平均 O(1) 的快速查找。
 * 4. 只要數值存在，就將其翻倍，直到找不到為止。
 */

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int res = original;
        unordered_set<int> set(nums.begin(), nums.end());
        while(set.contains(res)) {
            res *= 2;
        }
        return res;
    }
};
