/**
 * 題目：3132. Find the Integer Added to Array II
 * 難度：中等 (Medium)
 * 描述：在刪除 nums1 中兩個元素後，找到一個整數 x 使得剩餘元素加上 x 後等於 nums2。
 * * 優化重點：
 * 1. 暴力枚舉：僅枚舉前三個對應關係，極大縮小搜尋空間。
 * 2. 雙指標：高效驗證 x 的可行性，時間複雜度 O(N)。
 */

class Solution {
public:
    int minimumAddedInteger(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::ranges::sort(nums1);
        std::ranges::sort(nums2);
        
        // 鎖定 nums2[0] 的三種可能對應來源
        std::vector<int> cand = {nums2[0] - nums1[0], nums2[0] - nums1[1], nums2[0] - nums1[2]};
        std::ranges::sort(cand); // 確保我們先測試最小的 x
        
        for(int x : cand) {
            int j = 0, skipped = 0;
            // 使用雙指標驗證 x 是否可行
            for(int i = 0; i < (int)nums1.size(); i++) {
                if(j < (int)nums2.size() && nums1[i] + x == nums2[j]) {
                    j++;
                } else {
                    skipped++;
                }
                // 若刪除超過 2 個元素，則此 x 不可行
                if(skipped > 2) break;
            }
            if(j == (int)nums2.size()) return x;
        }
        return -1;
    }
};
