## <a name="two-pointers-other"></a>👥 Two Pointers - Other (變形型)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0160 | [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists) | 🟢 Easy | Linked List <br> Two Pointers | [C++](./solution/Solution_0160.cpp.md) | O(n+m) | O(1) |
| 0442 | [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array) | 🟡 Medium | Array <br> Two Pointers | [C++](./solution/Solution_0442.cpp.md) | O(n) | O(1) |
| 0557 | [Reverse Words in a String III](https://leetcode.com/problems/reverse-words-in-a-string-iii) | 🟢 Easy | String <br> Two Pointers | [C++](./solution/Solution_0557.cpp.md) | O(n) | O(1) |
| 2441 | [Largest Positive Integer That Exists With Its Negative](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative) | 🟢 Easy | Hash Table <br> Two Pointers <br> Sorting | [C++](./solution/Solution_2441_1.cpp.md) | O(n) | O(n) |

> [!NOTE]
> [Other 各題特色]<br>
> 0160 等長走法：兩指針分別走完各自鏈表後換到對方頭部，相遇點即交叉點。<br>
> 0442 負號標記：用 index 當作 hash key，對應位置取負號來記錄「出現過」。<br>
> 0557 區段內反轉：先找到每個單字的邊界，再對撞交換字元。<br>
> 2441 排序後對撞：先排序，left 從頭找正數，right 從尾找對應負數。<br>

<br><br>
---

