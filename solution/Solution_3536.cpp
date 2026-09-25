/**
 * 題目：3536. Maximum Product of Two Digits
 * 難度：簡單 (Easy)
 * 描述：找出數字 n 的所有數位中最大的兩個，並返回它們的乘積。
 * 優化重點：
 * 1. 單次遍歷：在拆解數字的過程中同時更新 max 與 second_max。
 * 2. 邊界處理：初始化為 -1，確保數字不足兩位時能正確處理（視題目需求而定）。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 */

#include <algorithm>

class Solution {
public:
    int maxProduct(int n) {
        int mx1 = -1, mx2 = -1;
        while(n > 0) {
            int d = n % 10;
            if(d > mx1) {
                mx2 = mx1;
                mx1 = d;
            } else if(d > mx2) {
                mx2 = d;
            }
            n /= 10;
        }
        return mx1 * mx2;
    }
};
