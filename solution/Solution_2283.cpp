/**
 * 題目：2283. Check if Number Has Equal Digit Count and Digit Value
 * 難度：簡單 (Easy)
 * 描述：驗證每個索引 i 的數值是否等於數字 i 在字串中出現的次數。
 * * 優化重點：
 * 1. 空間精簡：僅使用一個長度為 10 的陣列進行統計。
 * 2. 兩階段處理：先統計後驗證，將空間複雜度從 O(N) 的兩倍降低至常數空間 O(1)。
 */

class Solution {
public:
    bool digitCount(std::string num) {
        int n = num.size();
        std::vector<int> appear(10, 0);
        
        // 第一次遍歷：統計頻率
        for (int i = 0; i < n; i++) {
            appear[num[i] - '0']++;
        }
        
        // 第二次遍歷：對照檢查
        for (int i = 0; i < n; i++) {
            if (appear[i] != (num[i] - '0')) {
                return false;
            }
        }
        
        return true;
    }
};
