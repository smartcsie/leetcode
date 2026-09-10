# Binary Search 分類總覽

## 第一步：判斷屬於哪一種二分搜

拿到一題，先問自己「我在找什麼？」，答案決定了子分類：

| 我在找... | 子分類 | 特徵 |
|---|---|---|
| 陣列裡有沒有存在某個確切的值 | `binary-search`（籠統，精確值搜尋） | 判斷式有「等於/小於/大於」三個分支 |
| 陣列裡「第一個」滿足條件的位置 | `binary-search-find-left-bound` | 判斷式只有兩個分支（滿足/不滿足），答案偏左 |
| 陣列裡「最後一個」滿足條件的位置 | `binary-search-find-right-bound` | 判斷式只有兩個分支，答案偏右 |
| 一個**數值範圍**裡最小/最大的合法答案（不是在陣列索引上找） | `binary-search-on-answer` | 搜尋對象是「答案本身」，通常搭配一個 `feasible(x)` 檢查函式 |

**分辨「找邊界」跟「二分搜答案」最容易搞混的地方**：兩者程式碼長得
幾乎一樣（都是 `while` 收斂 + 判斷式切半），差別在於**搜尋的對象**——
在真實陣列的索引上收斂 → 找邊界；在一個獨立的數值範圍（例如
`[1, 10^9]`）上收斂、判斷式通常要另外呼叫一個檢查函式 → 二分搜答案。

## 第二步：選一種寫法流派（兩種都要會，但先選一種練熟）

### 收斂派（推薦優先練熟這個）

```cpp
int left = 0, right = n;  // 找左邊界時，right 從 n 開始（半開區間 [left, right)）
while (left < right) {
    int mid = left + (right - left) / 2;
    if (可能是答案) right = mid;      // 不用 -1，半開區間天生保留 mid
    else left = mid + 1;              // 確定不是答案才 +1，直接排除
}
return left; // 迴圈結束 left==right，就是答案
```

**口訣**：「可能是答案，留著（`right=mid`）；確定不是，踢掉（`left=mid+1`）。」

找右邊界只要把「找左邊界的判斷式」反過來，收斂完再手動 `-1`：
```cpp
int left = 0, right = n;
while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] > target) right = mid;   // 確定太大，排除
    else left = mid + 1;                    // <= target，可能是答案，先往右試探
}
int idx = left - 1; // 收斂完 left 停在「第一個 > target」的位置，答案要往前一格
```

### labuladong 派（閉區間，三個函式共用同一個骨架）

```cpp
// 精確值搜尋
while (left <= right) {
    if (nums[mid] < target) left = mid + 1;
    else if (nums[mid] > target) right = mid - 1;
    else return mid;  // 找到直接回傳
}

// 找左邊界（相等時不回傳，繼續往左逼近）
else right = mid - 1;   // 相等時
// 迴圈結束後要額外檢查：left >= n 或 nums[left] != target 就回傳 -1

// 找右邊界（相等時繼續往右逼近）
else left = mid + 1;    // 相等時
```

**布林條件版特例**（沒有「相等」分支，只有 true/false，例如 278）：
```cpp
while (left <= right) {
    if (isBadVersion(mid)) right = mid - 1;
    else left = mid + 1;
}
return left;  // 不用額外變數記錄，left 自然收斂到答案
```

### 兩種流派的取捨

| | 收斂派 | labuladong 派 |
|---|---|---|
| 迴圈條件 | `left < right` | `left <= right` |
| `right` 初始值 | `n`（半開區間） | `n - 1`（閉區間） |
| 找到候選時 | `right = mid`，不用 ±1 | `right = mid - 1`，要 -1 |
| 要額外變數記錄答案嗎 | 不用 | 陣列數值搜尋要；純布林條件不用 |
| 適合場景 | 保證答案存在、想要程式碼精簡 | 目標可能不存在、需要三分支清楚分開 |

⚠️ **常見 bug**：`else if(!isBadVersion(mid))` 這種寫法會讓同一個 `mid`
被判斷兩次（`if` 判斷一次、`else if` 又呼叫一次），邏輯上不影響答案，
但會讓呼叫次數多一倍，違背二分搜「減少呼叫次數」的初衷——直接用
`else` 就好，不要重複判斷。

## 目前收錄狀況分類表

| 分類 | 題目 |
|---|---|
| `binary-search`（精確值搜尋 + 特殊題） | 4、33、74、81、367、374、704 |
| `binary-search-find-left-bound` | 153、154、162、278、540、852、1351、2529 |
| `binary-search-find-right-bound` | 34、275、611（同題另有雙指標解法） |
| `binary-search-on-answer` | 69、378、441、1201、1608、2195 |

## 特殊題型備忘

- **4. Median of Two Sorted Arrays**：真正的最佳解（`O(log(min(M,N)))`）
  是在較短陣列上二分搜「切割點」，不是找值也不是找邊界，是這個分類
  裡最特殊的一種；用暴力雙指標合併版（`O(M+N)`）反而分類在
  `two-pointers-same`，兩版可以對照練習「暴力 vs 最佳解」。
- **300. Longest Increasing Subsequence** 的 `O(N log N)` patience
  sorting 解法用了 `lower_bound`，但主分類還是 `dp-lis`（演算法核心
  是貪心維護 tails 陣列，二分搜只是查詢子步驟）。
- **1930、1930** 一類看起來像二分搜、實際是別的技巧（貪心/DP）的題目，
  判斷準則是「拿掉二分搜的部分，這題的演算法核心還成立嗎？」——如果
  拿掉就整題垮掉，才是真的二分搜；如果只是拿二分搜當內部查詢工具，
  主分類應該給真正的演算法核心。
