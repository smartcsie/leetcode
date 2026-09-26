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
private:
    int getReflect(int n) {
        int r = 0;
        while(n > 0) {
            r = (r << 1) | (n & 1);
            n >>= 1;
        }
        return r;;
    }
public:
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](const int& a, const int& b){
            int refA = getReflect(a);
            int refB = getReflect(b);
            return refA != refB ? refA < refB : a < b;
        });
        return nums;
    }
};