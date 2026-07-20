/**
 * 題目：2707. Extra Characters in a String
 * 描述：給定一個字串 s 和一個字典 dictionary，你可以將 s 分割成若干子字串。
 *       若某個子字串不在字典中，它就會被視為「額外字元」。求出最少需要的額外字元數量。
 * 
 * 解法思路：
 * 1. 使用 unordered_set 儲存字典中的所有單字，方便 O(1) 查詢。
 * 2. 定義 dp[i] 代表字串前 i 個字元 (s[0...i-1]) 所需的最少額外字元數。
 * 3. 狀態轉移：
 *    - 初始化 dp 陣列為最大可能值 (例如 n)。
 *    - dp[0] = 0 (空字串不需要額外字元)。
 *    - 對於每一個位置 i，枚舉分割點 j (0 <= j < i)：
 *      - 若子字串 s[j...i-1] 存在於字典中，則額外字元數不變：dp[i] = min(dp[i], dp[j])。
 *      - 若不在字典中，則該子字串全部視為額外字元：dp[i] = min(dp[i], dp[j] + (i - j))。
 */

class Solution {
public:
    int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
        std::unordered_set<std::string> dicSet(dictionary.begin(), dictionary.end());
        const int n = s.size();
        
        // dp[i] 表示前 i 個字元的最少額外字元數，初始值設為 n（最差情況全部都是額外字元）
        std::vector<int> dp(n + 1, n);
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            // 預設情況：如果不與前面組合成字典單字，當前第 i 個字元本身就是一個額外字元
            dp[i] = dp[i - 1] + 1;
            
            for (int j = 0; j < i; j++) {
                // 檢查子字串 s[j ... i-1] 是否在字典中
                if (dicSet.count(s.substr(j, i - j))) {
                    dp[i] = std::min(dp[i], dp[j]);
                } else {
                    dp[i] = std::min(dp[i], dp[j] + (i - j));
                }
            }
        }
        
        return dp[n];
    }
};
