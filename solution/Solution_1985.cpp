/**
 * 題目：1985. Find the Kth Largest Integer in the Array (找出陣列中的第 K 大整數)
 * 難度：中等 (Medium)
 * 描述：在字串陣列中找出表示數值第 K 大的字串。
 * * 時間複雜度：O(N) - nth_element 平均為線性時間。
 * 空間複雜度：O(1) - 原地操作 (除了堆疊空間)。
 * * 優化思路：
 * 1. 數值比較規則：長度較長者必然較大；若長度相同，則比較字典序。
 * 2. 使用 nth_element 避免全排序，直接將第 K 大元素放到正確位置。
 */

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1,  nums.end(), [](const string& a, const string& b) {
            if(a.size() != b.size()) {
                return a.size() > b.size();
            }
            return a > b;
        });
        return nums[k - 1];
    }
};
