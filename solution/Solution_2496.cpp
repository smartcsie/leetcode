/**
 * 題目：2496. Maximum Value of a String in an Array
 * 描述：給定一個字串陣列 strs，若字串包含英文字母則值為其長度，
 *       若僅包含數字則值為其轉成的整數。請返回所有字串中的最大值。
 * 
 * 解法思路：
 * 1. 宣告一個 `maxVal` 變數來追蹤歷經的最大數值，初值設為 0。
 * 2. 走訪 `strs` 中的每一個字串 s：
 *    - 利用 `std::any_of` 搭配 `::isalpha` 檢查字串中是否有夾雜英文字母。
 *    - 如果有字母，數值 `val` 為字串長度 `s.size()`。
 *    - 如果全為數字，則使用 `std::stoi(s)` 將字串轉為整數。
 * 3. 透過 `std::max` 持續更新 `maxVal`。
 * 4. 迴圈結束後返回 `maxVal`。
 */

class Solution {
public:
    int maximumValue(std::vector<std::string>& strs) {
        int maxVal = 0;
        for (std::string& s : strs) {
            // 檢查字串是否包含英文字母
            bool hasAlpha = std::any_of(s.begin(), s.end(), ::isalpha);
            // 若包含字母則取長度，否則將字串轉為整數
            int val = hasAlpha ? s.size() : std::stoi(s);
            // 更新全域最大值
            maxVal = std::max(maxVal, val);
        }
        return maxVal;
    }
};
