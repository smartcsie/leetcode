/**
 * 題目：67. Add Binary (二進位求和)
 * 難度：簡單 (Easy)
 * 描述：給定兩個二進位字串，返回它們的和（二進位）。
 * * 時間複雜度：O(max(M, N)) - M, N 為兩個字串長度。
 * 空間複雜度：O(1) - 僅存儲結果。
 * * 優化思路：
 * 1. 使用 `res.push_back()` 取代 `res += to_string()`，避免不必要的記憶體分配。
 * 2. 直接轉換字元 `'0'` 或 `'1'`，避免昂貴的整數轉字串運算。
 */

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        while(i >= 0 || j >= 0 || carry == 1) {
            if(i >= 0) carry += a[i--] - '0';
            if(j >= 0) carry += b[j--] - '0';
            res.push_back((carry % 2)+'0');
            carry /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
