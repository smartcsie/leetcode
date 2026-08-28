/**
 * 題目：1636. Sort Array by Increasing Frequency (按照頻率將陣列升序排序)
 * 難度：簡單 (Easy)
 * 描述：根據元素的頻率進行升序排序，若頻率相同，則按數值降序排序。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(1)
 */
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> counts;
        for(const int& x : nums) counts[x]++;
        sort(nums.begin(), nums.end(), [&](const int& a, const int& b) {
            return counts[a] != counts[b] ? counts[a] < counts[b] : a > b;
        });
        return nums;
    }
};
