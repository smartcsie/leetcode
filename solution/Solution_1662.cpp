// 題目：1662. Check If Two String Arrays are Equivalent
// 難度：Easy
// 時間複雜度：O(L)，L = 所有字元總數
// 空間複雜度：O(1)
// 分類主題：string / two-pointers
// 技巧：雙指標（字串索引 + 字元索引）逐字元比較，不用先把陣列串接成一個字串

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        // wIdx：目前在第幾個字串；cIdx：目前在該字串的第幾個字元
        // 兩個陣列各自維護一組指標
        int wIdx1 = 0, wIdx2 = 0, cIdx1 = 0, cIdx2 = 0;
        int n1 = word1.size();
        int n2 = word2.size();

        // 只要兩邊都還有字串可讀就繼續比較
        while(wIdx1 < n1 && wIdx2 < n2) {
            // 目前指到的兩個字元不同，串接後一定不相等
            if(word1[wIdx1][cIdx1] != word2[wIdx2][cIdx2]) return false;

            // 推進 word1 的指標：
            // 如果已經是目前字串的最後一個字元，就換到下一個字串的開頭
            if(cIdx1 == (word1[wIdx1].size() - 1)) {
                wIdx1++;
                cIdx1 = 0;
            } else {
                cIdx1++;       // 否則只往同一字串的下一個字元
            }

            // 推進 word2 的指標，邏輯同上
            if(cIdx2 == (word2[wIdx2].size() - 1)) {
                wIdx2++;
                cIdx2 = 0;
            } else {
                cIdx2++;
            }
        }

        // 迴圈結束時，兩邊都剛好讀完才算相等：
        // 如果只有一邊讀完，代表另一邊還有剩餘字元，串接後長度不同
        return wIdx1 == n1 && wIdx2 == n2;
    }
};