/**
 * 題目：3483. Unique 3-Digit Even Numbers
 * 難度：簡單 (Easy)
 * 描述：使用給定的 digits 陣列中的數字組成不重複的三位數偶數。
 * 優化重點：
 * 1. 使用位元運算 (num & 1) == 0 判斷偶數，效率極高。
 * 2. 透過條件檢查提前終止不必要的迴圈。
 * 3. 使用 unordered_set 確保結果的唯一性。
 *
 * 時間複雜度：O(N^3)
 * 空間複雜度：O(U)
 */


class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        unordered_set<int> seen;
        int n = digits.size();
        for(int i = 0; i < n ;i++) {
            if(digits[i] == 0) continue;
            for(int j = 0; j < n ;j++) {
                if(i == j) continue;
                for(int k = 0; k < n ;k++) {
                    if(i == k || j == k) continue;
                    if(digits[k] & 1) continue;
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    seen.insert(num);
                }
            }
        }
        return seen.size();
    }
};
