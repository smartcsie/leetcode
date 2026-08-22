/**
 * 題目：2266. Count Number of Texts
 * 難度：中等 (Medium)
 * 描述：手機九宮格輸入法裡，一個數字鍵對應多個字母（例如 '2' 對應
 * 'a','b','c'），打字時連續按同一個鍵 n 次，代表選這個鍵對應的第 n
 * 個字母。給定按鍵記錄 pressedKeys，求可能對應到幾種不同的原始文字
 * 訊息（結果對 10^9+7 取模）。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(最長連續按鍵長度)
 *
 * 解法思路：
 * （雖然題目分類在 Backtracking，但實際上是一個換皮版的 Linear DP，
 * 跟 91. Decode Ways 是同一個核心邏輯，只是「每組合法長度」從固定
 * 的 1~2 變成依按鍵種類而定的 1~3 或 1~4）：
 * 1. 先把 pressedKeys 按照「連續相同字元」分組（例如 "22233" 分成
 *    "222" 和 "33" 兩組），因為不同組之間的按鍵完全獨立，各自的切分
 *    方式數可以直接相乘（乘法原理）。
 * 2. 對每一組長度為 len 的連續按鍵，這個鍵最多對應幾個字母
 *    （大部分鍵是 3 個字母，'7' 和 '9' 是 4 個字母）決定了「一次最多
 *    可以連續按幾下代表同一個字母」，這個上限記為 limit。
 * 3. 這一組長度為 len 的按鍵，有幾種切分方式：dp[x] 代表「長度為 x
 *    的連續按鍵」有幾種切法，dp[0] = 1（空的，一種切法），
 *    dp[x] = dp[x-1] + dp[x-2] + ... + dp[x-limit]（枚舉最後一個字母
 *    用掉了幾次按鍵，1 到 limit 次），這跟 91 題「每次可以吃 1 位數字
 *    或 2 位數字」的遞迴形狀完全一樣，只是這裡是「1 到 limit 位」。
 * 4. 把每一組的 dp[len] 結果連乘起來（乘法原理，取模），就是最終答案。
 */
class Solution {
public:
    int countTexts(string pressedKeys) {
        const int MOD = 1e9 + 7;
        auto maxGroup = [](char c) -> int {
            return (c == '7' || c == '9') ? 4 : 3;
        };

        int n = pressedKeys.size();
        int i = 0;
        long long ans = 1;
        while (i < n) {
            int j = i;
            while (j < n && pressedKeys[j] == pressedKeys[i]) ++j;
            int len = j - i;
            int limit = maxGroup(pressedKeys[i]);

            vector<long long> dp(len + 1, 0);
            dp[0] = 1;
            for (int x = 1; x <= len; ++x) {
                for (int t = 1; t <= min(limit, x); ++t) {
                    dp[x] = (dp[x] + dp[x - t]) % MOD;
                }
            }
            ans = (ans * dp[len]) % MOD;
            i = j;
        }
        return (int)ans;
    }
};
