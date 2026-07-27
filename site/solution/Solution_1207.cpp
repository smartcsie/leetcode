/**
 * 題目：1207. Unique Number of Occurrences (獨一無二的出現次數)
 * 難度：簡單 (Easy)
 * 描述：檢查陣列中每個數值出現的次數是否皆為唯一。
 * * 時間複雜度：O(N) - 遍歷陣列一次進行計數，再遍歷 map 一次檢查唯一性。
 * 空間複雜度：O(N) - 使用哈希表儲存頻率。
 * * 設計思路：
 * 1. 使用 unordered_map 統計每個數字出現的次數。
 * 2. 使用 unordered_set 儲存出現過的頻率，若插入時發現頻率已存在則代表不唯一。
 */

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counts;
        for (int num : arr) {
            counts[num]++;
        }
        
        unordered_set<int> frequencies;
        for (const auto& [val, count] : counts) {
            // 如果插入失敗 (insert 返回 pair 的第二個元素為 false)，代表頻率已存在
            if (!frequencies.insert(count).second) {
                return false;
            }
        }
        
        return true;
    }
};
