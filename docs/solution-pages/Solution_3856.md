# Solution_3856

```cpp
/**
 * 題目：Trim Trailing Vowels
 * 難度：簡單 (Easy)
 * 描述：移除字串末尾所有的母音（a, e, i, o, u，包含大小寫）。
 * * 優化重點：
 * 1. O(N) 時間：僅需遍歷末端母音部分。
 * 2. 位元運算：利用 2130466 進行母音識別。
 * 時間複雜度：O(N) - 從尾端移除母音，pop_back 直到尾端為子音。
 * 空間複雜度：O(1) - 僅使用常數空間。

 */

class Solution {
private:
    // 利用位元遮罩快速檢查字元是否為母音
    // 數字 2130466 在二進位中，對應 a, e, i, o, u 的位置皆為 1
    static bool isVowel(char c) {
        return (2130466 >> (c - 'a' + 1)) & 1;
    }

public:
    std::string trimTrailingVowels(std::string s) {
        // 持續檢查尾端，直到為空或尾端不再是母音
        while (!s.empty() && isVowel(s.back())) {
            s.pop_back();
        }
        return s;
    }
};

```
