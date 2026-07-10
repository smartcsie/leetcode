/**
 * 題目：1881. Maximum Value after Insertion
 * 難度：中等 (Medium)
 * 描述：在字串形式的數字中插入一個數值 x，使最終結果最大。
 * * 優化重點：
 * 1. 貪婪搜索：單次遍歷即可找到最佳插入位置，O(N)。
 * 2. 條件分流：針對正負號分別採用不同的貪婪條件。
 */

class Solution {
public:
    std::string maxValue(std::string n, int x) {
        int i = 0;
        char c = x + '0';
        
        // 負數處理：尋找第一個大於 x 的位數並插入
        if (n[0] == '-') {
            i = 1; // 跳過負號
            while (i < n.size() && c >= n[i]) {
                i++;
            }
        } 
        // 正數處理：尋找第一個小於 x 的位數並插入
        else {
            while (i < n.size() && c <= n[i]) {
                i++;
            }
        }
        
        n.insert(i, 1, c);
        return n;
    }
};
