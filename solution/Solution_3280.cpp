/**
 * 題目：3280. Convert Date to Binary
 * 難度：簡單 (Easy)
 * 描述：將 YYYY-MM-DD 格式的日期中的數字部分轉換為二進位表示。
 * * 優化重點：
 * 1. C++20 format：使用標準庫中的格式化功能，代碼簡潔且高效。
 * 2. 嚴謹解析：利用日期格式固定長度的特性進行切割。
 */

#include <string>
#include <format> // C++20

class Solution {
public:
    std::string convertDateToBinary(std::string date) {
        // 切割字串並轉為整數
        int year = std::stoi(date.substr(0, 4));
        int month = std::stoi(date.substr(5, 2));
        int day = std::stoi(date.substr(8, 2));
        
        // 使用 format 進行二進位轉換，{:b} 代表二進位輸出
        return std::format("{:b}-{:b}-{:b}", year, month, day);
    }
};
