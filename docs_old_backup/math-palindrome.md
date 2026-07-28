## <a name="math-palindrome"></a>🔢 Math Palindrome(數學-回文)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0009 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | 🟢 Easy | Math | [C++](./solution-pages/Solution_0009.md) | O(logn) | O(1) | [Note](#0009-palindrome-number) |
| 0866 | [Prime Palindrome](https://leetcode.com/problems/prime-palindrome/) | 🟡 Medium | Math / Palindrome | [C++](./solution-pages/Solution_0866.md) | O(sqrt(P) * 10^(L/2)) | O(1) |
| 2396 | [Strictly Palindromic Number](https://leetcode.com/problems/strictly-palindromic-number/) | 🟡 Medium | Math <br> Brainteaser | [C++](./solution-pages/Solution_2396.md) | O(1) | O(1) | [Note](#2396-strictly-palindromic-number) |


### 0009. Palindrome Number
>  [Palindrome Number](https://leetcode.com/problems/palindrome-number/)<br>
> x < 0 則 return false <br>
> x == 0 則 return true <br>
> **while回圈內，邊界條件如下** <br>
> **if (reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && (x % 10) > 7)) return 0;** <br>
---

### 2396 Strictly Palindromic Number
> [Strictly Palindromic Number](https://leetcode.com/problems/strictly-palindromic-number/) 
> return false;

---


<br><br>
---


