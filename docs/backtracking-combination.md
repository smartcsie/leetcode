## <a name="backtracking-combination"></a>🔢 Backtracking Combination(回朔法 組合)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **0017** | [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0017.cpp) | O(4^N) | O(N) | [Note](#0017-letter-combinations-of-a-phone-number) |
| 0022 | [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) | 🟡 Medium | Backtracking / String | [C++](./solution/Solution_0022.cpp) | O(4ᴺ/√N) | O(N) |
| 0039 | [Combination Sum](https://leetcode.com/problems/combination-sum/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0039.cpp) | O(N^(T/M)) | O(T/M) | [Note](#0039-combination-sum) |
| 0040 | [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) | 🟡 Medium | Backtracking / Sorting | [C++](./solution/Solution_0040.cpp) | O(2ᴺ) | O(N) | [Note](#0040-combination-sum-ii) |
| 0077 | [Combinations](https://leetcode.com/problems/combinations/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0077.cpp) | O(k * C(n, k)) | O(k) |
| 0078 | [Subsets](https://leetcode.com/problems/subsets) | 🟡 Medium | Backtracking / Recursion <br> Bit Manipulation | [C++](./solution/Solution_0078.cpp) | O(N*2ᴺ) | O(N) |
| 0079 | [Word Search](https://leetcode.com/problems/word-search/) | 🟡 Medium | DFS / Backtracking | [C++](./solution/Solution_0079.cpp) | O(N*3ᴸ) | O(L) |
| 0090 | [Subsets II](https://leetcode.com/problems/subsets-ii/) | 🟡 Medium | Backtracking / Sorting | [C++](./solution/Solution_0090.cpp) | O(N*2ᴺ) | O(N) |
| 0216 | [Combination Sum III](https://leetcode.com/problems/combination-sum-iii/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0216.cpp) | O(C(9, k)) | O(k) |
| 0784 | [Letter Case Permutation](https://leetcode.com/problems/letter-case-permutation/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0784.cpp) | O(2ᴺ) | O(N) | [Note](#0784-letter-case-permutation) |


### 0017. Letter Combinations of a Phone Number
> [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)<br>
> vector<string> phone = {"abc", "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};<br>
> index為digits目前走到第index個char，phone[digits[index]-'2']為digits[index]所對應到的phone string<br>
---

### 0039. Combination Sum
> [Combination Sum](https://leetcode.com/problems/combination-sum/)<br>
> 先對candidates做排序，sort(candidates.begin(), candidates.end());<br>
> 副程式combinationSum，多int start call by value，vector<vector<int>> res; vector<int> cur; call by reference<br>
> for(int i = start; i < candidates.size(); i++)內要判斷 if(candidates[i] > target) break;否則跑不出來<br>
> 因為此題允許元素重覆使用，遞迴呼叫**i不用+1**，combinationSum(candidates, target , **i**, cur, res);<br>
---

### 0040. Combination Sum II
> [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) <br>
> 先對candidates做排序，sort(candidates.begin(), candidates.end());<br>
> 副程式combinationSum2，多int start call by value，vector<vector<int>> res; vector<int> cur; call by reference<br>
> 去重覆，**if(i > start && candidates[i] == candidates[i - 1]) continue;**<br>
> 因為此題**不**允許元素重覆使用，遞迴呼叫**i需用+1**， combinationSum2(candidates, target - candidates[i], **i+1**, cur, res);<br>
---



### 0784. Letter Case Permutation
> [Letter Case Permutation](https://leetcode.com/problems/letter-case-permutation/) <br>
> index從開始傳進backtrack，因為只要處理大小寫，index先跳過不是大小寫，while (index < s.size() && isdigit(s[index])) index++<br>
> 終止遞迴條件， if(index == s.size()) { res.push_back(s); return;}<br>
> index目標字元轉lowercase遞迴， s[index] = tolower(s[index]); backtrack(s, index + 1, res);<br>
> index目標字元轉uppercase遞迴， s[index] = toupper(s[index]); backtrack(s, index + 1, res);<br>
---





<br><br>
---

