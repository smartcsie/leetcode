/**
 * 題目：397. Integer Replacement
 * 難度：中等 (Medium)
 * 描述：透過 +1、-1 或 /2 操作將 n 變為 1 的最少步驟。
 */

#include <iostream>

class Solution {
public:
    int integerReplacement(int n) {
        if (n == INT_MAX) {
            return 2 + integerReplacement(n / 2 + 1);
        }
        int ans = 0;
        for (; n > 1; ++ans) {
            if ((n & 1) == 0) 
                n >>= 1;
            else if (n == 3 || (n & 2) == 0) 
                n--;
            else 
                n++;
        }
        return ans;
    }
};
