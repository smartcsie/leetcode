/**
 * 題目：350. Intersection of Two Arrays II (兩個陣列的交集 II)
 * 難度：簡單 (Easy)
 * 描述：給你兩個整數陣列 nums1 和 nums2，請你以陣列形式返回兩者的交集。
 *      返回結果中每個元素出現的次數，應與元素在兩個陣列中都出現的次數一致（取較小值）。
 * 
 * 時間複雜度：O(n + m) - 其中 n 和 m 分別為兩個陣列的長度。
 * 空間複雜度：O(min(n, m)) - 我們通常將較小的陣列放入 Hash Map 中以節省空間。
 * 
 * 解法思路：
 * 1. 利用 Hash Map (unordered_map) 統計第一個陣列中每個數字出現的次數。
 * 2. 遍歷第二個陣列，檢查當前數字是否在 Map 中且計數大於 0。
 * 3. 若滿足條件，代表該數字是交集的一部分：
 *    - 將數字加入結果陣列 res。
 *    - 將 Map 中該數字的計數減 1，代表消耗了一個匹配額度。
 */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // 小優化：確保 nums1 是較短的那個，減少空間消耗
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        vector<int> res;
        unordered_map<int, int> counts;
        // 統計第一個陣列的數字頻率
        for (int num : nums1) {
            counts[num]++;
        }
        // 遍歷第二個陣列比對頻率
        for (int num : nums2) {
            if (counts.count(num) && counts[num] > 0) {
                res.push_back(num);
                counts[num]--; // 每匹配到一個，次數減一
            }
        }
        return res;
    }
};
