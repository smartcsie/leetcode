## <a name="string-character-classification "></a>🔗 String - Character Classification (字串 字元識別)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0520 | [Detect Capital](https://leetcode.com/problems/detect-capital/) | 🟢 Easy | String | [C++](./solution/Solution_0520.cpp.md) | O(N) | O(1) | [Note](#0520-detect-capital) |
| 0709 | [To Lower Case](https://leetcode.com/problems/to-lower-case) | 🟢 Easy | String | [C++](./solution/Solution_0709.cpp.md) | O(N) | O(1) | [Note](#0709-to-lower-case) |
| 1347 | [Minimum Number of Steps to Make Two Strings Anagram](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/) | 🟡 Medium | Hash Table / String / Counting | [C++](./solution/Solution_1347.cpp.md) | O(N) | O(1) | |
| 1704 | [Determine if String Halves Are Alike](https://leetcode.com/problems/determine-if-string-halves-are-alike/) | 🟢 Easy | String / Bit Manipulation | [C++](./solution/Solution_1704.cpp.md) | O(N) | O(1) | [Note](#1704-second-largest-digit-in-a-string) |
| 1796 | [Second Largest Digit in a String](https://leetcode.com/problems/second-largest-digit-in-a-string/) | 🟢 Easy | String <br> Hash Table | [C++](./solution/Solution_1796.cpp.md) | O(N) | O(1) |[Note](#1796-second-largest-digit-in-a-string) |
| 1903 | [Largest Odd Number in String](https://leetcode.com/problems/largest-odd-number-in-string/) | 🟢 Easy | String | [C++](./solution/Solution_1903.cpp.md) | O(N) | O(1) | [Note](#1903-largest-odd-number-in-string) |
| 1935 | [Maximum Number of Words You Can Type](https://leetcode.com/problems/maximum-number-of-words-you-can-type/) | 🟢 Easy | String / Stream | [C++](./solution/Solution_1935.cpp.md) | O(N * M) | O(1) | |
| 1957 | [Delete Characters...](https://leetcode.com/problems/delete-characters-to-make-fancy-string/) | 🟢 Easy | String / Two Pointers | [C++](./solution/Solution_1957.cpp.md) | O(N) | O(N) | |
| 2124 | [Check if All A's Appears Before All B's](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs) | 🟢 Easy | String | [C++](./solution/Solution_2124.cpp.md) | O(N) | O(1) | [Note](#2124-check-if-all-as-appears-before-all-bs) |
| 2278 | [Percentage of Letter in String](https://leetcode.com/problems/percentage-of-letter-in-string/) | 🟢 Easy | String / Counting | [C++](./solution/Solution_2278.cpp.md) | O(N) | O(1) | |
| 2399 | [Check Distances Between Same Letters](https://leetcode.com/problems/check-distances-between-same-letters/) | 🟢 Easy | Hash Table / String / Array | [C++](./solution/Solution_2399.cpp.md) | O(N) | O(1) ||
| 2496 | [Maximum Value of a String in an Array](https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/) | 🟢 Easy | Array / String / Simulation | [C++](./solution/Solution_2496.cpp.md) | O(N * L) | O(1) | |
| 2586 | [Count the Number of Vowel Strings in Range](https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range) | 🟢 Easy | Array <br> String | [C++](./solution/Solution_2586.cpp.md) | O(n) | O(1) |
| 2678 | [Number of Senior Citizens](https://leetcode.com/problems/number-of-senior-citizens) | 🟢 Easy | String | [C++](./solution/Solution_2678.cpp.md) | O(n) | O(1) | [Note](#2678-number-of-senior-citizens) |
| 2710 | [Remove Trailing Zeros From a String](https://leetcode.com/problems/remove-trailing-zeros-from-a-string/) | 🟢 Easy | String / Two Pointers |  [C++](./solution/Solution_2710.cpp.md) | O(N) | O(1) | [Note](#2710-check-if-a-string-is-an-acronym-of-words) |
| 3110 | [Score of a String](https://leetcode.com/problems/score-of-a-string) | 🟢 Easy | String | [C++](./solution/Solution_3110.cpp.md) | O(N) | O(1) |
| 3121 | [Count the Number of Special Characters II](https://leetcode.com/problems/count-the-number-of-special-characters-ii/) | 🟡 Medium | String Processing | [C++](./solution/Solution_3121.cpp.md) | O(N) | O(1) | [Note](#3121-special-chars-ii) | | 
| 3136 | [Valid Word](https://leetcode.com/problems/valid-word/) | 🟢 Easy | String / Validation | [C++](./solution/Solution_3136.cpp.md) | O(N) | O(1) | [Note](#3136-valid-word) |
| 3775 | [Reverse Words With Same Vowel Count](https://leetcode.com/problems/reverse-words-with-same-vowel-count/) | 🟢 Easy | String / Two Pointers | [C++](./solution/Solution_3775.cpp.md) | O(N*L) | O(N) |
| 3813 | [Vowel-Consonant Score](https://leetcode.com/problems/vowel-consonant-score/) | 🟢 Easy | String Processing | [C++](./solution/Solution_3813.cpp.md) | O(N) | O(1) | |
| 3856 | [Trim Trailing Vowels](https://leetcode.com/problems/trim-trailing-vowels/) | 🟢 Easy | String / Two Pointers | [C++](./solution/Solution_3856.cpp.md) | O(N) | O(1) | [Note](#3856-trim-trailing-vowels) |
| 3931 | [Check Adjacent Digit Differences](https://leetcode.com/problems/check-adjacent-digit-differences/) | 🟢 Easy | String <br> Math | [C++](./solution/Solution_3931.cpp.md) | O(N) | O(1) |


### 0520. Detect Capital
> [Detect Capital](https://leetcode.com/problems/detect-capital/) <br>
> count計算uppercase個數<br>
> 全部小寫 count == 0，全部大寫 count == word.size()，第一個char大寫 count == 1 && isupper(word[0])<br>

---


### 0709. To Lower Case
> [To Lower Case](https://leetcode.com/problems/to-lower-case) <br>
> **for(char& c : s ) if(isupper(c)) c += 32;** <br>

---

### 1704. Second Largest Digit in a String
> [Determine if String Halves Are Alike](https://leetcode.com/problems/determine-if-string-halves-are-alike/)<br>
> isVowel函數回傳是否大小寫Vowel，countVowels回傳一個string裡面有多少個Vowel<br>
> 最後檢查左半子字串和右半子字串是否相等，**return countVowels(s.substr(0, mid)) == countVowels(s.substr(mid));** <br>

---


### 1796. Second Largest Digit in a String
> [Second Largest Digit in a String](https://leetcode.com/problems/second-largest-digit-in-a-string/) <br>
> 可能有重覆的數<br>
> **if(digit > large) { second = large; large = digit;}** <br>
> **else if( **digit < large** && digit > second) { second = digit;}** <br>
                
---


### 1903. Largest Odd Number in String
> [Largest Odd Number in String](https://leetcode.com/problems/largest-odd-number-in-string/) <br>
> 一直檢查最後一個digit是否是odd<br>
> for(int i = num.size() - 1; i >= 0; i--) if(num[i] & 1) return num.substr(0, i + 1);<br>

---

### 2124. Check if All A's Appears Before All B's
> [Check if All A's Appears Before All B's](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs)<br>
> 檢查是否存在"ba"的case，如果有，return false<br>
> **return s.find("ba") == string::npos;** <br>


---

### 2678. Number of Senior Citizens
> [Number of Senior Citizens](https://leetcode.com/problems/number-of-senior-citizens)  <br>
> Index 11和12是age <br>
> int age = 10 * (detail[11] - '0') + (detail[12] - '0');<br>
> if( age > 60) citizens++;<br>

---

### 2710. Check if a String Is an Acronym of Words
> [Remove Trailing Zeros From a String](https://leetcode.com/problems/remove-trailing-zeros-from-a-string/)<br>
> 類似 3856[Trim Trailing Vowels](https://leetcode.com/problems/trim-trailing-vowels/) <br>
> **while (!num.empty() && num.back() == '0'){** <br>
> &emsp;&emsp;&emsp;&emsp;**num.pop_back();** <br>
> **}** <br>


---


### 3121. Count the Number of Special Characters II
> [Count the Number of Special Characters II](https://leetcode.com/problems/count-the-number-of-special-characters-ii/)  <br>
> 用一組vector紀錄26個大小寫char出現的位置vector<pair<int, int>> indices(26, {-1, -1});<br>
> 大寫紀錄最左邊，小寫紀錄最右邊<br>
> 最後count計算所有char，小寫index在大寫前面(小於)

---




### 3136. Valid Word
> [Valid Word](https://leetcode.com/problems/valid-word/) <br>
> 如果是數字continue， if(isdigit(c)) continue<br>
> 如果是大小寫字母，代入isVowel，計數vowel或consonant<br>
> 不是前兩種，return false<br>
> 最後 (vowel >= 1) && (consonant >= 1)<br>

---

### 3856. Trim Trailing Vowels
> [Trim Trailing Vowels](https://leetcode.com/problems/trim-trailing-vowels/) <br>
> 類似 [Remove Trailing Zeros From a String](https://leetcode.com/problems/remove-trailing-zeros-from-a-string/)<br>
> while loop檢查 s.back()是不是Vowel，如果是，移除<br>
> **while (!s.empty() && isVowel(s.back())) {** <br>
> **&emsp;&emsp;&emsp;&emsp;s.pop_back();** <br>
> **}** <br>


---


<br><br>
---


