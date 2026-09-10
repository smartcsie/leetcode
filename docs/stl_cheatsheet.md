# C++ STL Cheatsheet

## 通用演算法 `<algorithm>`

```cpp
sort(first, last);
sort(first, last, greater<int>());
reverse(first, last);
*max_element(first, last);
*min_element(first, last);
accumulate(first, last, init);          // <numeric>
count(first, last, x);
find(first, last, x);                   // 回傳 iterator
binary_search(first, last, val);        // 回傳 bool
lower_bound(first, last, val);          // 回傳 iterator，第一個 >= val
*upper_bound(first, last, val);         // 回傳 iterator，第一個 > val
```

✅ 你筆記有用過：`sort` `reverse` `max_element` `min_element` `accumulate` `count` `find` `binary_search` `lower_bound` `upper_bound`

---

## Array `<array>`

```cpp
array<int, 5> arr = {1, 2, 3, 4, 5};
arr[0];
arr.front();  arr.back();
arr.begin();  arr.end();
arr.rbegin(); arr.rend();
arr.empty();
arr.at(index);
arr.size();
```

✅ 你筆記有用過：`arr[]` `arr.size()` `arr.begin()` `arr.end()`

---

## Vector `<vector>`

```cpp
vector<int> vec(n, 10);
vector<int> vec = {10, 20, 30};
vector<int> vec(arr, arr + size);
vector<int> vec(vec2.begin(), vec2.end());
vector<vector<int>> vec;
vector<vector<int>> vec(n, vector<int>(m, 0));

vec.begin();  vec.end();
vec.rbegin(); vec.rend();
vec.front();  vec.back();
vec.empty();  vec.size();
vec[pos];
vec.push_back(num);  vec.pop_back();
vec.insert(pos, num);
vec.insert(pos, size, num);
vec.clear();
vec.erase(pos);
vec.erase(pos1, pos2);
vec.reserve(n);
vec.assign(n, val);
```

✅ 你筆記有用過：幾乎全部，常用 `push_back` `pop_back` `size` `empty` `begin` `end` `reserve` `erase` `insert`

---

## Set / Unordered Set `<set>` `<unordered_set>`

```cpp
set<int> s;                              // 升序
set<int, greater<int>> s;               // 降序
set<int> s = {1, 2, 3};
set<int> s(vec.begin(), vec.end());

s.insert(elem);
s.erase(val);
s.erase(it);
s.clear();
s.begin();  s.end();
s.size();   s.empty();
s.find(elem);                            // 回傳 iterator
s.count(elem);                           // 0 或 1
s.lower_bound(elem);
s.upper_bound(elem);

unordered_set<int> us;
```

✅ 你筆記有用過：`insert` `count` `find` `size` `empty` `begin` `end` `erase`

---

## Map / Unordered Map `<map>` `<unordered_map>`

```cpp
map<int, string> m;
map<int, string> m = {{1, "a"}, {2, "b"}};
map<int, string> m(vec.begin(), vec.end());

m.insert({key, val});
m[key] = val;
m.erase(key);
m.erase(it);
m.begin();  m.end();
m.size();   m.empty();
m.at(key);
m.find(key);                             // 回傳 iterator
m.count(key);                            // 0 或 1
m.clear();
m.upper_bound(key);
m.lower_bound(key);
m.contains(key);                         // C++20

unordered_map<int, int> um;
```

✅ 你筆記有用過：`insert` `[]` `count` `find` `size` `empty` `begin` `end` `contains`

---

## Stack `<stack>`

```cpp
stack<int> st;
st.push(num);
st.pop();
st.top();
st.empty();
st.size();
```

✅ 你筆記有用過：全部

---

## Queue `<queue>`

```cpp
queue<int> q;
q.push(num);
q.pop();
q.front();
q.back();
q.empty();
q.size();

queue<pair<int,int>> q;
```

✅ 你筆記有用過：全部

---

## Deque `<deque>`

```cpp
deque<int> dq;
dq.push_front(num);  dq.push_back(num);
dq.pop_front();      dq.pop_back();
dq.front();          dq.back();
dq.begin();          dq.end();
dq.empty();          dq.size();
dq.clear();
dq.erase(pos);
dq[pos];             dq.at(pos);
```

✅ 你筆記有用過：`push_back` `pop_front` `front` `back`（monotonic queue）

---

## Priority Queue `<queue>`

```cpp
priority_queue<int> pq;                         // max heap
priority_queue<int, vector<int>, greater<int>> pq;  // min heap

pq.push(num);
pq.pop();
pq.top();
pq.empty();
pq.size();
```

✅ 你筆記有用過：全部

---

## Utility `<utility>`

```cpp
pair<int, int> p;
p = make_pair(10, 20);
p = {10, 20};                            // C++11
p.first;  p.second;
auto [a, b] = p;                         // C++17 structured binding
```

✅ 你筆記有用過：`pair` `first` `second` structured binding

---

## 你筆記有用但上面沒列的

```cpp
// iota：填入連續整數
iota(vec.begin(), vec.end(), 0);          // [0,1,2,3,...]

// nth_element：部分排序
nth_element(first, nth, last);
nth_element(first, nth, last, comp);

// rotate：旋轉
rotate(first, middle, last);

// unique：去重（需先排序）
auto it = unique(vec.begin(), vec.end());
vec.erase(it, vec.end());

// next_permutation
next_permutation(first, last);

// __builtin 系列
__builtin_popcount(x);    // 1 的個數
__builtin_clz(x);         // 前導零個數
__builtin_ctz(x);         // 尾端零個數
```
