/**
 * 題目：3843. First Element with Unique Frequency
 * 難度：簡單 (Easy)
 * 描述：找到陣列中第一個元素，其「出現頻率」本身在頻率表中是唯一的。
 * * 時間複雜度：O(N)，兩次遍歷陣列與頻率映射。
 * 空間複雜度：O(N)，儲存數字頻率與頻率的頻率。
 * * 優化思路：
 * 1. 使用 unordered_map 進行 O(1) 的頻率統計。
 * 2. 嚴格遵守題目要求，先計算數字頻率，再計算頻率的頻率，最後掃描。
 */

class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> counts;
        for(const int& num : nums) {
            counts[num]++;
        }
        unordered_map<int, int> countFreq;
        for(const auto& [num, count] : counts) {
            countFreq[count]++;
        }
        for(const int& num : nums) {
            if(countFreq[counts[num]] == 1) return num;
        }
        return -1;
    }
};
