/**
 * 題目：44. Wildcard Matching
 * 難度：困難 (Hard)
 * 描述：實作支援 '?' 和 '*' 的萬用字元比對。'?' 比對任一單一字元，
 * '*' 比對任意字元序列（包含空字串），比對必須是完整字串 s 對整個
 * pattern p。
 *
 * 時間複雜度：O(M*N)
 * 空間複雜度：O(M*N)
 *
 * 解法思路：
 * （二維 DP，dp[i][j] 代表 s 的前 i 個字元是否能被 p 的前 j 個字元比對）：
 * 1. dp[0][0] = true：空字串對空 pattern 一定比對成功。
 * 2. 第一列初始化（i = 0，s 是空字串）：只有當 p[j] 是 '*' 時，
 *    dp[0][j+1] 才可能是 true，而且要看 dp[0][j] 是否也成立（'*' 可以
 *    吃掉零個字元，讓前面的比對結果延續下來）。
 * 3. 狀態轉移，看 p[j]（目前 pattern 比對到的字元）：
 *    - 如果 p[j] 是 '*'：有兩種情況可以讓 dp[i+1][j+1] 成立——
 *      (a) matchEmpty：'*' 吃零個字元，直接看 dp[i+1][j]（s 不消耗，
 *          只跳過這個 '*'）。
 *      (b) matchSome：'*' 至少吃一個字元（s[i] 這個字元），
 *          看 dp[i][j+1]（s 消耗一個字元，'*' 繼續留在原地，可以
 *          再吃下一個）。
 *      兩者只要有一個成立就行。
 *    - 如果 p[j] 不是 '*'：一般字元比對，s[i] 要能對到 p[j]
 *      （相等或 p[j] 是 '?'），而且前面 dp[i][j] 也要成立，才能推出
 *      dp[i+1][j+1] = true。
 * 4. 答案是 dp[m][n]，代表整個 s 是否能被整個 p 比對成功。
 * 5. 跟 Regex Matching(10) 的差異：這題 '*' 直接代表「任意字元序列」，
 *    轉移只需要考慮「吃 0 個」跟「吃 1 個（然後留在原地繼續吃）」兩種
 *    情況；Regex 的 '*' 是「前一個字元重複任意次」，多了一層要跟
 *    「前一個字元是否匹配」綁在一起判斷的邏輯，兩題形狀相似但轉移細節
 *    不同，所以還是同一個 dp-string 分類，但不是完全一樣的模板可以套。
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.length();
        const int n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = true;
        auto isMatch = [&](int i, int j) -> bool {
            return j >= 0 && p[j] == '?' || s[i] == p[j];
        };
        for (int j = 0; j < p.length(); ++j)
        if (p[j] == '*')
            dp[0][j + 1] = dp[0][j];
        for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        if (p[j] == '*') {
            const bool matchEmpty = dp[i + 1][j];
            const bool matchSome = dp[i][j + 1];
            dp[i + 1][j + 1] = matchEmpty || matchSome;
        } else if (isMatch(i, j)) {
            dp[i + 1][j + 1] = dp[i][j];
        }
        return dp[m][n];
    }
};
