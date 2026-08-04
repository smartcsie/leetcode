/**
 * 題目：504. Base 7 (七進位轉換)
 * 難度：簡單 (Easy)
 * 描述：將整數轉換為七進位字串。
 *
 * 時間複雜度：O(log7(N)) - 每次除以 7，位數隨指數遞減。
 * 空間複雜度：O(log7(N)) - 用於儲存結果字串。
 *
 * 解法思路：
 * 1. 處理負數：先記錄正負號，將 num 轉為正數進行轉換。
 * 2. 進位轉換：利用 num % 7 取得餘數，num /= 7 進入下一位。
 * 3. 輸出：反轉字串後加上正負號。
 */

class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        string ans;
        int neg = (num < 0) ? 1 : 0;
        while(num != 0) {
            char c = neg ? -(num % 7) + '0' : (num % 7) + '0';
            ans.push_back(c);
            num /= 7;
        }
        if(neg) ans.push_back('-');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
