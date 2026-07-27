/**
 * 題目：2255. Count Prefixes of a Given String
 * 難度：簡單 (Easy)
 * 描述：計算 words 陣列中有多少單詞是字串 s 的前綴。
 * * 時間複雜度：O(N * M) - N 為單詞個數，M 為單詞平均長度。
 * 空間複雜度：O(1) - 僅使用額外空間計數。
 * * 解法思路：
 * 1. 遍歷 words 中的每一個單詞。
 * 2. 使用 `string::find` 檢查該單詞是否在 s 的索引 0 處出現。
 * 3. 若 `find` 回傳 0，則表示該單詞是 s 的前綴。
 */

class Solution {
public:
    int countPrefixes(std::vector<std::string>& words, std::string s) {
        int count = 0;
        for (const std::string& word : words) {
            if (s.find(word) == 0) {
                count++;
            }
        }
        return count;
    }
};
