# 📐 演算法與定理索引

LeetCode 題目中出現的「有名字」的演算法與定理，依領域分類，附代表題。
這份頁面是手動維護的，不會被 `generate_site.py` 覆蓋。

---

## 數論／數學定理

| 演算法／定理 | 重點 | 代表題 |
| --- | --- | --- |
| Euclidean algorithm（輾轉相除） | gcd(a, b) = gcd(b, a mod b) | [1071. GCD of Strings](https://leetcode.com/problems/greatest-common-divisor-of-strings/)<br>[1979. Find Greatest Common Divisor of Array](https://leetcode.com/problems/find-greatest-common-divisor-of-array/) |
| Fast exponentiation（快速冪） | 指數折半，O(log n) | [50. Pow(x, n)](https://leetcode.com/problems/powx-n/)<br>[1922. Count Good Numbers](https://leetcode.com/problems/count-good-numbers/)<br>[372. Super Pow](https://leetcode.com/problems/super-pow/) |
| Lagrange's four-square theorem | 任何正整數都能寫成至多四個平方數之和 | [279. Perfect Squares](https://leetcode.com/problems/perfect-squares/) |
| Fermat's theorem on sums of two squares | 正整數可寫成兩平方數之和，若且唯若 4k+3 型質因數的次方都是偶數 | [633. Sum of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/) |
| Zeckendorf's theorem | 任何正整數可唯一表示為不連續費氏數之和，貪心取最大的費氏數 | [1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K](https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/) |
| Catalan numbers（卡塔蘭數） | C(n) = Σ C(i) × C(n-1-i) | [96. Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/) |
| Pascal's triangle（帕斯卡三角形） | C(n, k) = C(n-1, k-1) + C(n-1, k) | [118. Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/)<br>[119. Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/) |
| Inclusion–exclusion（容斥原理） | \|A ∪ B\| = \|A\| + \|B\| − \|A ∩ B\| | [878. Nth Magical Number](https://leetcode.com/problems/nth-magical-number/)<br>[1201. Ugly Number III](https://leetcode.com/problems/ugly-number-iii/) |
| Pythagorean triples（畢氏三元數） | a² + b² = c² | [1925. Count Square Sum Triples](https://leetcode.com/problems/count-square-sum-triples/) |
| Newton's method（牛頓法） | x ← (x + a / x) / 2，逼近平方根 | [69. Sqrt(x)](https://leetcode.com/problems/sqrtx/)<br>[367. Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/) |
| Shoelace formula（鞋帶公式） | 多邊形面積 = \|Σ(xᵢ·yᵢ₊₁ − xᵢ₊₁·yᵢ)\| / 2 | [812. Largest Triangle Area](https://leetcode.com/problems/largest-triangle-area/) |
| Gray code（格雷碼） | 相鄰兩數只差一個 bit，第 i 個為 i ^ (i >> 1) | [89. Gray Code](https://leetcode.com/problems/gray-code/) |
| Zeller's congruence／星期推算 | 由年月日推算星期幾 | [1185. Day of the Week](https://leetcode.com/problems/day-of-the-week/) |

---

## 遊戲理論／組合

| 演算法／定理 | 重點 | 代表題 |
| --- | --- | --- |
| Nim game／Sprague–Grundy | 每個局面有 SG 值，多堆遊戲取 XOR；Nim Game 單堆時 n 為 4 的倍數先手必敗 | [292. Nim Game](https://leetcode.com/problems/nim-game/)<br>[877. Stone Game](https://leetcode.com/problems/stone-game/)<br>[1025. Divisor Game](https://leetcode.com/problems/divisor-game/) |
| Josephus problem（約瑟夫問題） | f(n, k) = (f(n-1, k) + k) mod n | [1823. Find the Winner of the Circular Game](https://leetcode.com/problems/find-the-winner-of-the-circular-game/)<br>[390. Elimination Game](https://leetcode.com/problems/elimination-game/) |

---

## 陣列／序列技巧

| 演算法／定理 | 重點 | 代表題 |
| --- | --- | --- |
| Dutch national flag | 三個指標一次掃描，把元素分成三區 | [75. Sort Colors](https://leetcode.com/problems/sort-colors/) |
| Boyer–Moore voting | 抵銷法找出現次數過半的元素 | [169. Majority Element](https://leetcode.com/problems/majority-element/)<br>[229. Majority Element II](https://leetcode.com/problems/majority-element-ii/) |
| Fisher–Yates shuffle | 從後往前，每個位置與前面隨機位置交換 | [384. Shuffle an Array](https://leetcode.com/problems/shuffle-an-array/) |
| Reservoir sampling（水塘抽樣） | 第 i 個元素以 1/i 的機率取代目前的選擇 | [382. Linked List Random Node](https://leetcode.com/problems/linked-list-random-node/)<br>[398. Random Pick Index](https://leetcode.com/problems/random-pick-index/) |
| Quickselect | partition 後只往含目標的一側遞迴，平均 O(N) | [215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) |
| Floyd's cycle detection（龜兔賽跑） | 快慢指標，偵測環與環的起點 | [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)<br>[142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)<br>[287. Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)<br>[202. Happy Number](https://leetcode.com/problems/happy-number/) |
| Morris traversal | 利用空的子節點指標做線索，O(1) 空間走訪樹 | [94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)<br>[144. Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)<br>[99. Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/) |

---

## 字串

| 演算法／定理 | 重點 | 代表題 |
| --- | --- | --- |
| Manacher's algorithm | O(N) 求出所有位置的最長回文半徑 | [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)<br>[647. Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/) |
| Rabin–Karp／rolling hash | 滾動雜湊，O(1) 更新視窗的雜湊值 | [187. Repeated DNA Sequences](https://leetcode.com/problems/repeated-dna-sequences/)<br>[1044. Longest Duplicate Substring](https://leetcode.com/problems/longest-duplicate-substring/) |
| Z-algorithm | Z 陣列：每個位置與整個字串的最長共同前綴長度 | [28. Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)<br>[214. Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/) |
| Aho–Corasick | Trie 加上 fail link，多模式字串比對 | [1032. Stream of Characters](https://leetcode.com/problems/stream-of-characters/)（可用 Trie 變形） |

---

## 圖論

| 演算法／定理 | 重點 | 代表題 |
| --- | --- | --- |
| Dijkstra | 非負權重的單源最短路徑，搭配 priority queue | [743. Network Delay Time](https://leetcode.com/problems/network-delay-time/)<br>[1514. Path with Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability/) |
| Bellman–Ford | 逐輪鬆弛邊，可限制邊數 | [787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/) |
| Floyd–Warshall | 所有點對最短路徑，O(V³) | [1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/) |
| Kruskal／Prim（MST） | 最小生成樹：Kruskal 排序邊加 Union-Find，Prim 逐點擴張 | [1584. Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/)<br>[1135. Connecting Cities With Minimum Cost](https://leetcode.com/problems/connecting-cities-with-minimum-cost/) |
| Kahn's algorithm（拓撲排序） | 反覆移除入度為 0 的節點 | [207. Course Schedule](https://leetcode.com/problems/course-schedule/)<br>[210. Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) |
| Tarjan（橋、SCC） | DFS 時間戳與 low-link，找橋與強連通分量 | [1192. Critical Connections in a Network](https://leetcode.com/problems/critical-connections-in-a-network/) |
| Hierholzer's algorithm（歐拉路徑） | DFS 後序加入路徑再反轉 | [332. Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/) |
| De Bruijn sequence | 涵蓋所有長度 n 的字串各恰好一次的循環序列 | [753. Cracking the Safe](https://leetcode.com/problems/cracking-the-safe/) |
| Binary lifting（倍增法） | 預先存 2^j 級祖先，O(log N) 查詢 | [1483. Kth Ancestor of a Tree Node](https://leetcode.com/problems/kth-ancestor-of-a-tree-node/) |
| LCA（最低共同祖先） | 樹上兩節點最近的共同祖先 | [236. Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)<br>[235. Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) |

---

## 資料結構／其他

| 演算法／定理 | 重點 | 代表題 |
| --- | --- | --- |
| Fenwick tree（BIT）／Segment tree | 單點更新、區間查詢，皆為 O(log N) | [307. Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/)<br>[315. Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)<br>[327. Count of Range Sum](https://leetcode.com/problems/count-of-range-sum/) |
| Sweep line（掃描線） | 依座標排序事件，掃過去維護狀態 | [218. The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/) |
| Convex hull（Andrew monotone chain／Graham scan） | 找出包住所有點的最小凸多邊形 | [587. Erect the Fence](https://leetcode.com/problems/erect-the-fence/) |
| Meet in the middle | 資料對半拆開各自枚舉，再合併，把 2^N 降到 2^(N/2) | [1755. Closest Subsequence Sum](https://leetcode.com/problems/closest-subsequence-sum/) |

---

> 題號與題目連結是依記憶整理的，收錄前建議點開確認；1135 是付費題。
