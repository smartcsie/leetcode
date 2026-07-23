/**
 * 題目：1189. Maximum Number of Balloons
 * 描述：給你一個字串 text，你可以使用 text 中的字元來拼湊單字 "balloon"。
 *       請返回最多可以拼湊出多少個完整的 "balloon"。
 * 
 * 解法思路：
 * 1. 建立一個大小為 26 的頻率陣列 `counts`，用來統計目標單字 "balloon" 中每個字母需要的個數。
 * 2. 建立另一個大小為 26 的頻率陣列 `ballons`，用來統計輸入字串 `text` 中每個字母的實際擁有量。
 * 3. 走訪 "balloon" 的每個字元（利用 `std::string_view` 避免結尾空字元問題），填入 `counts`。
 * 4. 走訪 `text` 的每個字元，填入 `ballons`。
 * 5. 針對 "balloon" 內有出現的字母（counts[i] > 0），計算 `ballons[i] / counts[i]`，
 *    並找出所有字母中的最小值 (`minBallons`)，此即為能組出的最大單字數量。
 */

class Solution {
public:
    int maxNumberOfBalloons(std::string text) {
        // 1. 統計單字 "balloon" 每個字母的需求頻率
        std::vector<int> counts(26, 0);
        for (const char& c : std::string_view("balloon")) {
            counts[c - 'a']++;
        }
        // 2. 統計輸入字串 text 每個字母的實際擁有頻率
        std::vector<int> ballons(26, 0);
        for (const char& c : text) {
            ballons[c - 'a']++;
        }
        // 3. 計算各個字母能支持的組數，取最小值
        int minBallons = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (counts[i] > 0) {
                minBallons = std::min(minBallons, ballons[i] / counts[i]);
            }
        }
        return minBallons;
    }
};
