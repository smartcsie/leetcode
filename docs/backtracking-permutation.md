## <a name="backtracking-permutation"></a>🔢 Backtracking Permutation(回朔法 排列)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0046 | [Permutations](https://leetcode.com/problems/permutations/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0046.cpp) | O(N*N!) | O(N) | [Note](#0046-permutations) |
| 0047 | [Permutations II](https://leetcode.com/problems/permutations-ii/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0047.cpp) | O(N*N!) | O(N) |
| 3483 | [Unique 3-Digit Even Numbers](https://leetcode.com/problems/unique-3-digit-even-numbers/) | 🟢 Easy | Backtracking | [C++](./solution/Solution_3483_1.cpp) | O(P(N, 3)) | O(N) | |


### 0046. Permutations
> [Permutations](https://leetcode.com/problems/permutations/)<br>
> start == size，則一組排列結果完成，for loop i，從 start 到size - 1，先swap start 和 i，start + 1 帶入遞迴，再swap start 和 i做恢復<br>
---


<br><br>
---

> [!NOTE]
一個實用的分類判斷法則<br>
遇到新題目時可以這樣快速判斷：<br>
**(1) [1,2] 和 [2,1] 算不算同一個答案？** <br>
算同一個 → Combination<br>
不算同一個 → Permutation<br>
**(2) 同一個元素能不能重複選？** <br>
不行 → 用 used[]（排列）或 start+1（組合)<br>
可以 → 排列時用 visited 但允許同層重複跳過；組合時遞迴呼叫用 start 而非 start+1<br>
**(3) 陣列本身有沒有重複數字，且要求結果不能重複？** <br>
有 → 先排序，遞迴時 if (i > start && nums[i] == nums[i-1]) continue; 做去重<br>



