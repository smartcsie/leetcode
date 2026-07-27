/**
 * 題目：692. Top K Frequent Words (前 K 個高頻單詞)
 * 難度：中等 (Medium)
 * 描述：找出陣列中出現頻率前 K 高的單詞，若頻率相同則按字典序排序。
 * * 時間複雜度：O(N log K) - 遍歷 N 個元素，每個元素對 Heap 操作。
 * 空間複雜度：O(N) - 儲存雜湊表。
 * * 優化思路：
 * 當 K << N 時，使用 Heap (優先佇列) 比全排序 (sort) 的 O(N log N) 更有效率。
 */

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (const string& word : words) count[word]++;
        
        // 定義自定義比較器
        // 為了將頻率低、字典序大的放在堆頂，以便彈出
        auto comp = [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) return a.first < b.first; // 字典序大者優先彈出
            return a.second > b.second;                        // 頻率小者優先彈出
        };
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(comp);
        
        for (auto& entry : count) {
            pq.push(entry);
            if (pq.size() > k) pq.pop();
        }
        
        vector<string> res(k);
        for (int i = k - 1; i >= 0; --i) {
            res[i] = pq.top().first;
            pq.pop();
        }
        return res;
    }
};
