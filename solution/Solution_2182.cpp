/**
 * 題目：2182. Construct String With Repeat Limit
 * 描述：給你一個字串 s 和一個整數 repeatLimit。構造一個新字串，
 *       使任何字元連續出現的次數不超過 repeatLimit，並讓新字串的字典序盡可能大。
 * 
 * 解法思路：
 * 1. 頻率統計：使用大小為 26 的陣列 `counts` 統計字串 s 中每個字母（'a'-'z'）出現的次數。
 * 2. 貪心逆向遍歷（從大到小）：
 *    - 從字典序最大（'z' 對應的 25）開始處理，用 `cur` 代表當前要放入的大字元。
 *    - 使用另一個指針 `next` 來找次大的字元，用來在當前大字元達到 `repeatLimit` 限制時「插花」阻斷連續性。
 * 3. 迴圈建構：
 *    - 每次盡可能放入最多達 `repeatLimit` 個當前字元 `cur`。
 *    - 如果 `cur` 還沒用完，代表遇到瓶頸，此時必須借用一個 `next` 字元（找下一個還有剩的較小字元）放進去打破連續限制。
 *    - 若連 `next` 都找不到了（小於 0），說明無法繼續構造，直接結束。
 */

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // 1. 統計 26 個字母的出現頻率
        std::vector<int> counts(26, 0);
        for (const char& c : s) {
            counts[c - 'a']++;
        }
        std::string ans = "";
        // 2. 從最大字元 (25, 即 'z') 開始往下降到 0 ('a')
        for (int cur = 25, next = 24; cur >= 0; --cur) {
            next = std::min(next, cur - 1);
            while (true) {
                // 計算當前最多可以放幾個連續的 cur 字元
                int chars = std::min(counts[cur], repeatLimit);
                for (int k = 0; k < chars; ++k) {
                    ans += static_cast<char>('a' + cur);
                    --counts[cur];
                }
                // 如果當前字元已經用完，跳出內層 while，處理下一個更小的 cur
                if (counts[cur] == 0) {
                    break;
                }
                // 如果當前字元還沒用完（代表被 repeatLimit 擋住），必須找一個次大的字元來阻斷
                while (next >= 0 && counts[next] == 0) {
                    --next;
                }
                // 如果連次大字元也找光了，說明無法再插入阻斷，構造終止
                if (next < 0) {
                    break;
                }
                // 放入一個次大字元來打破連續限制
                ans += static_cast<char>('a' + next);
                --counts[next];
            }
        }
        return ans;
    }
};
