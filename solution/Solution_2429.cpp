/**
 * 題目：2429. Minimize XOR
 * 難度：中等 (Medium)
 * 描述：找到一個與 num2 具有相同 set bits 數量的 x，使 num1 ^ x 最小。
 * 優化重點：
 * 1. 貪婪分配：先利用 num1 的 1 進行抵銷，再補齊剩餘位元。
 * 2. 高效位元計數：利用 __builtin_popcount 快速獲取位元需求。
 *
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bits = __builtin_popcount(num2);
        int msb = bit_width(static_cast<unsigned int>(num1)) - 1;
        int ans = 0;
        for(int i = msb; i >= 0 && bits > 0; i--) {
            if(num1 & (1 << i)) {
                ans |= 1 << i;
                bits--;
            }
        }
        if(bits == 0) return ans;
        for(int i = 0; i < 32 && bits > 0; i++) {
            if(!((ans >> i) & 1)) {
                ans |= 1 << i;
                bits--;
            }
        }
        return ans;
    }
};
