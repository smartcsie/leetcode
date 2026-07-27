# Solution_0921

```cpp
/**
 * 題目：921. Minimum Add to Make Parentheses Valid
 * 難度：中等 (Medium)
 * 描述：計算為了使括號有效，最少需要插入的括號數量。
 * * 優化重點：
 * 1. 空間 O(1)：不再使用 vector 模擬堆疊，改用變數計數。
 * 時間複雜度：O(N) - 單次遍歷，計算未配對的括號數。
 * 空間複雜度：O(1) - 僅使用兩個計數變數。

 */

class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0, right = 0;
        for(const char& c : s) {
            if(c == '(') left++;
            else
                if(left > 0) left--;
                else right++;
        }
        return left + right;
    }
};

```
