/**
 * 題目：415. Add Strings (字串相加)
 * 難度：簡單 (Easy)
 * 描述：給定兩個非負整數的字串形式 num1 和 num2，計算它們的和並以字串形式回傳。
 * * 時間複雜度：O(max(N, M)) - N 和 M 為兩個字串的長度，遍歷一次即可。
 * 空間複雜度：O(max(N, M)) - 用於儲存結果字串。
 * * 解法思路：
 * 1. 使用雙指標 i 和 j 分別從兩個字串的末尾（個位數）開始遍歷。
 * 2. 使用一個變數 carry 記錄進位。
 * 3. 每次迴圈取出對應位數的數字（透過 - '0' 轉為整數），相加後將個位數存入 res。
 * 4. 使用 res.push_back() 將結果放入陣列末尾（效能為 O(1)）。
 * 5. 最後執行 reverse(res.begin(), res.end()) 將字串順序翻轉為正確的結果。
 */

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        
        // 只要任一字串尚未遍歷完，或還有進位，則繼續計算
        while (i >= 0 || j >= 0 || carry != 0) {
            // 若指標小於 0 則補 0，否則取當前字元轉為數字
            int a = (i >= 0) ? num1[i--] - '0' : 0;
            int b = (j >= 0) ? num2[j--] - '0' : 0;
            
            int sum = a + b + carry;
            
            // 將 sum 的個位數轉回字元加入結果字串
            res.push_back((sum % 10) + '0');
            
            // 更新進位
            carry = sum / 10;
        }
        
        // 將結果反轉回正確順序
        reverse(res.begin(), res.end());
        
        return res;
    }
};
