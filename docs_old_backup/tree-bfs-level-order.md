## <a name="tree-bfs-level-order"></a>🌳 Tree - BFS / Level Order (層序遍歷)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0102 | [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | 🟡 Medium | Tree <br> BFS | [C++](./solution-pages/Solution_0102.md) | O(n) | O(w) |
| 0103 | [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-zigzag-level-order-traversal/) | 🟡 Medium | Tree <br> BFS | [C++](./solution-pages/Solution_0103.md) | O(N) | O(W) |
| 0107 | [Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii) | 🟢 Easy | Tree / BFS | [C++](./solution-pages/Solution_0107.md) | O(N) | O(W) |
| 0199 | [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/) | 🟡 Medium | Tree <br> BFS | [C++](./solution-pages/Solution_0199.md) | O(n) | O(w) |
| 0429 | [N-ary Tree Level Order Traversal](https://leetcode.com/problems/n-ary-tree-level-order-traversal) | 🟡 Medium | Tree <br> BFS | [C++](./solution-pages/Solution_0429.md) | O(N) | O(W) |
| 0513 | [Find Bottom Left Tree Value](https://leetcode.com/problems/find-bottom-left-tree-value) | 🟡 Medium | Tree <br> BFS <br> DFS | [C++](./solution-pages/Solution_0513.md) | O(n) | O(w) |
| 0515 | [Find Largest Value in Each Tree Row](https://leetcode.com/problems/find-largest-value-in-each-tree-row/) | 🟡 Medium | Tree / BFS | [C++](./solution-pages/Solution_515.md) | O(N) | O(W) |
| 0637 | [Average of Levels in Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree) | 🟢 Easy | Tree <br> BFS | [C++](./solution-pages/Solution_0637.md) | O(N) | O(W) |
| 0662 | [Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/) | 🟡 Medium | Tree <br> BFS | [C++](./solution-pages/Solution_0662.md) | O(n) | O(w) |
| 0958 | [Check Completeness of a Binary Tree](https://leetcode.com/problems/check-completeness-of-a-binary-tree/) | 🟡 Medium | BFS <br> Level Order Traversal | [C++](./solution-pages/Solution_0958.md) | O(N) | O(W) |
| 0993 | [Cousins in Binary Tree](https://leetcode.com/problems/cousins-in-binary-tree/) | 🟢 Easy | Tree <br> BFS | [C++](./solution-pages/Solution_993.md) | O(N) | O(W) |
| 1161 | [Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree) | 🟡 Medium | Tree <br> BFS | [C++](./solution-pages/Solution_1161.md) | O(N) | O(W) |
| 1302 | [Deepest Leaves Sum](https://leetcode.com/problems/deepest-leaves-sum/) | 🟡 Medium | Tree <br> BFS | [C++](./solution-pages/Solution_1302.md) | O(N) | O(W) |
| 1609 | [Even Odd Tree](https://leetcode.com/problems/even-odd-tree/) | 🟡 Medium | Tree <br> BFS | [C++](./solution-pages/Solution_1609.md) | O(n) | O(w) |
| 2583 | [Kth Largest Sum in a Binary Tree](https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/) | 🟡 Medium | Tree <br> BFS <br> Math | [C++](./solution-pages/Solution_2583.md) | O(N) | O(N) | 


> [!NOTE]
> BFS Level Order 標準模板：用 queue，每層開始時記錄 `size = q.size()`，再跑 size 次。<br>
> 空間複雜度 O(w)，w 為最寬的一層節點數，最壞情況 O(n/2) = O(n)。<br>

> [!NOTE]
> [107. Binary Tree Level Order Traversal II](./solution-pages/Solution_0107.md)只有比[102. Binary Tree Level Order Traversal](./solution-pages/Solution_0102.md)<br>
> 多一行 Reverse 結果<br>


<br><br>
---

