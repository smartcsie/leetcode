/**
 * 題目：943. Find the Shortest Superstring
 * 難度：困難 (Hard)
 * 描述：給定一組字串 words，找出一個最短的字串，讓 words 裡每個字串都
 * 是它的子字串（子字串可以重疊）。如果有多個最短解，回傳任一個即可。
 *
 * 時間複雜度：O(N² * L + N² * 2^N)
 * 空間複雜度：O(N * 2^N)
 *
 * 解法思路：
 * （Bitmask DP，這題是「旅行推銷員問題（TSP）」的變形：把每個字串當
 * 一個「城市」，兩個字串之間的「距離」用重疊長度的負值表示，目標是
 * 找一條經過所有城市、總距離最短（也就是總重疊最大）的路徑）：
 * 1. 先預處理 overlap[i][j]：字串 i 的結尾跟字串 j 的開頭最多能重疊
 *    幾個字元（例如 "catg" 結尾跟 "gcta" 開頭重疊 1 個字元 "g"）。
 * 2. dp[mask][last] 代表「用了 mask 這些字串、且最後一個接上去的是
 *    字串 last」時，能拿到的最大總重疊長度。
 * 3. base case：dp[只有第i個bit][i] = 0（只用一個字串，還沒有跟誰
 *    重疊過）。
 * 4. 狀態轉移：從 dp[mask][last] 出發，接上一個還沒用過的字串 next，
 *    重疊量增加 overlap[last][next]，更新 dp[mask | (1<<next)][next]。
 * 5. **這題最容易出錯的地方**：dp 陣列的「無效狀態」要用一個明確小於
 *    任何合法值的哨兵（例如 INT_MIN/2），不能用 0 當哨兵！因為 0 本身
 *    也是一個合法的重疊值（兩個字串之間可能真的沒有重疊），如果用 0
 *    當「未計算」的哨兵，會導致「合法的 0 重疊」被誤判成「還沒算過」，
 *    用嚴格 `>` 比較時又會漏掉「新值等於 0、但這個狀態原本是不可達」
 *    的情況，讓 parent 陣列斷鏈、還原不出正確的拼接順序。
 * 6. 找出 dp[全部用完][last] 裡最大值對應的 last，用 parent 陣列回溯
 *    出完整的字串使用順序，再依序拼接（第一個字串完整放入，之後每個
 *    字串只接上「扣掉重疊部分」的後半段）。
 */
class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> overlap(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int maxLen = min(words[i].size(), words[j].size());
                for (int k = maxLen; k > 0; --k) {
                    if (words[i].substr(words[i].size() - k) == words[j].substr(0, k)) {
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }

        const int NEG = INT_MIN / 2;
        vector<vector<int>> dp(1 << n, vector<int>(n, NEG));
        vector<vector<int>> parent(1 << n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i) dp[1 << i][i] = 0;

        for (int mask = 1; mask < (1 << n); ++mask) {
            for (int last = 0; last < n; ++last) {
                if (!(mask & (1 << last))) continue;
                if (dp[mask][last] == NEG) continue;
                int remaining = ((1 << n) - 1) ^ mask;
                for (int next = 0; next < n; ++next) {
                    if (!(remaining & (1 << next))) continue;
                    int newMask = mask | (1 << next);
                    int val = dp[mask][last] + overlap[last][next];
                    if (val > dp[newMask][next]) {
                        dp[newMask][next] = val;
                        parent[newMask][next] = last;
                    }
                }
            }
        }

        int fullMask = (1 << n) - 1;
        int best = -1, bestLast = 0;
        for (int last = 0; last < n; ++last) {
            if (dp[fullMask][last] > best) {
                best = dp[fullMask][last];
                bestLast = last;
            }
        }

        vector<int> order;
        int mask = fullMask, last = bestLast;
        while (last != -1) {
            order.push_back(last);
            int p = parent[mask][last];
            mask ^= (1 << last);
            last = p;
        }
        reverse(order.begin(), order.end());

        string result = words[order[0]];
        for (int i = 1; i < (int)order.size(); ++i) {
            int ov = overlap[order[i - 1]][order[i]];
            result += words[order[i]].substr(ov);
        }
        return result;
    }
};
