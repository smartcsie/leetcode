/**
 * 題目：2376. Count Special Integers
 * 難度：困難 (Hard)
 * 描述：給定一個正整數 n，求 1 到 n 之間，「所有數字都不重複」的整數
 * （稱為 special integer）總共有幾個。
 *
 * 時間複雜度：O(D²)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （Digit DP，逐位固定前綴、枚舉每一位可能填的數字，統計後面位數的
 * 排列數）：
 * 1. 位數比 n 少的情況：第一位 9 種選擇（1~9），之後每一位選擇數
 *    逐位遞減（因為不能跟前面重複），本質是排列數 P(9, i)，用一個
 *    累乘變數 perm 逐步遞增位數。
 * 2. 位數跟 n 一樣的情況，逐位固定「前面已經跟 n 一樣」的前綴，枚舉
 *    當前這一位可以填的、比 n 這一位小、且還沒被前綴用過的數字 x：
 *    填了 x 之後，後面剩下的位數可以從「還沒用過的數字」裡任意排列，
 *    排列數用 avail（還剩幾個數字可選）跟 slots（還剩幾個位置）算
 *    P(avail, slots)。
 * 3. 如果目前這一位 n 自己的數字已經在前綴裡出現過（used[d] 是
 *    true），代表從這裡開始，n 本身就已經違反「不重複」了，直接
 *    break，不會有 +1 的機會（後面的位數不用再看，因為前綴已經確定
 *    不可能透過原封不動延續 n 的方式湊出合法的 special integer）。
 * 4. 如果一路比對到 n 的最後一位都沒有撞到重複，代表 n 自己就是一個
 *    special integer，答案 +1。
 */
class Solution {
public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int len = s.size();
        long long ans = 0;
        long long perm = 9;
        for (int i = 1; i < len; ++i) {
            ans += perm;
            perm *= (10 - i);
        }
        vector<bool> used(10, false);
        for (int i = 0; i < len; ++i) {
            int d = s[i] - '0';
            int start = (i == 0) ? 1 : 0;
            for (int x = start; x < d; ++x) {
                if (used[x]) continue;
                long long ways = 1;
                int avail = 10 - (i + 1);
                int slots = len - i - 1;
                for (int j = 0; j < slots; ++j) ways *= (avail - j);
                ans += ways;
            }
            if (used[d]) break;
            used[d] = true;
            if (i == len - 1) ans += 1;
        }
        return (int)ans;
    }
};
