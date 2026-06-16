/**
 * 題目：2443. Sum of Number and Its Reverse (數字與其反轉的和)
 * 難度：中等 (Medium)
 * 描述：判斷是否存在非負整數 x，使得 x 加上其反轉數字等於 num。
 * * 時間複雜度：O(N log N) - 遍歷 0 到 num，每次反轉消耗 log10(x) 時間。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 1. 模組化：獨立出 reverseInteger 函數，提高程式碼整潔度。
 * 2. 邊界處理：num 為 0 時，0 + 0 = 0，為特殊情況。
 */

class Solution {
private:
    int reverse(int n) {
        int rev = 0;
        while(n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }
public:
    bool sumOfNumberAndReverse(int num) {
        for(int x = num / 2; x <= num; x++) {
            if(x + reverse(x) == num) return true;
        }
        return false;
    }
};
