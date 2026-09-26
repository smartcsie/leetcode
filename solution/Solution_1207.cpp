/**
 * 題目：1207. Unique Number of Occurrences (獨一無二的出現次數)
 * 難度：簡單 (Easy)
 * 描述：檢查陣列中每個數值出現的次數是否皆為唯一。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 設計思路：
 * 1. 1. 使用 unordered_map 統計每個數字出現的次數。
 * 2. 2. 使用 unordered_set 儲存出現過的頻率，若插入時發現頻率已存在則代表不唯一。
 */

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freqs;
        for(const int& x : arr) freqs[x]++;
        unordered_set<int> uniqueSet;
        for(const auto& [num, freq] : freqs) {
            if(uniqueSet.contains(freq)) return false;
            uniqueSet.insert(freq);
        }
        return true;
    }
};
