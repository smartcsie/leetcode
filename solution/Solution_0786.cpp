/**
 * 題目：786. K-th Smallest Prime Fraction
 * 難度：困難 (Hard)
 * 描述：在給定的質數陣列中，找出第 K 小的分數。
 * * 優化重點：
 * 1. 優先佇列 (Max-Heap)：避免 $O(N^2)$ 的暴力窮舉，直接找出第 K 小。
 * 2. 空間效率：僅保留 N 個候選分數，空間複雜度降至 O(N)。
 */

class Solution {
public:
    std::vector<int> kthSmallestPrimeFraction(std::vector<int>& arr, int k) {
        int n = arr.size();
        // 使用 Lambda 進行自定義比較：比較分數大小 arr[i]/arr[j]
        auto cmp = [&](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return (double)arr[a.first] / arr[a.second] < (double)arr[b.first] / arr[b.second];
        };
        
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);
        
        // 初始將所有與最後一個元素的分數放入堆中
        for (int i = 0; i < n - 1; ++i) {
            pq.push({i, n - 1});
        }
        
        // 取出 K-1 次最大的，剩下的堆頂即為第 K 小
        for (int i = 0; i < k - 1; ++i) {
            auto [numIdx, denIdx] = pq.top();
            pq.pop();
            if (denIdx - 1 > numIdx) {
                pq.push({numIdx, denIdx - 1});
            }
        }
        
        return {arr[pq.top().first], arr[pq.top().second]};
    }
};
