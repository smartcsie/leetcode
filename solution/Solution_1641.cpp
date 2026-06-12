/**
 * 題目：1641. Count Sorted Vowel Strings (統計元音字串數量)
 * 難度：中等 (Medium)
 * 描述：找出長度為 n 且字典序非遞減的元音字串數量。
 * * 時間複雜度：O(1) - 組合計算固定次數。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 1. 數學建模：此問題等價於將 n 個物件放入 5 個箱子，公式為 C(n+5-1, 5-1) = C(n+4, 4)。
 * 2. 避免溢位：分步驟相乘並除以整數。
 */

class Solution {
private:
    long combination(int n, int k) {
        if(k == 0 || k == n) return 1;
        long res = 1;
        if (k > n / 2) k = n - k;
        for(int i = 1; i <= k; i++) {
            res = res * (n - i + 1) / i;
        }
        return res;
    }
public:
    int countVowelStrings(int n) {
        int res = 1;
        for (int i = 1; i <= 4; ++i) {
            res = res * (n + i) / i;
        }
        return static_cast<int>(res);
    }
};
