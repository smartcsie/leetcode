# 主題筆記總整理

這份筆記整理了各主題的代表題、核心概念與常見陷阱，
作為 AI agent 產生各分類筆記頁面的參考資料。

---

## 資料結構

### unordered_map
**代表題**：1. Two Sum
**核心用法**：O(1) 查詢、計數、建立映射

```cpp
unordered_map<int, int> m;
m[key]++;           // 計數
m.count(key);       // 是否存在
m.contains(key);    // C++20
auto [k, v] = *m.begin();  // structured binding
```

**常見陷阱**：
- `unordered_map` 不保證順序，需要排序用 `map`
- 大量衝突時退化成 O(N)，競程可用自訂 hash 避免

---

### unordered_set
**代表題**：217. Contains Duplicate
**核心用法**：O(1) 查詢是否存在、去重

```cpp
unordered_set<int> s(vec.begin(), vec.end());
s.count(x);   // 0 或 1
s.insert(x);
```

---

### Stack
**代表題**：20. Valid Parentheses
**核心用法**：括號匹配、單調棧、後序表達式

```cpp
stack<int> st;
st.push(x); st.pop(); st.top(); st.empty();
```

---

### Monotonic Stack
**代表題**：739. Daily Temperatures
**核心概念**：維護單調遞增或遞減的棧，用來找「下一個更大/更小的元素」

```cpp
// 找下一個更大的元素
for (int i = 0; i < n; i++) {
    while (!st.empty() && nums[st.top()] < nums[i]) {
        ans[st.top()] = i - st.top();
        st.pop();
    }
    st.push(i);
}
```

---

### Monotonic Queue
**代表題**：239. Sliding Window Maximum
**核心概念**：deque 維護視窗內的最大/最小值，front 永遠是當前最優值

```cpp
deque<int> dq;  // 存 index
for (int i = 0; i < n; i++) {
    while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
    dq.push_back(i);
    if (dq.front() < i - k + 1) dq.pop_front();  // 超出視窗
    if (i >= k - 1) ans.push_back(nums[dq.front()]);
}
```

---

### Priority Queue
**代表題（max heap）**：215. Kth Largest Element
**代表題（min heap）**：23. Merge k Sorted Lists

```cpp
priority_queue<int> maxPQ;                           // max heap
priority_queue<int, vector<int>, greater<int>> minPQ; // min heap

// 自訂 comparator
auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
```

**常見陷阱**：
- `greater<int>()` 只能用在存純值的 heap，存指針需自訂 comparator
- 維護 Top K：min heap 只保留 k 個，O(N log K) 比全排序 O(N log N) 快

---

### Trie
**代表題**：208. Implement Trie

```cpp
struct Trie {
    Trie* children[26] = {};
    bool isEnd = false;

    void insert(string word) {
        Trie* cur = this;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->children[i]) cur->children[i] = new Trie();
            cur = cur->children[i];
        }
        cur->isEnd = true;
    }
};
```

---

### Union Find (DSU)
**代表題**：547. Number of Provinces

```cpp
vector<int> parent(n);
iota(parent.begin(), parent.end(), 0);

function<int(int)> find = [&](int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
};
auto unite = [&](int x, int y) { parent[find(x)] = find(y); };
```

---

## 演算法

### Binary Search 三種模式
**代表題**：704. Binary Search（標準）、278. First Bad Version（Left Bound）、69. Sqrt(x)（Right Bound）

```cpp
// 標準查找
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) return mid;
    else if (nums[mid] < target) left = mid + 1;
    else right = mid - 1;
}

// Find Left Bound（第一個滿足條件）
while (left < right) {
    int mid = left + (right - left) / 2;
    if (condition(mid)) right = mid;
    else left = mid + 1;
}
return left;

// Find Right Bound（最後一個滿足條件）
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (condition(mid)) { ans = mid; left = mid + 1; }
    else right = mid - 1;
}
return ans;
```

**lower_bound / upper_bound**（代表題：34. Find First and Last Position）：
```cpp
lower_bound(first, last, val)  // 第一個 >= val
upper_bound(first, last, val)  // 第一個 > val
// 注意：需先排序；STL string::find 不是 KMP，是 Naive O(NM)
```

