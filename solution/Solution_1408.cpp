/**
 * 題目：1408. String Matching in an Array (陣列中的字串匹配)
 * 難度：簡單 (Easy)
 * 描述：在陣列中找出所有是其他字串子字串的字串。
 * * 時間複雜度：O(N^2 * K) - N 為字串個數，K 為字串平均長度。
 * 空間複雜度：O(1) (不計結果陣列) 或 O(N) 取決於字串儲存方式。
 * * 優化思路：
 * 1. 排序：透過長度排序，只需檢查當前字串是否為「後方較長字串」的子字串。
 * 2. 提前中斷：找到匹配即 break，自動避免加入重複結果。
 */

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        // 1. 依照長度由短至長排序
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        
        vector<string> res;
        const int n = static_cast<int>(words.size());
        
        // 2. 遍歷檢查
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // 如果 words[i] 是 words[j] 的子字串
                if (words[j].find(words[i]) != string::npos) {
                    res.push_back(words[i]);
                    // 一旦找到匹配，該字串已符合條件，跳出內層迴圈
                    break;
                }
            }
        }
        
        return res;
    }
};
