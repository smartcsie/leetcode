/**
 * 題目：2609. Find the Longest Balanced Substring
 * 難度：簡單 (Easy)
 * 描述：找到最長連續的平衡子字串 (所有 0 在 1 前面，且數量相等)。
 * 
 * 解法思路：
 * 1. 使用 `zeros` 和 `ones` 兩個計數器，分別記錄當前連續段中 0 與 1 的數量。
 * 2. 遍歷字串：
 *    - 當遇到 '0'：若前一個字元是 '1'，表示進入了下一個區塊，需重置計數器。
 *    - 當遇到 '1'：增加 `ones` 並更新最大長度 `2 * min(zeros, ones)`。
 * 3. 此邏輯確保了我們只計算「連續的」0 後接 1 的結構。
 */

class Solution {
public:
    int findTheLongestBalancedSubstring(std::string s) {
        int ones = 0, zeros = 0;
        int ans = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                // 若從 '1' 切換回 '0'，代表區塊重置
                if (i > 0 && s[i - 1] == '1') {
                    zeros = 0;
                    ones = 0;
                }
                zeros++;
            } else {
                // 遇到 '1' 時累加並計算當前平衡長度
                ones++;
                ans = std::max(ans, 2 * std::min(zeros, ones));
            }
        }   
        return ans;
    }
};
