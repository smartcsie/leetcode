// 題目：171. Excel Sheet Column Number
// 難度：Easy
// 時間複雜度：O(n)，n = columnTitle 的長度
// 空間複雜度：O(1)
// 分類主題：math / string
// 技巧：26 進位轉換（A~Z 對應 1~26，沒有 0），類似「字串轉整數」的 sum = sum * base + digit

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        for(const char& c : columnTitle) {
            // 由左到右處理每個字母，等同 26 進位：
            //   sum * 26：把目前累積的值整體進一位（像十進位的 sum * 10）
            //   c - 'A' + 1：這個字母代表的數字，'A' = 1、'B' = 2、... 'Z' = 26
            // 注意是 1~26，不是 0~25，所以要 + 1
            // 例："AB" -> 先 'A'：0 * 26 + 1 = 1；再 'B'：1 * 26 + 2 = 28
            //     "ZY" -> 'Z'：26；'Y'：26 * 26 + 25 = 701
            sum = sum * 26 + (c - 'A' + 1);
        }
        // 題目保證結果落在 int 範圍內（最大為 "FXSHRXW" = 2^31 - 1），不會溢位
        return sum;
    }
};