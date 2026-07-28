## <a name="tree"></a>🌳 Tree (樹結構)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0094 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) | 🟢 Easy | Tree <br> DFS | [C++](./solution-pages/Solution_0094.md) | O(n) | O(h) | [Note](#0094-binary-tree-inorder-traversal) |
| 0100 | [Same Tree](https://leetcode.com/problems/same-tree/) | 🟢 Easy | Tree | [C++](./solution-pages/Solution_0100.md) | O(n) | O(h) | [Note](#0100-same-tree) |
| 0105 | [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | 🟡 Medium | Tree <br> Recursion | [C++](./solution-pages/Solution_105.md) | O(N) | O(N) |
| 0106 | [Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) | 🟡 Medium | Tree <br> Recursion | [C++](./solution-pages/Solution_106.md) | O(N) | O(N) |
| 0144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/) | 🟢 Easy | Tree | [C++](./solution-pages/Solution_0144.md) | O(n) | O(h) | [Note](#0144-binary-tree-preorder-traversal) |
| 0145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/) | 🟢 Easy | Tree | [C++](./solution-pages/Solution_0145.md) | O(n) | O(h) | [Note](#0145-binary-tree-postorder-traversal) |
| 0226 | [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) | 🟢 Easy | Tree | [C++](./solution-pages/Solution_0226.md) | O(n) | O(h) | [Note](#0226-binary-invert-binary-tree) |
| 0236 | [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree) | 🟡 Medium | Tree <br> DFS <br> Recursion | [C++](./solution-pages/Solution_0236.md) | O(n) | O(h) |
| 0589 | [N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal/) | 🟢 Easy | Tree | [C++](./solution-pages/Solution_0589.md) | O(n) | O(h) |
| 0590 | [N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal/) | 🟢 Easy | Tree | [C++](./solution-pages/Solution_0590.md) | O(n) | O(h) |
| 0889 | [Construct Binary Tree from Preorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/) | 🟡 Medium | Tree <br> Recursion | [C++](./solution-pages/Solution_889.md) | O(N) | O(N) |
| 2236 | [Root Equals Sum of Children](https://leetcode.com/problems/root-equals-sum-of-children/) | 🟢 Easy | Tree | [C++](./solution-pages/Solution_2236.md) | O(1) | O(1) |
| 2331 | [Evaluate Boolean Binary Tree](https://leetcode.com/problems/evaluate-boolean-binary-tree) | 🟢 Easy | Tree <br> DFS <br> Recursion | [C++](./solution-pages/Solution_2331.md) | O(n) | O(h) |

### 0094 Binary Tree Inorder Traversal
> [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) <br>
> root為空則return，遞迴左子樹，把root->val加入到result vector，遞迴右子樹<br>
---

### 0100 Same Tree
> [Same Tree](https://leetcode.com/problems/same-tree/) <br>
> 如果p q 都為空，回傳true，只有p或只有或兩個val不相等，回傳false，最後return isSameTree(p左子樹和q左子樹) 且 isSameTree(p右子樹和q右子樹)<br>
---

### 0144 Binary Tree Preorder Traversal
> [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/) <br>
root為空則return，把root->val加入到result vector，遞迴左子樹，遞迴右子樹<br>

---

### 0145 Binary Tree Postorder Traversal
> [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/) <br>
root為空則return，遞迴左子樹，遞迴右子樹，把root->val加入到result vector<br>

---

### 0226 Binary Invert Binary Tree
> [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) <br>
root為空則return，swap左右子樹的node，invertTree遞迴左子樹，invertTree遞迴右子樹<br>

---


<br><br>
---

