/**
 * 題目：2570. Merge Two 2D Arrays by Summing Values
 * 難度：Easy
 * 描述：nums1、nums2 的每個元素為 [id, val]，且各自以 id 嚴格遞增排列。
 *       合併兩個陣列：id 出現在任一陣列就保留，
 *       若兩邊都有則 val 相加，回傳依 id 遞增排列的結果。
 *
 * 分類主題：hash-table-counting
 * 技巧：值域固定的計數陣列, 依 id 掃描天然有序
 *
 * 解法思路：計數陣列
 * 1. id 的範圍只有 1 ~ 1000，直接開 counts[1001]，以 id 當索引累加 val。
 * 2. 兩個陣列都走一遍，同 id 的 val 自然加在同一格。
 * 3. 從 id = 1 掃到 1000，把 counts[i] 不為 0 的格子輸出為 [i, counts[i]]。
 *    掃描順序就是 id 遞增，不需要另外排序。
 * 4. 以「counts 是否為 0」判斷 id 是否存在，是因為題目保證 val >= 1。
 *
 * 時間複雜度：O(n + m + V)，V = 1000 為 id 值域
 * 空間複雜度：O(V)（不計輸出）
 */
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        array<int, 1001> counts = {}; // counts[id] = 該 id 的 val 總和

        // 兩個陣列的 val 依 id 累加到同一張表
        for (const vector<int>& v : nums1) counts[v[0]] += v[1];
        for (const vector<int>& v : nums2) counts[v[0]] += v[1];

        // 依 id 由小到大掃描，val 總和為 0 代表該 id 沒出現過
        for (int i = 1; i <= 1000; i++) {
            if (!counts[i]) continue;
            ans.push_back({i, counts[i]});
        }
        return ans;
    }
};
