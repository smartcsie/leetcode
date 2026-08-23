/**
 * 題目：402. Remove K Digits
 * 難度：中等 (Medium)
 * 分類主題：greedy-digit-construction
 * 描述：給定一個以字串表示的非負整數 num，移除其中 k 位數字，讓剩下
 * 的數字組成的新數字盡量小（不能有多餘的前導零）。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （單調遞增堆疊，這是這個 pattern 裡最經典的模板：想讓數字最小，
 * 高位數字越小越好，所以只要「前面的數字比後面大」就該優先刪掉
 * 前面的）：
 * 1. 用一個字串當堆疊，依序處理每個數字字元：只要堆疊還有剩餘的
 *    刪除次數（k > 0）、且堆疊頂端的數字比目前這個字元大，就把
 *    堆疊頂端彈出（相當於刪掉它），k 減 1；重複這個檢查直到條件
 *    不成立，再把目前字元放進堆疊。
 * 2. 這樣能保證堆疊裡的數字序列「盡量遞增」，因為只要出現逆序
 *    （前面比後面大）就會被優先消除，逆序代表「刪掉前面那個能讓
 *    高位變小，對整體數值影響最大」。
 * 3. 如果遍歷完字串，k 還有剩（代表整個字串是遞增的，前面完全沒有
 *    逆序可刪），直接從堆疊尾端刪除剩下的 k 個（因為遞增序列裡，
 *    尾端的數字對整體數值影響最小，刪尾端最划算）。
 * 4. 處理前導零：從結果字串開頭找到第一個非零字元的位置，把前面的
 *    零都切掉；如果切完是空字串，代表結果是 0。
 */
class Solution {
public:
    string removeKdigits(string num, int k) {
        string stack;
        for (char c : num) {
            while (!stack.empty() && k > 0 && stack.back() > c) {
                stack.pop_back();
                k--;
            }
            stack += c;
        }
        while (k > 0 && !stack.empty()) {
            stack.pop_back();
            k--;
        }
        int start = 0;
        while (start < (int)stack.size() - 1 && stack[start] == '0') start++;
        stack = stack.substr(start);
        return stack.empty() ? "0" : stack;
    }
};
