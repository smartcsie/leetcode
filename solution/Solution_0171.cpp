/**
 * 題目：171. Excel Sheet Column Number
 * 描述：將 Excel 的欄位名稱 (如 "A", "AB") 轉換為對應的數字。
 * 
 * 解法思路：
 * 1. 將 Excel 欄位視為 26 進位系統。
 * 2. 遍歷字串，每一位數的值為 `sum * 26 + (當前字母轉數字)`。
 * 3. 使用 `std::accumulate` 進行累加，將字串從左到右摺疊計算出最終結果。
 */

#include <string>
#include <numeric>

class Solution {
public:
    int titleToNumber(std::string columnTitle) {
        // 使用 accumulate 進行左摺疊運算 (Left Fold)
        return std::accumulate(columnTitle.begin(), columnTitle.end(), 0, [](int sum, char c) {
            return sum * 26 + (c - 'A' + 1);
        });
    }
};
