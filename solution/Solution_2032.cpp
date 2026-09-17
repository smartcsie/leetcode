/**
 * 題目：2032. Two Out of Three
 * 難度：簡單 (Easy)
 * 描述：找出至少在三個陣列中的兩個出現過的整數。
 * 優化重點：
 * 1. 位元遮罩 (Bitmasking)：使用 1, 2, 4 分別代表三個陣列，O(1) 空間記錄狀態。
 * 2. C++20 `std::popcount`：直接獲取被設置的位元數，避開手動循環計數。
 *
 * 時間複雜度：O(N1+N2+N3)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> count(101, 0);
        for(const int& x : nums1) count[x] |= 1;
        for(const int& x : nums2) count[x] |= 2;
        for(const int& x : nums3) count[x] |= 4;
        vector<int> ans;
        ans.reserve(101);
        for(int i = 1; i<= 100; i++) {
            if(__builtin_popcount(count[i]) > 1) ans.push_back(i);
        }
        return ans;
    }
};
