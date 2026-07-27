/**
 * 題目：926. Flip String to Monotone Increasing
 * 難度：中等 (Medium)
 * 描述：計算讓字串變成單調遞增（所有 0 在 1 前）所需的最少翻轉次數。
 * * 時間複雜度：O(N) - N 為字串長度，只需遍歷一次。
 * 空間複雜度：O(1) - 僅使用兩個變數記錄狀態。
 * * 解法思路：
 * 1. count[0] 代表「以當前位置結尾，且為單調遞增狀態，且結尾為 0」所需的最小翻轉數。
 * 2. count[1] 代表「以當前位置結尾，且為單調遞增狀態，且結尾為 1」所需的最小翻轉數。
 * 3. 若遇到 '0'：
 *    - 結尾為 0：不需要翻轉 (count[0] 不變)。
 *    - 結尾為 1：需要將當前 '0' 翻轉為 '1' (count[1] = count[1] + 1)。
 * 4. 若遇到 '1'：
 *    - 結尾為 0：需要將當前 '1' 翻轉為 '0' (count[0] = count[0] + 1)。
 *    - 結尾為 1：不需要翻轉，可繼承前一個位置結尾為 0 或 1 的狀態 (count[1] = min(count[0], count[1]))。
 */

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> count(2, 0);
        for(const char& c : s) {
            count[c - '0']++;
            count[0] = min(count[0], count[1]);
        }
        return count[0];
    }
};
