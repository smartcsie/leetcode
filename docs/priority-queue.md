## <a name="priority-queue"></a>📚 Priority Queue (優先佇列)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0023 | [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists) | 🔴 Hard | Heap <br> Linked List | [C++](./solution/Solution_0023.cpp.md) | O(Nlogk) | O(k) |
| 0373 | [Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sum/) | 🟡 Medium | Heap <br> Greedy | [C++](./solution/Solution_0373.cpp.md) | O(KlogK) | O(K) |
| 0692 | [Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words) | 🟡 Medium | Hash Table <br> Heap | [C++](./solution/Solution_0692.cpp.md) | O(NlogK) | O(N) |
| 0703 | [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream) | 🟢 Easy | Heap (Priority Queue) | [C++](./solution/Solution_0703.cpp.md) | O(NlogK) / O(log K) | O(K) |
| 0786 | [K-th Smallest Prime Fraction](https://leetcode.com/problems/k-th-smallest-prime-fraction/) | 🟡 Medium | Priority Queue / Binary Search | [C++](./solution/Solution_0786.cpp.md) | O(N log N) | O(N) | |
| 1046 | [Last Stone Weight](https://leetcode.com/problems/last-stone-weight) | 🟢 Easy | Heap (Priority Queue) | [C++](./solution/Solution_1046.cpp.md) | O(NlogN) | O(N) |

> [!NOTE]
> [692. [Top K Frequent Words](./solution/Solution_0692.cpp.md)<br>
> 在 N=500時，NlogN與NlogK的差異微乎其微（甚至因為 CPU 快取命中率與常數項的緣故，std::sort 往往比 std::priority_queue 跑得更快）。<br>
> std::sort O(NlogN)：雖然時間複雜度看起來較高，但它在底層實作上非常平滑，且不需要額外的記憶體配置與大量的節點比較運算，在500個元素的規模下，這幾乎是瞬間完成。<br>
> std::priority_queue：O(NlogK)：雖然複雜度在K N時較佳，但它涉及大量的 push 與 pop 操作，以及頻繁的物件移動，這些都是額外的開銷。<br>


<br><br>
---

