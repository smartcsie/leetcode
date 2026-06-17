/**
 * 題目：3731. Find Missing Elements (找出缺失元素)
 * 難度：簡單 (Easy)
 * 描述：在陣列的最小值與最大值之間，找出所有未出現過的整數。
 * * 時間複雜度：O(N + K)，N 為陣列大小，K 為數值範圍 (max - min)。
 * 空間複雜度：O(K)，用於標記存在與否的位元陣列。
 * * 優化思路：
 * 1. 防禦性程式設計：加入空陣列判斷以避免未定義行為 (Segmentation Fault)。
 * 2. 空間最佳化：確保標記容器大小適中，避免無效記憶體開銷。
 */

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        auto [minIt, maxIt] = minmax_element(nums.begin(), nums.end());
        int min = *minIt;
        int max = *maxIt;
        vector<bool> seen(max + 1, false);
        vector<int> res;
        res.reserve(max - min);
        for(const int& num : nums) {
            seen[num] = true;
        }
        for(int i = min + 1; i < max; i++) {
            if(!seen[i]) res.push_back(i);
        }
        return res;
    }
};
