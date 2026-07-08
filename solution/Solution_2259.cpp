/**
 * 題目：2259. Remove Digit From Number to Maximize Result
 * 難度：簡單 (Easy)
 * 描述：移除字串中指定的一個 digit，使得剩餘字串代表的數值最大。
 * * 優化重點：
 * 1. 貪婪搜索：O(N) 單次掃描決定移除位置。
 * 2. 字串操作：利用 string::erase 與 string::rfind 簡潔處理字串變動。
 */

#include <string>

class Solution {
public:
    std::string removeDigit(std::string number, char digit) {
        // 貪婪遍歷：尋找第一個出現且後方數值更大的 digit
        for (int i = 0; i < number.size() - 1; ++i) {
            if (number[i] == digit && digit < number[i + 1]) {
                return number.erase(i, 1);
            }
        }
        
        // 若未找到，則移除最後一個出現的 digit
        return number.erase(number.rfind(digit), 1);
    }
};
