/**
 * 題目：1680. Concatenation of Consecutive Binary Numbers
 * 難度：中等 (Medium)
 * 描述：將 1 到 n 的二進位數字串聯，回傳 mod 10^9 + 7 的結果。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 透過 i & (i-1) == 0 判斷是否為 2 的冪次，從而動態更新位數長度。
 * 2. 使用 long long 處理中間結果，並在每一步取模防止溢位。
 */

class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        int bits = 0;
        long long ans = 0;
        for(int i = 1; i <= n; i++) {
            if( (i & (i - 1)) == 0) bits++;
            ans = (ans << bits | i) % MOD;
        }
        return static_cast<int>(ans);
    }
};
