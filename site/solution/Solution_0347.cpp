/**
 * 題目：347. Top K Frequent Elements (前 K 個高頻元素)
 * 難度：中等 (Medium)
 * 描述：找出陣列中出現頻率最高的前 K 個元素。
 * * 時間複雜度：O(N) - 統計頻率 O(N)，nth_element 選擇 O(N)。
 * 空間複雜度：O(N) - 儲存頻率 Map 與 Vector。
 * * 優化思路：
 * 1. 使用 unordered_map 統計頻率。
 * 2. 使用 nth_element 在線性時間內將頻率前 K 高的元素移至容器後段。
 * 3. 預先 reserve 結果空間，減少 vector 動態擴展次數。
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int num : nums) counts[num]++;
        
        // 利用範圍建構子直接將 map 轉為 vector<pair>
        vector<pair<int, int>> freq_vec(counts.begin(), counts.end());

        // 使用 nth_element 進行快速選擇
        // 目標：將前 K 大的元素放到容器的最末端 [size-k, size-1]
        auto target = freq_vec.begin() + (freq_vec.size() - k);
        nth_element(freq_vec.begin(), target, freq_vec.end(), 
            [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second < b.second; // 依照頻率從小到大比較
            });
            
        // 預先配置空間，避免多次 push_back 觸發重分配
        vector<int> res;
        res.reserve(k);
        for (auto it = target; it != freq_vec.end(); ++it) {
            res.push_back(it->first);
        }
        
        return res;
    }
};
