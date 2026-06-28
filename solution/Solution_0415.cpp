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
        while(i >= 0 || j >= 0 || carry !=0) {
            if(i >=0) carry += num1[i--] - '0';
            if(j >=0) carry += num2[j--] - '0';
            res.push_back((carry % 10) + '0');
            carry /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


