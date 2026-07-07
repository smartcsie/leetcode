/**
 * 題目：2283. Check if Number Has Equal Digit Count and Digit Value
 * 難度：簡單 (Easy)
 * 描述：驗證每個索引 i 的數值是否等於數字 i 在字串中出現的次數。
 * * 優化重點：
 * 1. 頻率統計：使用長度為 10 的固定大小陣列（因為位元範圍為 0-9），避免動態記憶體配置。
 * 2. 雙向對應：同時維護「期望值」與「實際值」，最後透過陣列相等性檢查快速驗證。
 */

class Solution {
public:
    bool digitCount(std::string num) {
        int n = num.size();
        std::vector<int> occur(10, 0); // 期望出現次數
        std::vector<int> appear(10, 0); // 實際出現次數
        
        for (int i = 0; i < n; i++) {
            int x = num[i] - '0'; // 轉為整數
            occur[i] = x;         // 記錄索引 i 對應的數值
            appear[x]++;          // 統計數字 x 出現的頻率
        }
        
        // 比較兩個統計表是否一致
        return occur == appear;
    }
};
