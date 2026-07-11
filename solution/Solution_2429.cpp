/**
 * 題目：2429. Minimize XOR
 * 難度：中等 (Medium)
 * 描述：找到一個與 num2 具有相同 set bits 數量的 x，使 num1 ^ x 最小。
 * * 優化重點：
 * 1. 貪婪分配：先利用 num1 的 1 進行抵銷，再補齊剩餘位元。
 * 2. 高效位元計數：利用 __builtin_popcount 快速獲取位元需求。
 */

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bits = __builtin_popcount(num2);
        int res = 0;
        
        // 第一階段：優先匹配 num1 中現有的 1
        for (int i = 31; i >= 0; i--) {
            if ((num1 & (1 << i)) && bits > 0) {
                res |= (1 << i);
                bits--;
            }
        }
        
        // 第二階段：若 bits 還有剩，由低位往高位補齊 0
        for (int i = 0; i <= 31; i++) {
            if (!(res & (1 << i)) && bits > 0) {
                res |= (1 << i);
                bits--;
            }
        }
        
        return res;
    }
};
