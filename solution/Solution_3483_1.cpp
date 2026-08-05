/**
 * 題目：3483. Unique 3-Digit Even Numbers
 * 難度：簡單 (Easy)
 * 描述：使用給定的 digits 陣列中的數字組成不重複的三位數偶數。
 *
 * 時間複雜度：O(P(N,3))，即排列組合數量級，N 為 digits 長度。
 * 空間複雜度：O(N)，用於遞迴堆疊與標記陣列。
 *
 * 解法思路：
 * 1. 使用回溯法 (Backtracking) 窮舉所有可能的排列。
 * 2. 使用 visited 陣列避免重複使用同一索引的數字。
 * 3. 使用 unordered_set 自動處理數值上的重複，確保結果唯一。
 * 4. 位元檢查 (cur[2] & 1) == 0 判斷偶數，首位判斷 digits[i] != 0。
 */

class Solution {

public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> seen;
        for(int i = 0; i < n; i++) {
            if(digits[i] == 0) continue;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                for(int k = 0; k < n; k++) {
                    if(j == k || i == k || (digits[k] % 2)) continue;
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    seen.insert(num);
                }
            }
        }
        return seen.size();
    }
};
