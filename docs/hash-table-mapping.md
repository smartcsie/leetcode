## <a name="hash-table-mapping"></a>🔑 Hash Table - Mapping (映射 / 異位詞 / 同構)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0001 | [Two Sum](https://leetcode.com/problems/two-sum/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0001.cpp.md) | O(n) | O(n) |
| 0012 | [Integer to Roman](https://leetcode.com/problems/integer-to-roman) | 🟡 Medium | Math <br> Hash Table <br> String | [C++](./solution/Solution_0012.cpp.md) | O(1) | O(1) |
| 0013 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer) | 🟢 Easy | Hash Table <br> Math <br> String | [C++](./solution/Solution_0013.cpp.md) | O(N) | O(1) |
| 0036 | [Valid Sudoku](https://leetcode.com/problems/valid-sudoku) | 🟡 Medium | Array <br> Hash Table <br> Bitset | [C++](./solution/Solution_0036.cpp.md) | O(1) | O(1) |
| 0128 | [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) | 🟡 Medium | Array <br> Hash Table | [C++](./solution/Solution_0128.cpp.md) | O(N) | O(N) |
| 0202 | [Happy Number](https://leetcode.com/problems/happy-number) | 🟢 Easy | Hash Table <br> Fast-Slow Pointers | [C++](./solution/Solution_0202.cpp.md) | O(logn) | O(1) |
| 0205 | [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings) | 🟢 Easy | Hash Table <br> String | [C++](./solution/Solution_0205.cpp.md) | O(n) | O(1) |
| 0242 | [Valid Anagram](https://leetcode.com/problems/valid-anagram) | 🟢 Easy | Hash Table <br> String | [C++](./solution/Solution_0242.cpp.md) | O(n) | O(1) |
| 0290 | [Word Pattern](https://leetcode.com/problems/word-pattern) | 🟢 Easy | Hash Table <br> String | [C++](./solution/Solution_0291.cpp.md) | O(N + M) | O(N + M) |
| 0383 | [Ransom Note](https://leetcode.com/problems/ransom-note) | 🟢 Easy | Hash Table <br> String | [C++](./solution/Solution_0383.cpp.md) | O(M + N) | O(1) |
| 0454 | [4Sum II](https://leetcode.com/problems/4sum-ii) | 🟡 Medium | Hash Table | [C++](./solution/Solution_0454.cpp.md) | O(n²) | O(n²) |
| 0804 | [Unique Morse Code Words](https://leetcode.com/problems/unique-morse-code-words/) | 🟢 Easy | Hash Set | [C++](./solution/Solution_0804.cpp.md) | O(S) | O(S) | [Note](#0804-unique-morse-code-words) |
| 0884 | [Uncommon Words from Two Sentences](https://leetcode.com/problems/uncommon-words-from-two-sentences) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0884.cpp.md) | O(N + M) | O(N + M) |
| 1002 | [Find Common Characters](https://leetcode.com/problems/find-common-characters) | 🟢 Easy | Array <br> Hash Table <br> String | [C++](./solution/Solution_1002.cpp.md) | O(N*K) | O(1) |
| 1309 | [Decrypt String from Alphabet to Integer Mapping](https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/) | 🟢 Easy | Hash Table / String Parsing | [C++](./solution/Solution_1309.cpp.md)  | O(N) | O(1) | |
| 1436 | [Destination City](https://leetcode.com/problems/destination-city) | 🟢 Easy | Hash Table <br> String | [C++](./solution/Solution_1436.cpp.md) | O(N) | O(N) |
| 1640 | [Check Array Formation Through Concatenation](https://leetcode.com/problems/check-array-formation-through-concatenation/) | 🟢 Easy | Hash Map | [C++](./solution/Solution_1640.cpp.md) | O(N) | O(N) | [Note](#1640-check-array-formation-through-concatenation) |
| 2133 | [Check if Every Row and Column Contains All Numbers](https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers) | 🟢 Easy | Array <br> Hash Table <br> Bitset | [C++](./solution/Solution_2133.cpp.md) | O(n²) | O(n) |
| 2154 | [Keep Multiplying Found Values by Two](https://leetcode.com/problems/keep-multiplying-found-values-by-two) | 🟢 Easy | Array <br> Hash Table <br> Simulation | [C++](./solution/Solution_2154.cpp.md) | O(n) | O(n) |
| 2342 | [Max Sum of a Pair With Equal Sum of Digits](https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/) | 🟡 Medium | Hash Table / Math | [C++](./solution/Solution_2342.cpp.md) | O(N*logM) | O(N) | |
| 2418 | [Sort the People](https://leetcode.com/problems/sort-the-people) | 🟢 Easy | Array <br> Sorting <br> Hash Table | [C++](./solution/Solution_2418.cpp.md) | O(NlogN) | O(N) |
| 2441 | [Largest Positive Integer That Exists With Its Negative](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative) | 🟢 Easy | Hash Table <br> Two Pointers <br> Sorting | [C++](./solution/Solution_2441.cpp.md) | O(n) | O(n) |
| 3678 | [Smallest Absent Positive Greater Than Average](https://leetcode.com/problems/smallest-absent-positive-greater-than-average/) | 🟢 Easy | Array <br> Hash Set | [C++](./solution/Solution_3678.cpp.md) | O(N) | O(N) |
| 3838 | [Weighted Word Mapping](https://leetcode.com/problems/weighted-word-mapping/) | 🟢 Easy | Hash Mapping / Simulation | [C++](./solution/Solution_3828.cpp.md) | O(N * L) | O(1) | |


> [!NOTE]
> [Two Sum](./solution/Solution_0001.cpp.md) 因為**尚未排序**過，所以 Complexity **O(n), O(n)**<br>
> [Two Sum II](./solution/Solution_0167.cpp.md) 因為**已排序**，所以 Complexity **O(n), O(1)**<br>

> [!NOTE]
> [2001 Number of Pairs of Interchangeable Rectangles](./solution/Solution_2001.cpp.md) 和 [1512. Number of Good Pairs](./solution/Solution_1512.cpp.md)<br>
> 同時用到了 Greedy Math Pattern，(1+n)/2<br>
> [2001 Number of Pairs of Interchangeable Rectangles](./solution/Solution_2001_1.cpp.md)同時也在考<br>
> **浮點數精度問題(Floating-point precision)-某些比例可能在運算中產生微小的誤差（例如1/3在某些計算環境下可能不完全相等）**<br>
> **導致原本應該視為相同的比例被誤判為不同。**<br>

### 0804. Unique Morse Code Words
> [Unique Morse Code Words](https://leetcode.com/problems/unique-morse-code-words/) <br>
> 用一組 vector<string> morse 定義morse code mapping<br>
> 針對words每個string，轉為morsecode，放入unordered_set<string> unique_codes;<br>
> 因為unordered_set會去重覆，最後unique_codes.size();<br>

### 1640. Check Array Formation Through Concatenation
> [Check Array Formation Through Concatenation](https://leetcode.com/problems/check-array-formation-through-concatenation/) <br>
> 用一組  unordered_map<int,vector<int>> map 紀錄每組vector第一個int和該組vector <br>
> 對arr 使用index i，如果arr[i]在map中找到，取出來，每個int開始比對，i往後走<br>

### 2342. Max Sum of a Pair With Equal Sum of Digits
> [Max Sum of a Pair With Equal Sum of Digits](https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/) <br>
> **int digit_sum = digitSum(num);** <br>
> **if(digit_max_map.count(digit_sum)) {** <br>
> &emsp;&emsp;&emsp;&emsp;**maximum  = std::max(maximum, digit_max_map[digit_sum] + num );** <br>
> &emsp;&emsp;&emsp;&emsp;**digit_max_map[digit_sum] = std::max(digit_max_map[digit_sum], num);** <br>
> **} else {** <br>
> &emsp;&emsp;&emsp;&emsp;**digit_max_map[digit_sum] = num;** <br>
> **}** <br>


<br><br>
---

