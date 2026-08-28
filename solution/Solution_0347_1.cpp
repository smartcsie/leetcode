/**
 * 題目：347. Top K Frequent Elements
 * 難度：中等 (Medium)
 * 描述：給定一個整數陣列 nums 和整數 k，回傳出現頻率前 k 高的元素。
 *
 * 時間複雜度：O(N log N) - 所有元素都 push 進 heap，每次 push 為 O(log N)。
 * 空間複雜度：O(N) - hash map 與 heap 各佔 O(N)。
 *
 * 解法思路：
 * （Hash Map + Max Heap）：
 * 1. 用 unordered_map 統計每個數字的出現頻率。
 * 2. 將 {頻率, 數字} 的 pair 全部推入 max heap（priority_queue 預設最大堆）。
 *    pair 比較時先比 first（頻率），頻率高的自然排在堆頂。
 * 3. 從堆頂依序 pop k 次，取出頻率最高的 k 個數字。
 *
 * 注意：
 * 此解法把所有元素都推入 heap，時間為 O(N log N)。
 * 若改用 min heap 只保留 k 個元素，可優化到 O(N log K)。
 * 若用 nth_element，可進一步優化到 O(N) 平均。
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> q;
        vector<int> res;
        for (auto a : nums) ++m[a];
        for (auto it : m) q.push({it.second, it.first});
        for (int i = 0; i < k; ++i) {
            res.push_back(q.top().second); q.pop();
        }
        return res;
    }
};