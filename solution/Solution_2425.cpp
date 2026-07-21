/**
 * 題目：2425. Bitwise XOR of All Pairings
 * 描述：給定兩個下標從 0 開始的陣列 nums1 和 nums2。
 *       存在另一個陣列 nums3，包含所有來自 nums1[i] 與 nums2[j] 配對的按位與 XOR 結果。
 *       請返回 nums3 中所有元素的總 XOR 值。
 * 
 * 解法思路：
 * 1. 頻率分析：
 *    - nums1 中的每一個元素，都會與 nums2 的所有元素各配對一次，因此 nums1 的每個元素總共會出現 nums2.size() 次。
 *    - 同理，nums2 的每個元素總共會出現 nums1.size() 次。
 * 2. XOR 的奇偶性質：
 *    - 根據 XOR 的反身性，一個數字若被 XOR 了偶數次，結果為 0（互相抵消）；若被 XOR 了奇數次，結果為其本身。
 * 3. 實作邏輯：
 *    - 若 nums2 的長度是奇數 (`nums2.size() & 1`)，代表 nums1 的所有元素會被保留下來，我們將其全體 XOR 總和累加到 ans 中。
 *    - 若 nums1 的長度是奇數 (`nums1.size() & 1`)，代表 nums2 的所有元素會被保留下來，我們將其全體 XOR 總和累加到 ans 中。
 */

class Solution {
public:
    int xorAllNums(std::vector<int>& nums1, std::vector<int>& nums2) {
        int ans = 0;
        // 若 nums2 長度為奇數，nums1 的每個元素會被保留並參與 XOR
        if (nums2.size() & 1) {
            ans ^= std::reduce(nums1.begin(), nums1.end(), 0, [](const auto& x, const auto& y) {
                return x ^ y;
            });
        }
        // 若 nums1 長度為奇數，nums2 的每個元素會被保留並參與 XOR
        if (nums1.size() & 1) {
            ans ^= std::reduce(nums2.begin(), nums2.end(), 0, [](const auto& x, const auto& y) {
                return x ^ y;
            });
        }
        return ans;
    }
};
