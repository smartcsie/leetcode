/**
 * 題目：3131. Find the Integer Added to Array I
 * 難度：簡單 (Easy)
 * 描述：找到數組 nums1 中所有元素被增加的整數 x，使得結果等於 nums2。
 * 優化重點：
 * 1. 簡潔直觀：利用最大值的線性關係直接求解。
 * 2. 標準庫優化：使用 std::max_element 快速取得極值。
 *
 * 時間複雜度：O(N) - 單次遍歷，找最大最小值之差。
 * 空間複雜度：O(1) - 僅使用常數空間。
 */

class Solution {
public:
    int addedInteger(std::vector<int>& nums1, std::vector<int>& nums2) {
        // 找到兩個陣列中的最大值
        int max1 = *std::max_element(nums1.begin(), nums1.end());
        int max2 = *std::max_element(nums2.begin(), nums2.end());
        
        // 差值即為被增加的整數 x
        return max2 - max1;
    }
};
