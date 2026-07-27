## <a name="string-substring"></a>🔗 String - Character (字串 統計字元)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0387 | [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string) | 🟢 Easy | Hash Table <br> String | [C++](./solution/Solution_0387.cpp) | O(n) | O(1) | [Note](#0387-first-unique-character-in-a-string) |
| 1941 | [Check if All Characters Have Equal Number of Occurrences](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences) | 🟢 Easy | Hash Table <br> String <br> Counting | [C++](./solution/Solution_1941.cpp) | O(n) | O(1) |
[Note](#1941-first-unique-character-in-a-string) |
### 0387. First Unique Character in a String
> [Number of Strings That Appear as Substrings in Word](https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/) <br>
> 第1個loop，統計字元出現頻頻率， **for(char c : s)  count[c-'a']++**; <br>
> 第2個loop，檢查頻率=1，return; <br>

---

### 1941. First Unique Character in a String
> [Check if All Characters Have Equal Number of Occurrences](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences) <br>
> 第1個loop，統計字元出現頻頻率，**for(char c : s)  count[c-'a']++;** <br>
> 因為要確認所有char頻率都一樣，所以以第一個字元為頻率比較基準，**int freq =   count[s[0]-'a'];** <br>
> 第2個loop， 檢查所有非0頻率都相等

---



<br><br>
---

