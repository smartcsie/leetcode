/**
 * 註解：待補充
 */
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