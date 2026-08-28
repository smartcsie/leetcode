/**
 * 題目：3014. Minimum Number of Pushes to Type Word I (輸入字串所需的最少按鍵次數 I)
 * 難度：中等 (Medium)
 * 描述：使用類似手機九宮格鍵盤，每個按鍵可以對應多個字母（最多 8 個字母共用同一個按鍵，
 *       按第 k 次循環切換到該按鍵上的第 k 個字母）。給定字串 word，
 *       可以自由把 26 個字母分配到有限的按鍵上，求輸入整個 word 所需的最少總按鍵次數。
 *
 * 時間複雜度：O(N+26log26)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 貪婪分配策略 (Greedy Assignment)：
 *    - 出現頻率越高的字母，應該被分配到「按鍵次數越少」的位置（例如每個按鍵的第 1 個字母只需按 1 次）。
 * 2. 統計字母出現頻率並降冪排序：
 *    - 先統計 word 中每個字母出現的次數，再將次數由大到小排序，
 *      確保出現次數最多的字母，優先取得成本最低的按鍵位置。
 * 3. 依序分配按鍵成本：
 *    - 每個按鍵最多容納 8 個字母（一輪最多 8 個按鍵可用），
 *      排序後第 i 個字母（0-indexed）所需的按鍵次數為 (i / 8 + 1)。
 * 4. 累加總成本：
 *    - 將每個字母的出現次數乘上其對應的按鍵次數並加總，即為最終答案。
 */
class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        vector<int> count(26);

        for (const char c : word)
        ++count[c - 'a'];

        ranges::sort(count, greater<>());

        for (int i = 0; i < 26; ++i)
        ans += count[i] * (i / 8 + 1);

        return ans;
    }
};
