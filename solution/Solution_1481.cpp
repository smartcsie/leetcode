/**
 * 題目：1481. Least Number of Unique Integers after K Removals
 * 難度：中等 (Medium)
 * 描述：在刪除 k 個元素後，求剩餘數字種類數量的最小值。
 * 優化重點：
 * 1. 轉儲頻率至 vector 時，只儲存頻率 (value) 而不儲存 key，減少空間開銷。
 * 2. 移除排序後的 pair，改用純頻率陣列排序，進一步提升效能。
 *
 * 時間複雜度：O(NlogN) - 計數後排序頻率，貪婪從最少移除。
 * 空間複雜度：O(N) - 頻率陣列大小為 N。
 */


class Solution {
public:
    int findLeastNumOfUniqueInts(std::vector<int>& arr, int k) {
        unordered_map<int, int> map_counts;
        for(const int& x : arr) map_counts[x]++;
        vector<int> counts;
        counts.reserve(map_counts.size());
        for(const auto& [_, x] : map_counts) counts.push_back(x);
        sort(counts.begin(), counts.end());
        int type = counts.size();
        for(int i = 0; i < counts.size(); i++) {
            if(k >= counts[i]) {
                k -= counts[i];
                type--;
            } else {
                return type;
            }
        }
        return type;
    }
};
