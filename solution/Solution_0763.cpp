/**
 * 題目：763. Partition Labels
 * 難度：中等 (Medium)
 * 分類主題：greedy-prefix-suffix
 * 描述：給定一個字串 s，把它切割成盡量多的片段，讓每個字母只出現在
 * 一個片段裡（同一個字母不能跨越兩個片段），回傳每個片段的長度。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)（26 個字母的計數）
 *
 * 解法思路：
 * （Prefix/Suffix Greedy，先用「後綴資訊」（每個字母最後出現的位置）
 * 預處理，再用貪心一次掃描決定切割點）：
 * 1. 先掃一遍字串，記錄每個字母「最後出現的索引」（lastIndex）。
 * 2. 再掃第二遍，維護目前片段的 [start, end] 範圍：對每個字元，把
 *    end 更新成 max(end, 這個字元最後出現的位置)——代表「這個片段
 *    至少要延伸到這裡，才能把這個字元完整包住」。
 * 3. **切割時機**：當掃描位置 i 剛好等於 end（代表目前片段內，所有
 *    看過的字元的「最後出現位置」都已經被涵蓋了，沒有任何字元會
 *    跑出這個片段），這裡就是一個合法的切割點，記錄片段長度
 *    （end - start + 1），並把 start 移到下一個位置。
 * 4. 這個貪心的正確性：只要 end 還沒追上 i，代表片段內還有字元的
 *    「最後出現位置」在更後面，這個片段還不能結束；一旦追上了，就是
 *    能切的最早時機（切越早，片段數越多，越符合題目要求）。
 */
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(26, 0);
        for (int i = 0; i < (int)s.size(); ++i) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<int> result;
        int start = 0, end = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            end = max(end, lastIndex[s[i] - 'a']);
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};
