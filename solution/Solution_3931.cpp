/**
 * 題目：3931. Check Adjacent Digit Differences (檢查相鄰數位差值)
 * 難度：簡單 (Easy)
 * 描述：檢查字串中所有相鄰數字的差值絕對值是否皆不超過 2。
 * * 時間複雜度：O(N)，遍歷字串一次。
 * 空間複雜度：O(1)，僅使用常數空間。
 * * 優化思路：
 * 1. 防禦性程式設計：明確處理空字串或單字元情況。
 * 2. 邏輯簡化：直接使用 `std::abs` 進行數值運算，這是 C++ 中最快且最易維護的寫法。
 */

class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i = 1; i < s.size(); i++) {
            if(abs(s[i] - s[i-1]) > 2) return false;
        }
        return true;
    }
};
