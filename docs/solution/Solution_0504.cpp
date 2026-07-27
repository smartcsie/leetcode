/**
 * 題目：504. Base 7 (七進位轉換)
 * 難度：簡單 (Easy)
 * 描述：將整數轉換為七進位字串。
 * * 時間複雜度：O(log7(N)) - 每次除以 7，位數隨指數遞減。
 * 空間複雜度：O(log7(N)) - 用於儲存結果字串。
 * * 優化思路：
 * 1. 處理負數：先記錄正負號，將 num 轉為正數進行轉換。
 * 2. 進位轉換：利用 num % 7 取得餘數，num /= 7 進入下一位。
 * 3. 輸出：反轉字串後加上正負號。
 */

class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        string res = "";
        bool neg = (num < 0);
        int n = num;
        while(n != 0) {
            int reminder = (n % 7) < 0 ? -(n % 7) : (n % 7);
            res.push_back(reminder + '0');
            n /= 7;
        }
        if(neg) res.push_back('-');
        reverse(res.begin(), res.end());
        return res;
    }
};
