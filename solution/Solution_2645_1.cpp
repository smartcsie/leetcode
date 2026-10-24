/**
 * 題目：2645. Minimum Additions to Make Valid String
 * 難度：Medium
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 * 分類主題：math-formula
 *
 * 解法說明：
 * 最終合法字串是 k 組 "abc"，長度為 3k，所以需補的字元數 = 3k - n。
 * 問題變成：word 最少要分散到幾組 "abc" 裡（求 k）。
 * 同一組 "abc" 內字元必須嚴格遞增（a < b < c），
 * 所以只要相鄰字元「不遞增」(word[i] <= word[i-1])，就必須開新的一組。
 *   k = 1（第一組） + 「不遞增」的相鄰位置數
 */
class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();

        // 至少需要一組 "abc"（word 長度 >= 1）
        int k = 1;

        // 相鄰字元沒有嚴格遞增（如 "aa"、"ba"、"cb"）→ 後者無法接在前者同一組，需另開新組
        for(int i = 1; i < n; i++) {
            if(word[i] <= word[i - 1]) k++;
        }

        // 總長度 3k 減去已有的 n 個字元，就是要補的數量
        return 3 * k - n;
    }
};