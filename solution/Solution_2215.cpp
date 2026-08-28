/**
 * 題目：2215. Find the Difference of Two Arrays
 * 難度：簡單 (Easy)
 * 描述：給定兩個整數陣列 nums1、nums2，回傳一個長度為 2 的陣列 answer：
 * answer[0] 是只存在於 nums1、不存在於 nums2 的相異整數所組成的陣列；
 * answer[1] 是只存在於 nums2、不存在於 nums1 的相異整數所組成的陣列。
 *
 * 時間複雜度：O(N+M)
 *             建立兩個 hash set 各需 O(N)、O(M)，之後各遍歷一次。
 * 空間複雜度：O(N+M)
 *
 * 解法思路：
 * （雙 Hash Set 求差集 Set Difference）：
 * 1. 建立兩個 hash set：
 * - 用 nums1、nums2 分別建構 unordered_set，自動去除重複值，
 *   同時具備 O(1) 平均查詢的效能。
 * 2. 預先保留空間：
 * - ans[0]、ans[1] 用 reserve 預留 set1、set2 大小的空間，
 *   避免 push_back 過程中多次重新配置記憶體。
 * 3. 求差集：
 * - 遍歷 set1，若元素不存在於 set2，代表只屬於 nums1，加進 ans[0]；
 * - 遍歷 set2，若元素不存在於 set1，代表只屬於 nums2，加進 ans[1]。
 */
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set set1(nums1.begin(), nums1.end());
        unordered_set set2(nums2.begin(), nums2.end());
        vector<vector<int>> ans(2);
        ans[0].reserve(set1.size());
        ans[1].reserve(set2.size());
        for(const int& x : set1) if(!set2.count(x)) ans[0].push_back(x);
        for(const int& x : set2) if(!set1.count(x)) ans[1].push_back(x);
        return ans;
    }
};
