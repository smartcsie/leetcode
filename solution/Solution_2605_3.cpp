/**
 * 題目：2605. Form Smallest Number From Two Digit Arrays
 * 難度：簡單 (Easy)
 * 描述：給兩個由 1~9 組成的陣列 nums1、nums2，
 *       回傳最小的數字，且其十進位表示中，兩個陣列各至少有一個數字出現。
 *
 * 解法思路：位元遮罩 (Bitmask)
 * 1. 用 int 的第 x 位元表示「數字 x 是否出現」，得到 seen1、seen2。
 * 2. 從 1 到 9 由小到大掃描：
 *    - 若 i 同時出現在兩個陣列，答案就是單一位數 i，直接回傳
 *      （單位數一定比兩位數小，且由小到大掃描，第一個就是最小）。
 *    - 同時記錄各陣列的最小數字 mn1、mn2。
 * 3. 沒有共同數字時，答案必為兩位數：
 *    取 mn1、mn2 兩種排列中較小者，即 min(mn1*10 + mn2, mn2*10 + mn1)。
 *
 * 時間複雜度：O(n + m + 9)，即 O(n + m)
 * 空間複雜度：O(1)
 */
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        // seen1 / seen2：第 x 位元為 1，代表該陣列含有數字 x
        int seen1 = 0, seen2 = 0;
        for (const int& x : nums1) seen1 |= 1 << x;  // 標記 nums1 出現過的數字
        for (const int& x : nums2) seen2 |= 1 << x;  // 標記 nums2 出現過的數字

        // mn1 / mn2：各陣列的最小數字，-1 表示尚未找到
        int mn1 = -1, mn2 = -1;
        for (int i = 1; i <= 9; i++) {
            int mask = 1 << i;  // 只保留第 i 位元，用來檢查數字 i

            // 兩個陣列都有 i：單位數 i 即為最小答案
            if ((seen1 & mask) && (seen2 & mask)) return i;

            // 第一次遇到的就是該陣列的最小值（因為 i 由小到大）
            if (mn1 == -1 && (seen1 & mask)) mn1 = i;
            if (mn2 == -1 && (seen2 & mask)) mn2 = i;
        }

        // 無共同數字：兩個最小值組成兩位數，十位數放較小者才會更小
        return min(mn1 * 10 + mn2, mn2 * 10 + mn1);
    }
};