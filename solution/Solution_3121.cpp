/**
 * 題目：3121. Count the Number of Special Characters II
 * 難度：中等 (Medium)
 * 描述：計算滿足以下條件的字母個數：小寫字母至少出現一次，且所有小寫出現位置皆在所有大寫之前。
 * 優化重點：
 * 1. 紀錄狀態：使用一個大小為 26 的 pair 陣列，儲存 `{大寫第一次出現索引, 小寫最後一次出現索引}`。
 * 2. 條件判斷：
 * - 大寫必須存在 (first != -1)
 * - 小寫必須存在 (second != -1)
 * - 必須滿足：最後一個小寫位置 < 第一個大寫位置。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    int numberOfSpecialChars(string word) {
        uint32_t lower = 0;   // 出現過的小寫字母
        uint32_t upper = 0;   // 出現過的大寫字母
        uint32_t bad = 0;     // 小寫出現在大寫之後的字母（失格）

        for(char c : word) {
            if(islower(c)) {
                int b = c - 'a';
                if(upper & (1u << b)) bad |= 1u << b;   // 對應的大寫已經出現過，這個小寫來得太晚
                lower |= 1u << b;
            } else {
                upper |= 1u << (c - 'A');
            }
        }
        // 大小寫都出現過，且沒有失格的字母數量
        return popcount(lower & upper & ~bad);
    }
};