/**
 * 題目：806. Number of Lines To Write String
 * 描述：給你一個陣列 widths，代表 26 個小寫英文字母各自的寬度。
 *       另有一個字串 s。你需要依序將 s 中的字元印出，每行最多 100 個像素。
 *       如果加上當前字元的寬度會超過 100 像素，則必須換到下一行印出。
 *       請返回一個長度為 2 的陣列：[總行數, 最後一行佔用的像素總數]。
 * 
 * 解法思路：
 * 1. 初始化 `linePixel = 0`（目前行已使用的像素）與 `lineCount = 1`（總行數從第 1 行開始）。
 * 2. 走訪字串 `s` 中的每一個字元 `c`：
 *    - 透過 `widths[c - 'a']` 取得該字元的寬度。
 *    - 檢查如果把這個字元加進來（`linePixel + width`）會不會超過 100：
 *      - 若超過，代表當前行裝不下了，必須將 `linePixel` 歸零，並將總行數 `lineCount` 加 1。
 *    - 將當前字元的寬度累加到 `linePixel` 中。
 * 3. 走訪結束後，回傳 `{lineCount, linePixel}`。
 */

class Solution {
public:
    std::vector<int> numberOfLines(std::vector<int>& widths, std::string s) {
        int linePixel = 0;
        int lineCount = 1;
        
        for (const char& c : s) {
            int width = widths[c - 'a'];
            
            // 如果加上當前字元會超過 100 像素，則換行
            if ((linePixel + width) > 100) {
                linePixel = 0;
                lineCount++;
            }
            
            // 累加當前行的像素
            linePixel += width;
        }
        
        return {lineCount, linePixel};
    }
};
