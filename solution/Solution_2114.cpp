/**
 * 題目：2114. Maximum Number of Words Found in Sentences (句子中的最多單詞數)
 * 難度：簡單 (Easy)
 * 描述：計算多個句子中包含單詞數量的最大值。
 * * 時間複雜度：O(N * M) - N 為句子總數，M 為句子的平均長度。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 根據題目，單詞間由單個空格分隔。因此，單詞數 = 空格數 + 1。
 * 直接遍歷字串統計空格，避免使用 `stringstream` 造成的記憶體配置與格式化開銷。
 */

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxCount = -1;
        for(const string& sentence : sentences) {
            int wordCount = 1;
            for(const char& c : sentence) {
                if(c == ' ') wordCount++;
            }
            maxCount = max(maxCount, wordCount);
        }
        return maxCount;
    }
};
