// 題目：2309. Greatest English Letter in Upper and Lower Case
// 難度：Easy
// 時間複雜度：O(n)
// 空間複雜度：O(1)
// 分類主題：string / bit-manipulation
// 技巧：兩個 26-bit 位元遮罩（bitmask）記錄大小寫出現過哪些字母，AND 後取最高位 1

class Solution {
public:
    string greatestLetter(string s) {
        // bit i 代表第 i 個字母（a/A 是 bit 0，z/Z 是 bit 25）是否出現過
        uint32_t lower = 0;   // 出現過的小寫字母
        uint32_t upper = 0;   // 出現過的大寫字母
        for(const char& c : s) {
            // 要用 |= 累積；用 = 會把前面的結果覆蓋掉
            if(islower(c)) lower |= 1U << (c - 'a');
            else           upper |= 1U << (c - 'A');
        }

        // 大小寫都出現過的字母：兩個遮罩都是 1 的位置
        uint32_t common = lower & upper;
        if(common == 0) return "";

        // bit_width(x) = 最高位 1 的位置 + 1，所以 bit_width - 1 就是最大字母的索引
        // 例：common 最高位是 bit 4（'E'）-> bit_width = 5 -> 4 -> 'A' + 4 = 'E'
        return string(1, 'A' + (bit_width(common) - 1));
    }
};