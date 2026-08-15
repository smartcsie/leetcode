/**
 * 題目：970. Powerful Integers (強力整數)
 * 難度：中等 (Medium)
 * 描述：尋找所有能表示為 x^i + y^j <= bound 的數。
 *
 * 時間複雜度：O(log_X(BOUND)*log_Y(BOUND))
 * 空間複雜度：O(S)，其中 S 是找到的強力整數個數。
 *
 * 設計思路：
 * 1. 強力整數的數值受限於 bound，因此 x^i 和 y^j 的最大指數不超過 log(bound)。
 * 2. 使用雙重迴圈窮舉所有可能的指數組合，並使用 unordered_set 去重。
 * 3. 注意：當 x 或 y 為 1 時，需要特殊處理以防止無限迴圈。
 */

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> ans;
        for (int a = 1; a <= bound; a *= x) {
            for (int b = 1; a + b <= bound; b *= y) {
                ans.insert(a + b);
                if (y == 1)   break;
            }
            if (x == 1)  break;
        }
        return vector<int>(ans.begin(), ans.end());
    }
};