---

### Sieve of Eratosthenes
**代表題**：204. Count Primes

```cpp
vector<bool> isPrime(n, true);
isPrime[0] = isPrime[1] = false;
for (int p = 2; p * p < n; p++)
    if (isPrime[p])
        for (int i = p * p; i < n; i += p)
            isPrime[i] = false;
```

**優化**：用 `static` 快取讓多次呼叫只跑一次；用 `vector<char>` 取代 `vector<bool>` 避免 bit 操作開銷。

---

### KMP
**代表題**：28. Find the Index of the First Occurrence

```cpp
vector<int> buildLPS(string& p) {
    int m = p.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (p[i] == p[len]) lps[i++] = ++len;
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }
    return lps;
}
```

---

## Bit Manipulation

### XOR 消除
**代表題**：136. Single Number
```cpp
// 所有數 XOR，兩兩抵銷，剩下唯一一個
int ans = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
```

### Brian Kernighan
**代表題**：191. Number of 1 Bits
```cpp
while (n) { n &= (n - 1); count++; }  // 每次消除最低位的 1
```

### `__builtin` 系列
```cpp
__builtin_popcount(x);   // 1 的個數，對應 std::popcount (C++20)
__builtin_clz(x);        // 前導零個數，x 不能為 0
__builtin_ctz(x);        // 尾端零個數
```

### Bitmask Subset Enumeration
**代表題**：78. Subsets、2397. Maximum Rows Covered by Columns
```cpp
for (int mask = 0; mask < (1 << n); mask++)
    for (int i = 0; i < n; i++)
        if (mask & (1 << i))  // 第 i 個元素被選中
```

### 常用 bit 技巧
```cpp
n & (n-1)    // 消除最低位的 1，也用來判斷 2 的冪次（n>0 && !(n&(n-1))）
n & (-n)     // 取最低位的 1
n ^ (n-1)    // 最低位 1 以下全部變 1
x >> i & 1   // 取第 i 位
x |= 1 << i  // 設第 i 位為 1
x &= ~(1<<i) // 清第 i 位
```

---

## DP

### Kadane's Algorithm
**代表題**：53. Maximum Subarray

```cpp
// 原形：維護以當前元素結尾的最大和
sum = max(num, sum + num);  // 等價於：sum += num; if (sum < 0) sum = 0;
mx = max(mx, sum);
```

**變體**：
- 152 Maximum Product Subarray：同時維護 `pos`（正乘積）和 `neg`（負乘積），遇負數 `swap(pos, neg)`
- 1567 Maximum Length of Subarray With Positive Product：同上，求長度不求積

---

### Knapsack 型態
**完整說明見 discussion_notes.md**

| 型態 | 迴圈順序 | 代表題 |
|---|---|---|
| Unbounded 排列/最值 | 外層容量，內層物品 | 322、377、279 |
| Unbounded 組合 | 外層物品，內層容量小→大 | 518 |
| 0/1 任何問法 | 外層物品，內層容量大→小 | 416、494 |

---

### LCS 家族
**代表題**：1143. Longest Common Subsequence

```
LCS → 1143
n + m - 2*LCS → 583 Delete Operation
n + m - LCS → 1092 Shortest Common Supersequence
n - LCS(s, reverse(s)) → 1312 Min Insertion Palindrome
LCS 變體（連續）→ 718 Maximum Length of Repeated Subarray
```

**核心差異**：
- LCS 不匹配：`dp[i][j] = max(dp[i-1][j], dp[i][j-1])`
- 718 不匹配：`dp[i][j] = 0`（連續性打斷）

---

### LIS
**代表題**：300. Longest Increasing Subsequence

```cpp
// O(N²) DP 版
for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
        if (nums[j] < nums[i])
            dp[i] = max(dp[i], dp[j] + 1);

// O(N log N) Patience Sorting 版
vector<int> tails;
for (int x : nums) {
    auto it = lower_bound(tails.begin(), tails.end(), x);
    if (it == tails.end()) tails.push_back(x);
    else *it = x;
}
return tails.size();
```

---

### DP on Tree（`tree-dfs-global`）
**代表題**：543. Diameter of Binary Tree

