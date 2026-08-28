/**
 * 題目：3769. Sort Integers by Binary Reflection
 * 難度：中等 (Medium)
 * 描述：根據整數的二進位反轉值進行排序，若反轉值相同，則按原數值大小排序。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 預分配 (Reserve)：使用 `reserve` 避免 `push_back` 時的記憶體重新配置。
 * 2. 結構簡化：直接利用 `std::pair` 的字典序特性，減少自定義比較函數的複雜度。
 */

class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        vector<int> reflect(n);
        vector<int> indices(n);
        for(int i = 0; i < n; i++) {
            int r = 0;
            int t = nums[i];
            while(t > 0) {
                r = (r << 1) | (t & 1);
                t >>= 1;
            } 
            reflect[i] = r;
        }
        for(int i = 0; i < n; i++) indices[i] = i;
        sort(indices.begin(), indices.end(), [&](const int& a, const int& b){
            return reflect[a] != reflect[b] ? reflect[a] < reflect[b] : nums[a] < nums[b];
        });
        vector<int> ans;
        ans.reserve(n);
        for(const int& idx : indices) ans.push_back(nums[idx]);
        return ans;
    }
};