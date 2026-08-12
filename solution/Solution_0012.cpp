/**
 * 題目：12. Integer to Roman (整數轉羅馬數字)
 * 難度：中等 (Medium)
 * 描述：將整數轉換為羅馬數字。
 *
 * 時間複雜度：O(1) - 羅馬數字最大值有限，遍歷次數固定。
 * 空間複雜度：O(1) - 使用固定大小的陣列。
 */

class Solution {
public:
    string intToRoman(int num) {
        vector<int> values =     {1000,     900,    500 ,   400,    100,    90,     
                                    50,     40,     10,     9,      5,      4,      1};
        vector<string> symbols = {"M",      "CM",   "D",    "CD",   "C",    "XC",
                                    "L",    "XL",   "X",    "IX",   "V",    "IV",   "I"};
        string ans;
        for(int i = 0; i < values.size(); i++) {
            if(num == 0) break;
            while(num >= values[i]) {
                num -= values[i];
                ans += symbols[i];
            }
        }
        return ans;
    }
};
