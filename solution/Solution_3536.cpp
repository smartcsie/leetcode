/**
 * 題目：3536. Maximum Product of Two Digits
 * 難度：簡單 (Easy)
 * 描述：找出數字 n 的所有數位中最大的兩個，並返回它們的乘積。
 * * 優化重點：
 * 1. 單次遍歷：在拆解數字的過程中同時更新 max 與 second_max。
 * 2. 邊界處理：初始化為 -1，確保數字不足兩位時能正確處理（視題目需求而定）。
 */

#include <algorithm>

class Solution {
public:
    int maxProduct(int n) {
        int first_max = -1;
        int second_max = -1;
        
        while (n > 0) {
            int digit = n % 10;
            if (digit > first_max) {
                second_max = first_max;
                first_max = digit;
            } else if (digit > second_max) {
                second_max = digit;
            }
            n /= 10;
        }
        
        return first_max * second_max;
    }
};
