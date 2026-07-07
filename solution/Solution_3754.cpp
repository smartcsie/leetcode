/**
 * 題目：3754. Concatenate Non-Zero Digits and Multiply by Sum I
 * 難度：簡單 (Easy)
 * 描述：提取所有非零位元並連接成新數字，再乘以這些非零位元的加總。
 * * 優化重點：
 * 1. 字串轉換：利用 to_string 將數字轉為字元陣列進行處理。
 * 2. 條件篩選：忽略 '0' 字元，同時建立串接字串與加總數值。
 * 3. 類型安全：使用 stoll 處理拼接後可能變大的數字，並透過 long long 進行最終乘法。
 */

class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;
        std::string s = to_string(n);
        std::string str_num = "";
        int digit_sum = 0;
        for (const char& c : s) {
            if (c != '0') {
                str_num.push_back(c);
                digit_sum += (c - '0');
            }
        }
        return std::stoll(str_num) * static_cast<long long>(digit_sum);
    }
};
