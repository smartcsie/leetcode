/**
 * 題目：2309. Greatest English Letter in Upper and Lower Case
 * 難度：簡單 (Easy)
 * 描述：給你一個由英文大寫和小寫字母組成的字串 s，請找出並返回 s 中
 * 「英文大寫和小寫同時出現」的字母中，字典序最大的字母。
 * 如果找不到這樣的字母，返回空字串 ""。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 原生整數位元遮罩（Integer Bitmask）：
 * - 宣告兩個整數 `upper` 與 `lower` 分別作為大寫和小寫字母的狀態壓縮記錄器。
 * - 當遇到大寫字母 `c` 時，透過 `upper |= (1 << (c - 'A'))` 將對應的 bit 設為 1。
 * - 當遇到小寫字母時，透過 `lower |= (1 << (c - 'a'))` 將對應的 bit 設為 1。
 * 2. 由大到小尋找最大交集：
 * - 從 `i = 25`（對應字元 `'Z'`）倒數迴圈到 `0`（對應字元 `'A'`）。
 * - 檢查當前 bit 在 `upper` 與 `lower` 中是否同時為 1：`(upper & (1 << i)) && (lower & (1 << i))`。
 * - 一旦找到符合條件的第一個字母，立刻組合成字串返回，即為字典序最大的解。
 */

class Solution {
public:
    std::string greatestLetter(std::string s) {
        int mx = 0;
        bitset<26> lower;
        bitset<26> upper;
        for(const char& c : s) {
            if(islower(c)) lower.set(c - 'a');
            else upper.set(c - 'A');
            if(lower.test((c | 32) - 'a') && upper.test((c | 32) - 'a')) {
                mx = max(mx, (c & (~32)));
            }
        }
        return mx == 0 ? "" : string(1, mx);
    }
};
