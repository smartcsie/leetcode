/**
 * 題目：504. Base 7 (七進位轉換)
 * 難度：簡單 (Easy)
 * 描述：將整數轉換為七進位字串。
 *
 * 時間複雜度：O(log7(N)
 * 空間複雜度：O(log7(N)
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
        int x = num;
        string ans;
        if(x < 0) x = -x;
        while(x > 0) {
            ans.push_back((x % 7) + '0');
            x /= 7;
        }
        if(num < 0) ans.push_back('-');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
