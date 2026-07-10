/**
 * 題目：868. Binary Gap
 * 難度：簡單 (Easy)
 * 描述：在 N 的二進位表示中，找出相鄰兩個 '1' 的最大距離。
 * * 優化重點：
 * 1. 位元運算：直接操作二進位，不需要轉換為字串，省空間。
 * 2. 高效遍歷：複雜度為 O(log N)，即 N 的二進位位數。
 */

#include <algorithm>
#include <climits>

class Solution {
public:
    int binaryGap(int n) {
        // 若 '1' 的數量少於 2，不存在間距
        if (__builtin_popcount(n) < 2) return 0;
        
        int pre_one_idx = -1;
        int max_gap = 0;
        int index = 0;
        
        while (n > 0) {
            // 檢查當前最低位是否為 1
            if (n & 1) {
                if (pre_one_idx != -1) {
                    max_gap = std::max(max_gap, index - pre_one_idx);
                }
                pre_one_idx = index;
            }
            n >>= 1; // 右移處理下一位
            index++;
        }
        
        return max_gap;
    }
};
