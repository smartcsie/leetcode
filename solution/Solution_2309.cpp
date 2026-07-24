/**
 * 題目：2309. Greatest English Letter in Upper and Lower Case
 * 描述：給你一個由英文大寫和小寫字母組成的字串 s，請找出並返回 s 中
 *       「英文大寫和小寫同時出現」的字母中，字典序最大的字母。
 *       如果找不到這樣的字母，返回空字串 ""。
 * 
 * 解法思路：
 * 1. 原生整數位元遮罩（Integer Bitmask）：
 *    - 宣告兩個整數 `upper` 與 `lower` 分別作為大寫和小寫字母的狀態壓縮記錄器。
 *    - 當遇到大寫字母 `c` 時，透過 `upper |= (1 << (c - 'A'))` 將對應的 bit 設為 1。
 *    - 當遇到小寫字母時，透過 `lower |= (1 << (c - 'a'))` 將對應的 bit 設為 1。
 * 2. 由大到小尋找最大交集：
 *    - 從 `i = 25`（對應字元 `'Z'`）倒數迴圈到 `0`（對應字元 `'A'`）。
 *    - 檢查當前 bit 在 `upper` 與 `lower` 中是否同時為 1：`(upper & (1 << i)) && (lower & (1 << i))`。
 *    - 一旦找到符合條件的第一個字母，立刻組合成字串返回，即為字典序最大的解。
 */

class Solution {
public:
    std::string greatestLetter(std::string s) {
        int upper = 0;
        int lower = 0;
        // 走訪字串，將大寫與小寫字母分別記錄進對應的整數 bitmask 中
        for (const char& c : s) {
            if (isupper(c)) {
                upper |= (1 << (c - 'A'));
            } else {
                lower |= (1 << (c - 'a'));
            }
        }
        // 從 'Z' (25) 到 'A' (0) 依序檢查是否存在同時擁有大小寫的字母
        for (int i = 25; i >= 0; --i) {
            if ((upper & (1 << i)) && (lower & (1 << i))) {
                return std::string(1, i + 'A');
            }
        }
        return "";
    }
};
