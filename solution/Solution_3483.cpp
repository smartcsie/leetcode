/**
 * 題目：3483. Unique 3-Digit Even Numbers
 * 難度：簡單 (Easy)
 * 描述：使用給定的 digits 陣列中的數字組成不重複的三位數偶數。
 * * 優化重點：
 * 1. 使用位元運算 (num & 1) == 0 判斷偶數，效率極高。
 * 2. 透過條件檢查提前終止不必要的迴圈。
 * 3. 使用 unordered_set 確保結果的唯一性。
 */


class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        std::unordered_set<int> unique_evens;
        int n = static_cast<int>(digits.size());
        
        // 枚舉所有三個數字的排列 (i, j, k)
        for (int i = 0; i < n; ++i) {
            // 三位數首位不能為 0
            if (digits[i] == 0) continue;
            
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;
                    
                    // 偶數判定：最後一位 digits[k] 必須是偶數
                    if ((digits[k] & 1) == 0) {
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                        unique_evens.insert(num);
                    }
                }
            }
        }
        
        return static_cast<int>(unique_evens.size());
    }
};
