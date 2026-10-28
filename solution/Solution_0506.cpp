/**
 * 題目：506. Relative Ranks
 * 難度：Easy
 * 描述：給定 n 位選手的分數 score（所有分數互不相同），
 *       回傳每位選手的名次：第 1 名為 "Gold Medal"、第 2 名為 "Silver Medal"、
 *       第 3 名為 "Bronze Medal"，第 4 名以後則回傳名次數字的字串。
 *       答案的順序要對應原本 score 的順序。
 *
 * 分類主題：sorting-custom-comparator
 * 技巧：排序 (值, 原索引) 的 pair 以記住原位置, greater<> 由大到小排序, static constexpr string_view 存獎牌名稱
 *
 * 時間複雜度：O(N log N)，主要來自排序
 * 空間複雜度：O(N)
 *
 * 解法思路：排序 + 記住原索引
 * 1. 排序後會打亂原本的位置，所以先把每個分數連同它的原索引一起存成
 *    pair (score[i], i)。
 * 2. 依分數由大到小排序（greater<> 對 pair 先比 first，即分數）。
 *    題目保證分數不重複，所以不需要處理平手。
 * 3. 排序後第 i 個（0 起算）就是第 i + 1 名：
 *    - i < 3：用獎牌名稱
 *    - i >= 3：用 to_string(i + 1) 當名次
 * 4. 名次要寫回「原索引」的位置，即 ans[pairs[i].second]，
 *    這樣輸出順序才會對應原本的 score 順序。
 */
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // 前三名的獎牌名稱；string_view 在編譯期決定，不需要在執行期建立字串
        static constexpr string_view medals[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        int n = score.size();

        // (分數, 原索引)：排序後仍可由 second 找回原本的位置
        vector<pair<int,int>> pairs;
        for (int i = 0; i < n; i++) {
            pairs.push_back({score[i], i});
        }

        // 分數由高到低排序（分數不重複，名次唯一）
        sort(pairs.begin(), pairs.end(), greater<>());

        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            int idx = pairs[i].second;  // 這個名次對應的原索引
            // 前三名用獎牌，其餘用名次數字；三元運算子兩邊型別要一致，所以獎牌要包成 string
            ans[idx] = (i < 3) ? string(medals[i]) : to_string(i + 1);
        }
        return ans;
    }
};
