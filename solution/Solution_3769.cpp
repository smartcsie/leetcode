/**
 * 題目：3769. Sort Integers by Binary Reflection
 * 難度：中等 (Medium)
 * 描述：根據整數的二進位反轉值進行排序，若反轉值相同，則按原數值大小排序。
 *
 * 時間複雜度：O(NlogN) - 排序操作為主導因素。
 * 空間複雜度：O(N) - 額外儲存反射對結構。
 *
 * 解法思路：
 * 1. 預分配 (Reserve)：使用 `reserve` 避免 `push_back` 時的記憶體重新配置。
 * 2. 結構簡化：直接利用 `std::pair` 的字典序特性，減少自定義比較函數的複雜度。
 */

class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int, int>> groups;
        int n = nums.size();
        groups.reserve(n);
        for(int i = 0 ; i < n; i++) {
            int x = nums[i];
            int r = 0;
            while(x > 0) {
                r = (r << 1) | (x % 2);
                x >>= 1;
            }
            groups.push_back({r, nums[i]});
        }
        sort(groups.begin(), groups.end());
        for(int i = 0; i < n; i++) {
            nums[i] = groups[i].second;
        }
        return nums;
    }
};
