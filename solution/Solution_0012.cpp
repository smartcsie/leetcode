/**
 * 題目：12. Integer to Roman (整數轉羅馬數字)
 * 難度：中等 (Medium)
 * 描述：將整數轉換為羅馬數字。
 *
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> mp = { 
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, 
            {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        string ans;
        for(const auto& [value, str] : mp) {
            while(num >= value) {
                ans += str;
                num -= value;
            }
        }
        return ans;
    }
};
