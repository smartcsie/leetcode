/**
 * 題目：139. Word Break (單字拆分)
 * 難度：中等 (Medium)
 * 描述：判斷字串 s 是否能由 wordDict 中的單字拼接而成。
 * * 時間複雜度：O(N^2 * K) - N 為字串長度，K 為單字平均長度。
 * 空間複雜度：O(N) - 使用布林 DP 陣列。
 * * 優化思路：
 * 1. 狀態定義：dp[i] 表示字串 s[0...i-1] 是否能被切分。
 * 2. 遍歷優化：先遍歷 dp 索引，再遍歷字典中的單字，避免頻繁呼叫 substr。
 */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true; // 空字串視為可切分

        // 遍歷所有可能的終點
        for (int i = 1; i <= s.size(); ++i) {
            // 遍歷所有可能的起點
            for (int j = 0; j < i; ++j) {
                // 如果前一段可拆分，且後一段在字典中
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; // 找到一條路徑即可，無需再檢查其他 j
                }
            }
        }
        return dp[s.size()];
    }
};
