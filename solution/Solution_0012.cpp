/**
 * 題目：12. Integer to Roman (整數轉羅馬數字)
 * 難度：中等 (Medium)
 * 描述：將整數轉換為羅馬數字。
 * * 時間複雜度：O(1) - 羅馬數字最大值有限，遍歷次數固定。
 * 空間複雜度：O(1) - 使用固定大小的陣列。
 */

class Solution {
public:
    string intToRoman(int num) {
        // 使用靜態陣列避免動態配置
        static const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        static const string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string res;
        res.reserve(16); // 羅馬數字最大長度不會超過 16
        
        for (int i = 0; i < 13; ++i) {
            // 只要 num 大於等於當前數值，就持續累加該符號
            // 這種貪婪策略適用於羅馬數字的建構規則
            while (num >= values[i]) {
                num -= values[i];
                res += symbols[i];
            }
        }
        return res;
    }
};
