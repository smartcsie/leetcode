/**
 * 題目：868. Binary Gap
 * 難度：簡單 (Easy)
 * 描述：在 N 的二進位表示中，找出相鄰兩個 '1' 的最大距離。
 * 優化重點：
 * 1. 位元運算：直接操作二進位，不需要轉換為字串，省空間。
 * 2. 高效遍歷：複雜度為 O(log N)，即 N 的二進位位數。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    int binaryGap(int n) {
        if(__builtin_popcount(n) < 2) return 0;
        int prevIdx = -1;
        int curIdx = 0;
        int ans = 0;
        while(n > 0) {
            if(n & 1) {
                if(prevIdx != -1) {
                    ans = max(ans, curIdx - prevIdx);
                }
                prevIdx = curIdx;
            }
            n >>= 1;
            curIdx++;
        }
        return ans;
    }
};
