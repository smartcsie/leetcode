/*
 * 題目：3637. Trionic Array I
 * 難度：Easy
 * 描述：若存在索引 0 < p < q < n - 1，使 nums[0..p] 嚴格遞增、nums[p..q] 嚴格遞減、nums[q..n-1] 嚴格遞增，稱 nums 為 trionic 陣列。判斷給定的 nums 是否為 trionic。
 * 分類主題：array-linear-scan
 * 技巧：峰谷計數, 嚴格單調需排除相等, 順序規則（峰在谷前）
 * 時間複雜度：O(n)
 * 空間複雜度：O(1)
 * 解法思路：
 *   1. 形狀必須是「升 → 降 → 升」，也就是恰好一個峰（先升後降）與一個谷（先降後升），而且峰在谷前
 *   2. 嚴格單調不允許相等，掃描時只要有相鄰元素相等就直接回傳 false
 *   3. 沒有相等時，每個內部位置 i 只可能是峰 (左 < 中 > 右)、谷 (左 > 中 < 右)，或是單調的中間點
 *   4. 遇到峰：若已經有峰或已經有谷（第二個峰，或谷在峰之前）回傳 false，否則記錄峰
 *   5. 遇到谷：若已經有谷（第二個谷）回傳 false，否則記錄谷
 *   6. 最後必須同時有一個峰與一個谷
 */
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int peak = 0, valley = 0;   // 峰、谷的個數
        for(int i = 1; i < n - 1; i++) {
            // 嚴格單調不允許相鄰相等；這個檢查會涵蓋每一對相鄰元素
            if(nums[i - 1] == nums[i] || nums[i] == nums[i + 1]) return false;

            // 峰：左 < 中 > 右
            if(nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
                // 峰必須是第一個轉折：之前已有峰（多個峰）或已有谷（谷在峰前）都不行
                if(peak > 0 || valley > 0) return false;
                peak++;
            }
            // 谷：左 > 中 < 右
            if(nums[i - 1] > nums[i] && nums[i] < nums[i + 1]) {
                // 只能有一個谷
                if(valley > 0) return false;
                valley++;
            }
        }
        // 必須恰好是「升 → 峰 → 降 → 谷 → 升」
        return peak == 1 && valley == 1;
    }
};