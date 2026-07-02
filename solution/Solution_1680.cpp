/**
 * 題目：1680. Concatenation of Consecutive Binary Numbers
 * 難度：中等 (Medium)
 * 描述：將 1 到 n 的二進位數字串聯，回傳 mod 10^9 + 7 的結果。
 * * 時間複雜度：O(N)，每個數字僅處理一次。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 透過 i & (i-1) == 0 判斷是否為 2 的冪次，從而動態更新位數長度。
 * 2. 使用 long long 處理中間結果，並在每一步取模防止溢位。
 */

#include <iostream>

class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int bits = 0; // 當前數字需要的二進位位元數
        
        for (int i = 1; i <= n; i++) {
            // 當 i 為 2 的冪次時（例如 1, 2, 4, 8），位元長度增加
            // i & (i - 1) == 0 是判斷 2 的冪次的經典位元技巧
            if ((i & (i - 1)) == 0) {
                bits++;
            }
            
            // 將現有結果向左位移 bits 位，騰出空間給下一個數字 i
            // 再將 i 加入並取模
            ans = ((ans << bits) | i) % MOD;
        }
        
        return static_cast<int>(ans);
    }
};
