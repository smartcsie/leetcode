/**
 * 題目：1358. Number of Substrings Containing All Three Characters (包含所有三種字元的子字串數)
 * 難度：中等 (Medium)
 * 描述：計算字串中包含至少一個 'a', 'b', 'c' 的子字串總數。
 * * 時間複雜度：O(N)，每個字元最多被 left 與 i 指針各遍歷一次。
 * 空間複雜度：O(1)，固定大小的 count 陣列。
 * * 優化思路：
 * 1. 利用數學邏輯：當視窗 [left, i] 滿足條件時，以 i 為結尾且滿足條件的子字串共有 `left + 1` 個。
 * (這與你原程式碼的 `res += n - i` 邏輯不同，但在處理邏輯上更為直觀)。
 */

class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0, n = s.size(), left = 0;
        vector<int> count(3, 0);
        for(int i = 0; i < n; i++) {
            ++count[s[i] - 'a'];
            while(count[0] && count[1] && count[2] ){
                res += n - i;
                --count[s[left++] - 'a'];
            }
        }
        return res;
    }
};
