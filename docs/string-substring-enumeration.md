## <a name="string-substring-enumeration"></a>🔗 String - Substring Enumeration (字串 子字串列舉)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1291 | [Sequential Digits](https://leetcode.com/problems/sequential-digits/) | 🟡 Medium | Brute Force / String | [C++](./solution/Solution_1291.cpp.md) | O(1) | O(1) | |
| 3556 | [Sum of Largest Prime Substrings](https://leetcode.com/problems/sum-of-largest-prime-substrings/) | 🟡 Medium | Math / Brute Force | [C++](./solution/Solution_3556.cpp.md) | O(N²*sqrt(M)) | O(1) | [Note](#3556-sum-of-largest-prime-substrings) |
| 3713 | [Longest Balanced Substring I](https://leetcode.com/problems/longest-balanced-substring-i/) | 🟡 Medium | Brute Force / Math | [C++](./solution/Solution_3713.cpp.md) | O(N^2) | O(1) |  |

### 3556 Sum of Largest Prime Substrings
> [Sum of Largest Prime Substrings](https://leetcode.com/problems/sum-of-largest-prime-substrings/) <br>
> 雙層迴圈計算列出子字串，轉成數字，for(int i = 0;i < n; i++)  for(int j = i;j < n; j++) curNum = curNum * 10 + (s[j] - '0');<br>
> 如果curNum是prime，curNum更新到前三大的數，if(isPrime(curNum)) updateMax(curNum, max1, max2, max3); <br>
---

### 3713 Longest Balanced Substring I
> [Longest Balanced Substring I](https://leetcode.com/problems/longest-balanced-substring-i/) <br>
> 對於 3713. Longest Balanced Substring I，這題通常不能直接用單一的「滑動視窗」來解，原因在於它的定義要求「所有出現過的字元頻率必須相等」。<br>
> [3090 Maximum Length Substring](https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/)是Sliding window的一個例子<br>
> 為什麼滑動視窗很難用在這裡？<br>
> 典型的滑動視窗（如上一題 3090）適用於「頻率上限檢查」（例如 count <= 2），當條件不滿足時，我們可以透過移動 left 來快速縮小視窗直到條件再次滿足。<br>
> 然而，「平衡」的定義要求的是「各字元頻率相等」。如果視窗內有 'a': 2, 'b': 1，當你滑動時，這個條件極不穩定。這導致你無法單純地透過移動 left 來保證平衡，因為「平衡」是一個非常脆弱的狀態。<br>

---



<br><br>
---



