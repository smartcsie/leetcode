/**
 * 題目：13. Roman to Integer (羅馬數字轉整數)
 * 難度：簡單 (Easy)
 * 描述：將羅馬數字轉換為整數。
 * * 時間複雜度：O(N) - 遍歷字串一次。
 * 空間複雜度：O(1) - 使用固定大小陣列作為查找表。
 * * 優化思路：
 * 1. 使用陣列取代 unordered_map：直接將 char 對應到 int，避免雜湊函式開銷。
 * 2. 減少記憶體配置：靜態陣列存於 stack，比動態分配的 map 更快。
 */

class Solution {
public:
    int romanToInt(string s) {
        // 使用陣列做為映射表，空間固定且速度極快
        int val[128] = {0};
        val['I'] = 1; val['V'] = 5; val['X'] = 10;
        val['L'] = 50; val['C'] = 100; val['D'] = 500; val['M'] = 1000;
        
        int ans = 0;
        int n = s.size();
        
        // 遍歷字串，比較當前值與下一個值的大小
        for (int i = 0; i < n; ++i) {
            int current = val[s[i]];
            // 處理減法規則：例如 IV (4), IX (9)
            if (i + 1 < n && current < val[s[i + 1]]) {
                ans -= current;
            } else {
                ans += current;
            }
        }
        return ans;
    }
};
