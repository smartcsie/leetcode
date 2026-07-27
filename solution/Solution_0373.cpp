/**
 * 題目：373. Find K Pairs with Smallest Sums (查找和最小的 K 對數字)
 * 難度：中等 (Medium)
 * 描述：在兩個已排序陣列中，找出和最小的 K 對數字。
 * * 時間複雜度：O(K log K) - 堆中最多維持 K 個元素，進行 K 次提取與插入。
 * 空間複雜度：O(K) - 堆的空間以及結果集。
 * * 優化思路：
 * 1. 使用小頂堆 (Min-Heap) 儲存 {sum, {index1, index2}}。
 * 2. 初始時將 nums1 的前 k 個元素與 nums2[0] 配對放入堆中。
 * 3. 每次從堆中取出最小和，並將該元素在 nums2 中的下一位與 nums1 配對重新放入堆中。
 * 4. 使用 `reserve` 預先配置結果容器空間，減少記憶體重分配開銷。
 */

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty() || k == 0) return res;

        // 預先配置記憶體，避免動態擴容開銷
        res.reserve(k);

        using Element = pair<int, pair<int, int>>;
        priority_queue<Element, vector<Element>, greater<Element>> pq;

        // 初始放入 nums1 與 nums2[0] 的組合
        for (int i = 0; i < min((int)nums1.size(), k); ++i) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        // 進行 K 次提取
        while (k-- > 0 && !pq.empty()) {
            auto [sum, indices] = pq.top(); // C++17 結構化綁定
            pq.pop();
            
            int i = indices.first;
            int j = indices.second;
            res.push_back({nums1[i], nums2[j]});

            // 若 nums2 還有元素，放入下一個候選組合
            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }

        return res;
    }
};