```cpp
int dfs(TreeNode* root, int& ans) {
    int left  = dfs(root->left,  ans);
    int right = dfs(root->right, ans);
    ans = max(ans, left + right);    // 跨越當前節點的最佳結果
    return 1 + max(left, right);     // 回傳給父節點
}
```

---

### State Machine DP
**代表題**：121. Best Time to Buy and Sell Stock（一次交易）、122（無限次）

```cpp
// 121：口袋 0 元
hold = max(hold, -price);
profit = max(profit, hold + price);

// 122：口袋有前次獲利
hold = max(hold, profit - price);  // 差別在這裡
profit = max(profit, hold + price);
```

---

## Two Pointers

### 滑動視窗
**固定大小（代表題：219）**：
```cpp
for (int i = 0; i < n; i++) {
    // 加入右端
    if (i >= k) // 移除左端
}
```

**可變大小（代表題：3）**：
```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    // 加入 right
    while (條件不滿足) { /* 移除 left */; left++; }
    ans = max(ans, right - left + 1);
}
```

---

## STL 常用技巧

### accumulate
```cpp
// 求和
int sum = accumulate(v.begin(), v.end(), 0);

// XOR（136 Single Number）
int xorAll = accumulate(v.begin(), v.end(), 0, bit_xor<int>());

// 自訂（3512 Minimum Operations）
accumulate(v.begin(), v.end(), 0LL);  // 用 long long 避免 overflow
```

### unique（217 Contains Duplicate）
```cpp
sort(v.begin(), v.end());
auto it = unique(v.begin(), v.end());
v.erase(it, v.end());
// 或直接判斷：v.size() != set(v).size()
```

### iota
```cpp
vector<int> idx(n);
iota(idx.begin(), idx.end(), 0);  // [0, 1, 2, ..., n-1]
sort(idx.begin(), idx.end(), [&](int a, int b) { return nums[a] < nums[b]; });
```

### nth_element
```cpp
// O(N) 平均，找第 k 小的元素
nth_element(v.begin(), v.begin() + k, v.end());
// v[k] 就是第 k 小，左邊都 <= v[k]，右邊都 >= v[k]
// 注意：STL string::find 不是 KMP，是 Naive O(NM)
```

---

## Tree

### 遍歷模式對應

| 遍歷 | 代表題 | 特徵 |
|---|---|---|
| Inorder（左根右） | 94 | BST 中序是升序 |
| Preorder（根左右） | 144 | 用來重建樹 |
| Postorder（左右根） | 145 | 計算子樹資訊後更新父節點 |
| BFS Level Order | 102 | 層序，用 queue |
| DFS Path | 112 | root→leaf 路徑 |
| DFS Global | 543 | 後序 + global reference 更新答案 |
| DFS Backtracking | 113 | push/pop 收集完整路徑 |

### BST 性質
- 中序遍歷是升序
- Reverse Inorder 是降序（用於 538、1038 Greater Sum Tree）
- 查找 O(H)，H 為樹高；平衡 BST 則 O(log N)

---

## Graph

### BFS vs DFS 選擇

| 場景 | 選擇 |
|---|---|
| 最短路徑（無權重） | BFS |
| 連通分量、環偵測 | DFS 或 Union Find |
| 拓撲排序 | BFS（Kahn）或 DFS |
| 最短路徑（有權重） | Dijkstra |
| 最小生成樹 | Prim 或 Kruskal |

---

## 數學

### Overflow 處理
```cpp
// 常見易 overflow 場景
mid * mid        → 改用 mid == x / mid（69 Sqrt）
a + b            → 用 long long 或 unsigned
rev * 10 + digit → 先判斷 rev > INT_MAX / 10（7 Reverse Integer）
```

### GCD
```cpp
__gcd(a, b);  // C++14
gcd(a, b);    // C++17 <numeric>
```

### 質因數分解
```cpp
// O(sqrt(N))
while (n % 2 == 0) { factors.push_back(2); n /= 2; }
for (int i = 3; i * i <= n; i += 2)
    while (n % i == 0) { factors.push_back(i); n /= i; }
if (n > 1) factors.push_back(n);
```
