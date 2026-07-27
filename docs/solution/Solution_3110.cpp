/**
 * 題目：3110. Score of a String (字串的分數)
 * 難度：簡單 (Easy)
 * 描述：計算字串的「分數」，定義為相鄰字元 ASCII 碼差值的絕對值之和。
 * * 時間複雜度：O(N) - 遍歷字串長度 N 一次。
 * 空間複雜度：O(1) - 僅使用整數變數儲存結果。
 * * 解法思路：
 * 1. 初始化一個累加變數 res 為 0。
 * 2. 使用迴圈遍歷字串直到倒數第二個字元 (i < s.size() - 1)。
 * 3. 每次將當前字元 s[i] 與下一個字元 s[i+1] 的差值的絕對值 (abs) 累加到 res 中。
 * 4. 回傳最終的 res。
 */

class Solution {
public:
    int scoreOfString(string s) {
        int res = 0;
        // 遍歷至倒數第二個位置，以確保 s[i+1] 不會越界
        for (int i = 0; i < s.size() - 1; i++) {
            // 使用 abs 計算 ASCII 碼的絕對差值
            res += abs(s[i] - s[i+1]);
        }
        return res;
    }
};
