/**
 * 題目：1945. Sum of Digits of String After Convert
 * 描述：將字串轉為字母序數字 (a=1, b=2...)，並進行 k 次「數字位數和」轉換。
 * 
 * 解法思路：
 * 1. 轉換階段：將每個字元轉為對應數字 (1-26)，並直接將這些數字的「位數相加」計入初始總和。
 * 2. 迭代階段：根據題目要求執行 k-1 次位數總和轉換 (digitSum)。
 */

class Solution {
private:
    // 計算初步轉換的數字和
    int charSum(const std::string& s) {
        int sum = 0;
        for (const char& c : s) {
            int num = c - 'a' + 1;
            // 直接計算該數的個位與十位之和 (因為 num 最大為 26，sum 最多為 2+6=8)
            sum += (num >= 10) ? (num / 10) + (num % 10) : num;
        }
        return sum;
    }

    // 計算整數的位數之和
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int getLucky(std::string s, int k) {
        // 先進行第一次轉換
        int sum = charSum(s);
        
        // 若 k > 1，則繼續進行後續轉換
        for (int i = 1; i < k; i++) {
            sum = digitSum(sum);
        }
        return sum;
    }
};
