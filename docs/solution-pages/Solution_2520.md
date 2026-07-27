# Solution_2520

```cpp
/**
 * 題目：2520. Count the Digits That Divide a Number
 * 難度：簡單 (Easy)
 * 描述：計算數字 num 的數位中，能夠整除 num 的位數個數。
 * 優化重點：
 * 1. 數位提取：使用 temp % 10 依序取得每一位。
 * 2. 整除判斷：確保提取出的數位不為 0（題目通常保證輸入大於 0 或無 0 位數，若包含 0 需額外判斷）。
 *
 * 時間複雜度：O(log N) - digit decomposition 檢查每個位元是否整除 n。
 * 空間複雜度：O(1) - 僅使用常數空間。
 */

class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        int temp = num;
        
        while (temp > 0) {
            int digit = temp % 10;
            // 題目保證數位不為 0，直接判斷是否整除
            if (num % digit == 0) {
                count++;
            }
            temp /= 10;
        }
        
        return count;
    }
};

```
