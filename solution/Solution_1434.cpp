/**
 * 題目：1434. Number of Ways to Wear Different Hats to Each Other
 * 難度：困難 (Hard)
 * 描述：給定每個人可以選擇的帽子清單 hats，求有幾種方式，讓每個人都戴
 * 一頂自己清單裡的帽子、且沒有兩個人戴同一頂帽子（結果對 10^9+7 取模）。
 *
 * 時間複雜度：O(40 * 2^N * 平均每頂帽子對應的人數)
 * 空間複雜度：O(40 * 2^N)
 *
 * 解法思路：
 * （Bitmask DP，這題的技巧是「反過來想」：不是對每個人枚舉戴哪頂帽子，
 * 而是對每頂帽子（1~40）依序決定要不要分配給某個人，這樣才能保證
 * 「同一頂帽子只分給一個人」這個限制自然被滿足）：
 * 1. 人數最多 10 人（適合當 bitmask），帽子最多 40 種，所以反過來
 *    「以帽子為主軸」逐一決定：mask 記錄「哪些人已經戴上帽子了」。
 * 2. dp[i][mask] 代表「只考慮 1~i 號帽子，且目前已戴帽子的人是 mask」
 *    時，總共有幾種分配方式。
 * 3. 狀態轉移，對第 i 頂帽子有兩種選擇：
 *    - 這頂帽子不分給任何人：dp[i][mask] += dp[i-1][mask]。
 *    - 這頂帽子分給某個「還沒戴帽子、且清單裡有這頂帽子」的人 p：
 *      dp[i][mask | (1<<p)] += dp[i-1][mask]。
 * 4. 先預處理 peopleForHat[h]，代表哪些人的清單裡有帽子 h，避免每次
 *    都要重新掃描所有人。
 * 5. 答案是 dp[40][所有人都戴上帽子的mask]，代表把 40 頂帽子都考慮
 *    完之後，剛好每個人都恰好戴上一頂帽子的方案數。
 */
class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        const int MOD = 1e9 + 7;
        int n = hats.size();
        vector<vector<int>> peopleForHat(41);
        for (int i = 0; i < n; ++i) {
            for (int h : hats[i]) peopleForHat[h].push_back(i);
        }

        int full = (1 << n) - 1;
        vector<vector<int>> dp(41, vector<int>(1 << n, -1));
        dp[0][0] = 1;
        for (int i = 1; i <= 40; ++i) {
            for (int mask = 0; mask <= full; ++mask) {
                if (dp[i - 1][mask] == -1) continue;
                long long base = dp[i - 1][mask];
                dp[i][mask] = (int)((dp[i][mask] == -1 ? 0 : dp[i][mask]) + base) % MOD;
                for (int p : peopleForHat[i]) {
                    if (mask & (1 << p)) continue;
                    int newMask = mask | (1 << p);
                    long long cur = dp[i][newMask] == -1 ? 0 : dp[i][newMask];
                    dp[i][newMask] = (int)((cur + base) % MOD);
                }
            }
        }
        return dp[40][full] == -1 ? 0 : dp[40][full];
    }
};
