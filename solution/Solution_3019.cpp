/**
 * 題目：3019. Number of Changing Keys
 * 描述：計算在打字過程中，按鍵變更的次數（忽略大小寫）。
 * 
 * 解法思路：
 * 1. 使用位元運算 `c | 32` 將所有字元統一轉換為小寫 (因為 'A' 是 65, 'a' 是 97，65 | 32 = 97)。
 * 2. 從索引 1 開始遍歷，比較當前字元與前一個字元是否不同。
 * 3. 若不同則計數器加 1。
 */

class Solution {
public:
    int countKeyChanges(std::string s) {
        int changes = 0;
        int n = s.size();
        
        for (int i = 1; i < n; i++) {
            // 利用位元運算 | 32 將字母轉為小寫後進行比較
            if ((s[i] | 32) != (s[i - 1] | 32)) {
                changes++;
            }
        }
        
        return changes;
    }
};
