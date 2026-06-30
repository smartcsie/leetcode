/**
 * 題目：1624. Largest Substring Between Two Equal Characters (兩個相同字元之間的的最長子字串)
 * 難度：簡單 (Easy)
 * 描述：找出字串中兩個相同字元之間的最長子字串長度，若無則返回 -1。
 * * 時間複雜度：O(N)，N 為字串長度，僅需遍歷一次。
 * 空間複雜度：O(1)，僅使用長度為 26 的整數陣列。
 * * 優化思路：
 * 1. 使用 `vector` 記錄第一次出現的索引，查詢效率 O(1)。
 * 2. 僅在發現相同字元時進行長度計算，避免重複操作。
 */

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res = -1;
        vector<int> lastSeen(26, -1);
        for(int i = 0 ; i < s.size(); i++) {
            const int c = s[i] - 'a';
            if(lastSeen[c] == -1) {
                lastSeen[c] = i;
            } else {
                res = max(res, i - lastSeen[c] - 1);
            }
        }
        return res;
    }
};
