/**
 * 題目：3121. Count the Number of Special Characters II
 * 難度：中等 (Medium)
 * 描述：計算滿足以下條件的字母個數：小寫字母至少出現一次，且所有小寫出現位置皆在所有大寫之前。
 * 優化重點：
 * 1. 紀錄狀態：使用一個大小為 26 的 pair 陣列，儲存 `{大寫第一次出現索引, 小寫最後一次出現索引}`。
 * 2. 條件判斷：
 * - 大寫必須存在 (first != -1)
 * - 小寫必須存在 (second != -1)
 * - 必須滿足：最後一個小寫位置 < 第一個大寫位置。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    int numberOfSpecialChars(std::string word) {
        /vector<int> lowers(26, -1);
        vector<int> uppers(26, -1);
        int n = word.size();
        int ans = 0;
        for(int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
            if(islower(word[i])) lowers[word[i] - 'a']= i;
            if(isupper(word[j])) uppers[word[j] - 'A']= j;
        }
        for(int i = 0; i < 26; i++) {
            if(lowers[i] > -1 && uppers[i] > -1 && (lowers[i] < uppers[i])) ans++;
        }
        return ans;
    }
};
