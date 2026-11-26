/**
 * 題目：3884. First Matching Character From Both Ends
 * 難度：簡單 (Easy)
 * 描述：在字串中找到第一個左右指標指向相同字元的索引位置。
 * 優化重點：
 * 1. 雙指標法 (Two-pointers)：同時從頭 (left) 與尾 (right) 進行檢查，將複雜度壓縮至單次遍歷。
 * 2. 提前中斷：一旦找到符合條件的字元，立即返回結果，達到最佳效能。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */


class Solution {
public:
    int firstMatchingIndex(string s) {
        int n = s.size();
        for(int i = 0; i <= n / 2; i++) {
            if(s[i] == s[n - 1 - i]) return i;
        }
        return -1;
    }
};