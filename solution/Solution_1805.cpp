/**
 * 題目：1805. Number of Different Integers in a String
 * 難度：簡單 (Easy)
 * 描述：計算字串中不同的數字整數個數（前導零視為相同）。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 將所有字母替換為空格，使數字被空格自然分隔。
 * 2. 使用 stringstream 讀取每個數字片段。
 * 3. 處理前導零：使用 `find_first_not_of('0')` 找到第一個非零位，並截取子字串；若全是 '0'，則視為 "0"。
 * 4. 將處理後的字串加入 `unordered_set` 以自動去重。
 */

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> seen;
        int n = word.size();
        int i = 0;
        while (i < n) {
            // 1. 如果不是數字，跳過
            if (!isdigit(word[i])) {
                i++;
                continue;
            }
            // 2. 找到一個數字區段的起點
            int start = i;
            while (i < n && isdigit(word[i])) {
                i++;
            }
            // 3. 處理前導零（保留至少一個 '0'，例如 "000" -> "0"）
            int l = start;
            while (l < i - 1 && word[l] == '0') {
                l++;
            }
            // 4. 放入 set 中
            seen.insert(word.substr(l, i - l));
        }
        return static_cast<int>(seen.size());
    }
};
