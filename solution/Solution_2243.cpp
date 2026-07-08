/**
 * 題目：2243. Calculate Digit Sum of a String
 * 難度：簡單 (Easy)
 * 描述：重複將長度大於 k 的字串分組並替換為各組數位和的字串形式。
 * * 優化重點：
 * 1. 外層迴圈：使用 while 循環持續檢查長度是否大於 k。
 * 2. 分組處理：使用步進式 for 迴圈 (i += k) 進行分組。
 * 3. 類型轉換：透過 str[j] - '0' 取得整數，並用 to_string 將和轉回字串。
 */

#include <string>

class Solution {
public:
    std::string digitSum(std::string s, int k) {
        std::string current = s;
        
        // 持續縮減字串直到長度小於等於 k
        while (current.size() > k) {
            std::string next = "";
            
            // 以 k 為單位進行分組加總
            for (int i = 0; i < current.size(); i += k) {
                int sum = 0;
                // 加總當前 k 個數字
                for (int j = i; j < i + k && j < current.size(); j++) {
                    sum += (current[j] - '0');
                }
                next += std::to_string(sum);
            }
            current = next;
        }
        
        return current;
    }
};
