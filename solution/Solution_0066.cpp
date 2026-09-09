/**
 * 題目：66. Plus One (加一)
 * 難度：簡單 (Easy)
 * 描述：給定一個以整數陣列表示的非負整數，對其加一並回傳結果陣列。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （模擬進位）：
 * 從最低位開始加 1，若有進位則繼續往前傳遞，若最高位仍有進位則在最前面插入 1。
 **/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(i == digits.size() - 1) carry += 1;
            carry += digits[i];
            digits[i] = carry % 10;
            carry /= 10;
            if(carry == 0) break;
        }
        if(carry == 1) digits.insert(digits.begin(), 1);
        return digits;
    }
};