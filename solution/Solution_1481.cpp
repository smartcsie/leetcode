/**
 * 題目：1481. Least Number of Unique Integers after K Removals
 * 難度：中等 (Medium)
 * 描述：在刪除 k 個元素後，求剩餘數字種類數量的最小值。
 * * 優化重點：
 * 1. 轉儲頻率至 vector 時，只儲存頻率 (value) 而不儲存 key，減少空間開銷。
 * 2. 移除排序後的 pair，改用純頻率陣列排序，進一步提升效能。
 */


class Solution {
public:
    int findLeastNumOfUniqueInts(std::vector<int>& arr, int k) {
        std::unordered_map<int, int> counts;
        for (const int num : arr) {
            counts[num]++;
        }
        
        // 僅提取頻率 (counts)，忽略具體數字 (key)
        std::vector<int> freq;
        freq.reserve(counts.size());
        for (const auto& [num, count] : counts) {
            freq.push_back(count);
        }
        
        // 依照頻率由小到大排序
        std::sort(freq.begin(), freq.end());
        
        int removed_types = 0;
        for (const int f : freq) {
            if (k >= f) {
                k -= f;
                removed_types++;
            } else {
                break;
            }
        }
        
        return static_cast<int>(freq.size()) - removed_types;
    }
};
