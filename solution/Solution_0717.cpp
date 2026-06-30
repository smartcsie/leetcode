/**
 * 題目：717. 1-bit and 2-bit Characters (1-bit 與 2-bit 字元)
 * 難度：簡單 (Easy)
 * 描述：判斷最後一個字元是否為 1-bit 字元。
 * * 時間複雜度：O(N)，N 為陣列長度。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 簡化指標移動邏輯。
 * 2. 移除不必要的變數以節省空間。
 */

#include <vector>

class Solution {
public:
    bool isOneBitCharacter(std::vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        
        // 貪婪法：直接模擬掃描過程
        while (i < n - 1) {
            // 如果當前是 1，代表是 2-bit 字元 (10 或 11)，直接跳過兩位
            // 如果當前是 0，代表是 1-bit 字元，跳過一位
            i += (bits[i] == 1) ? 2 : 1;
        }
        
        // 如果指標剛好停在最後一個位置，代表它是獨立的 1-bit 字元
        return i == n - 1;
    }
};
