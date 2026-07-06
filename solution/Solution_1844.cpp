/**
 * 題目：1844. Replace All Digits with Characters
 * 難度：簡單 (Easy)
 * 描述：將每個數字字元替換為前一個字元向後位移該數字代表的數值。
 * * 優化重點：
 * 1. 原地修改：直接在輸入字串上操作，無需建立新的字串物件。
 * 2. 算術技巧：利用 ASCII 碼的連續性，`s[i-1] + (s[i] - '0')` 即可得到目標字元。
 * 3. 步長調整：每次迴圈增加 2，精準定位每個數字位元。
 */

class Solution {
public:
    std::string replaceDigits(std::string s) {
        // 從第二個元素開始，每兩步處理一次
        for (int i = 1; i < s.size(); i += 2) {
            // s[i] - '0' 將數字字元轉換為整數偏移量
            // s[i-1] + 偏移量 = 新字元
            s[i] = s[i - 1] + (s[i] - '0');
        }
        return s;
    }
};
