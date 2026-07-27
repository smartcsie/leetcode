/**
 * 題目：557. Reverse Words in a String III (反轉字串中的單字 III)
 * 難度：簡單 (Easy)
 * 描述：給定一個字串，反轉每個單字中的字元順序，但保持單字順序不變，並保留空格。
 * 
 * 時間複雜度：O(n) - 每個字元最多被遍歷兩次。
 * 空間複雜度：O(1) - 直接在原字串進行操作。
 * 
 * 解法思路：
 * 1. 使用 `end` 指標掃描整個字串，尋找空格以定位單字末端。
 * 2. 一旦找到空格（或字串結尾），使用 `start` 到 `end - 1` 的範圍進行原地交換 (swap)。
 * 3. 更新 `start` 到下一個單字的開頭（跳過空格）。
 */

class Solution {
public:
    string reverseWords(string s) {
        int start = 0, n = s.size();
        
        for (int end = 0; end <= n; end++) {
            // 當遇到空格或到達字串末尾時，進行翻轉
            if (end == n || s[end] == ' ') {
                // 原地翻轉從 start 到 end - 1 的範圍
                int i = start, j = end - 1;
                while (i < j) {
                    swap(s[i++], s[j--]);
                }
                // 更新下一個單字的開始位置
                start = end + 1;
            }
        }
        
        return s;
    }
};
