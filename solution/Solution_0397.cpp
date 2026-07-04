/**
 * 題目：397. Integer Replacement
 * 難度：中等 (Medium)
 * 描述：透過 +1、-1 或 /2 操作將 n 變為 1 的最少步驟。
 */

#include <iostream>

class Solution {
public:
    int integerReplacement(int n) {
        long long ln = n; // 使用 long long 處理 n+1 的潛在溢位
        int steps = 0;
        
        while (ln > 1) {
            // 如果是偶數，直接右移 (除以 2)
            if ((ln & 1) == 0) {
                ln >>= 1;
            } 
            // 如果是 3 或倒數第二位為 0 (例如 ...01)，減 1 較優
            else if (ln == 3 || (ln & 2) == 0) {
                ln--;
            } 
            // 其他情況 (例如 ...11)，加 1 較優，因為會導致進位產生更多 0
            else {
                ln++;
            }
            steps++;
        }
        return steps;
    }
};
