## <a name="two-pointers-same"></a>👥 Two Pointers - Same Direction (同向型)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0031 | [Next Permutation](https://leetcode.com/problems/next-permutation/) | 🟡 Medium | Array / Two Pointers | [C++](./solution/Solution_0031.cpp.md) | O(N) | O(1) |
| 0086 | [Partition List](https://leetcode.com/problems/partition-list/) | 🟡 Medium | Linked List / Two Pointers | [C++](./solution/Solution_0086.cpp.md) | O(N) | O(1) |
| 0228 | [Summary Ranges](https://leetcode.com/problems/summary-ranges) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0228.cpp.md) | O(N) | O(1) |
| 0328 | [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/) | 🟡 Medium | Linked List | [C++](./solution/Solution_0328.cpp.md) | O(N) | O(1) |
| 0392 | [Is Subsequence](https://leetcode.com/problems/is-subsequence) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_0392.cpp.md) | O(n) | O(1) |
| 0443 | [String Compression](https://leetcode.com/problems/string-compression/) | 🟡 Medium | Two Pointers | [C++](./solution/Solution_0443.cpp.md) | O(N) | O(1) |
| 0541 | [Reverse String II](https://leetcode.com/problems/reverse-string-ii/) | 🟢 Easy | String / Two Pointers | [C++](./solution/Solution_0541.cpp.md) | O(N) | O(1) |
| 0844 | [Backspace String Compare](https://leetcode.com/problems/backspace-string-compare) | 🟢 Easy | String <br> Two Pointers | [C++](./solution/Solution_0844.cpp.md) | O(N+M) | O(1) |
| 1089 | [Duplicate Zeros](https://leetcode.com/problems/duplicate-zeros) | 🟢 Easy | Array / Two Pointers | [C++](./solution/Solution_1089.cpp.md) | O(N) | O(1) |
| 1417 | [Reformat The String](https://leetcode.com/problems/reformat-the-string/) | 🟢 Easy | String / Two Pointers | [C++](./solution/Solution_1417.cpp.md) | O(N) | O(N) | |
| 1721 | [Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list) | 🟡 Medium | Linked List <br> Two Pointers | [C++](./solution/Solution_1721.cpp.md) | O(N) | O(1) |
| 1768 | [Merge Strings Alternately](https://leetcode.com/problems/merge-strings-alternately) | 🟢 Easy | String <br> Two Pointers | [C++](./solution/Solution_1768.cpp.md) | O(N+M) | O(1) |
| 2109 | [Adding Spaces to a String](https://leetcode.com/problems/adding-spaces-to-a-string) | 🟡 Medium | String <br> Two Pointers | [C++](./solution/Solution_2109.cpp.md) | O(N+M) | O(N+M) |
| 2540 | [Minimum Common Value](https://leetcode.com/problems/minimum-common-value) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_2540.cpp.md) | O(N+M) | O(1) |
| 3132 | [Find the Integer Added to Array II](https://leetcode.com/problems/find-the-integer-added-to-array-ii/) | 🟡 Medium | Sorting / Two Pointers | [C++](./solution/Solution_3132.cpp.md) | O(NlogN) | O(1) | |
| 3637 | [Trionic Array I](https://leetcode.com/problems/trionic-array-i/) | 🟢 Easy | Two Pointers / State Transition | [C++](./solution/Solution_3637.cpp.md) | O(N) | O(1) | |
| 3819 | [Rotate Non Negative Elements](https://leetcode.com/problems/rotate-non-negative-elements/) | 🟢 Easy | Array / Two Pointers | [C++](./solution/Solution_3819.cpp.md) | O(N) | O(N) |
| 3940 | [Limit Occurrences in Sorted Array](https://leetcode.com/problems/limit-occurrences-in-sorted-array/) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_3940.cpp.md) | O(N) | O(1) |


> [!NOTE]
> [Same Direction 核心概念]<br>
> 兩個指針同方向前進，各自掃描不同陣列或字串（0392、1768、2540）。<br>
> 或一個指針掃描、另一個記錄「有效位置」（0228、0844）。<br>
> 0844 從**尾端**往前同向掃描，模擬退格後比對。<br>

> [!NOTE]
> [0392 Is Subsequence](./solution/Solution_0392.cpp.md)<br>
> 此題如果用 Dynamic Programming LCS，Complexity 會是 O(nm)，O(nm)<br>
> 但如果用 Two Pointers 會是 O(n)，O(1)<br>

<br><br>
---

