## <a name="2d-array"></a>🍱 Array - 2D Array (陣列 二維陣列)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0048 | [Rotate Image](https://leetcode.com/problems/rotate-image/) | 🟡&nbsp;Medium | Array | [C++](./solution/Solution_0048.cpp.md) | O(n²) | O(1) | [Note](#0048-rotate-image) |
| 0073 | [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes) | 🟡 Medium | Array <br> Matrix | [C++](./solution/Solution_0073.cpp.md) | O(M*N) | O(1) | |
| 0832 | [Flipping an Image](https://leetcode.com/problems/flipping-an-image/) | 🟢 Easy | Array / Two Pointers | [C++](./solution/Solution_0832.cpp.md) | O(N * M) | O(1) | |
| 0867 | [Transpose Matrix](https://leetcode.com/problems/transpose-matrix/) | 🟢 Easy | Matrix | [C++](./solution/Solution_0867.cpp.md) | O(M*N) | O(M*N) | |
| 1252 | [Cells with Odd Values...](https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/) | 🟢 Easy | Array / Math | [C++](./solution/Solution_1252.cpp.md) | O(K + MN) | O(M + N) | |
| 1260 | [Shift 2D Grid](https://leetcode.com/problems/shift-2d-grid/) | 🟢 Easy | Array / Simulation | [C++](./solution/Solution_1260.cpp.md) | O(M * N) | O(K) |  |
| **1582** | [Special Positions in a Binary Matrix](https://leetcode.com/problems/special-positions-in-a-binary-matrix/) | 🟢 Easy | Array <br> Matrix | [C++](./solution/Solution_1582.cpp.md) | O(m * n) | O(m + n) |
| 1779 | [Find Nearest Point That Has the Same X or Y Coordinate](https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/) | 🟢 Easy | Array / Simulation / Manhattan Distance | [C++](./solution/Solution_1779.cpp.md) | O(N) | O(1) |  |
| 1886 | [Determine Whether Matrix Can Be Obtained By Rotation](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/) | 🟢 Easy | Array | [C++](./solution/Solution_1886.cpp.md) | O(n²) | O(1) |[Note](#1886-determine-whether-matrix-can-be-obtained-by-rotation) |
| 2022 | [Convert 1D Array Into 2D Array](https://leetcode.com/problems/convert-1d-array-into-2d-array) | 🟢 Easy | Array <br> Matrix <br> Simulation | [C++](./solution/Solution_2022.cpp.md) | O(m*n) | O(1) | [Note](#2022-convert-1d-array-into-2d-array) |
| 2319 | [Check if Matrix Is X-Matrix](https://leetcode.com/problems/check-if-matrix-is-x-matrix/) | 🟢 Easy | Array / Matrix | [C++](./solution/Solution_2319.cpp.md) | O(n²) | O(1) ||
| 2482 | [Difference Between Ones and Zeros in Row and Column](https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/) | 🟡 Medium | Matrix / Prefix Sum / Precomputation | [C++](./solution/Solution_2482.cpp.md) | O(M * N) | O(M + N) | [Note](#2482-difference-between-ones-and-zeros-in-row-and-column) |
| 2639 | [Find the Width of Columns of a Grid](https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/) | 🟢 Easy | Array / Simulation | [C++](./solution/Solution_2639.cpp.md) | O(M * N * D) | O(1)* | |
| 2923 | [Find Champion I](https://leetcode.com/problems/find-champion-i/) | 🟢 Easy | Array / Math | [C++](./solution/Solution_2923.cpp.md) | O(N²) | O(1) | |
| 3142 | [Check if Grid Satisfies Conditions](https://leetcode.com/problems/check-if-grid-satisfies-conditions/) | 🟢 Easy | Simulation <br> Array | [C++](./solution/Solution_3142.cpp.md)  | O(M * N) | O(1) | [Note](#3142-grid-note) |
| 3417 | [Zigzag Grid Traversal With Skip](https://leetcode.com/problems/zigzag-grid-traversal-with-skip/) | 🟢 Easy | Simulation | [C++](./solution/Solution_3417.cpp.md) | O(M * N) | O(M * N) | [Note](#3417-zigzag-note) |

### 0048. Rotate Image
> [Rotate Image](https://leetcode.com/problems/rotate-image/)<br>
> 先求轉置矩陣，每個row再取reverse<br>
---

### 0073. Set Matrix Zeroes
> [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes)<br>
> 用兩個bool紀錄 col[0]和cow[0]是否有0，把每個row和col有0的紀錄在cow[0]和col[0]，之後set 0，最後set col[0]和cow[0]是<br>
---

### 0867. Transpose Matrix
> [Transpose Matrix](https://leetcode.com/problems/transpose-matrix/)<br>
> Size mxn，New 一個 Vector nxm<br>
---

### 1886. Determine Whether Matrix Can Be Obtained By Rotation
> [Determine Whether Matrix Can Be Obtained By Rotation](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/)<br>
> 0048 Rotate Image的延伸，比對target matrix，rotate 比對4次<br>
---

### 2022. Convert 1D Array Into 2D Array
> [Convert 1D Array Into 2D Array](https://leetcode.com/problems/convert-1d-array-into-2d-array)<br>
> 注意邊界條件 **if(m * n != original.size()) return {};** <br>



### 2482. Difference Between Ones and Zeros in Row and Column
> [Difference Between Ones and Zeros in Row and Column](https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/)
> 要輸出結果矩陣，ans[i][j]為ith row 1的數量 - 0的數量加上 jth col 1的數量 - 0的數量<br>
> 第一個雙層loop計算每一row和每一col的值<br>
>  **for(int j = 0; j < n; j++) {** <br>
>  &emsp;&emsp;&emsp;&emsp;**for(int i = 0; i < m; i++) {** <br>
>  &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;**rowSum[i] += grid[i][j] ? 1 : -1;** <br>
>  &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;**colSum[j] += grid[i][j] ? 1 : -1;** <br>
>  &emsp;&emsp;&emsp;&emsp;**}** <br>
>  **}** <br>
> 第二個雙層loop計算輸出矩陣ans<br>
>  **for(int i = 0; i < m; i++) {** <br>
>  &emsp;&emsp;&emsp;&emsp;**for(int j = 0; j < n; j++) {** <br>
>  &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;**ans[i][j] += rowSum[i] + colSum[j];** <br>
>  &emsp;&emsp;&emsp;&emsp;**}** <br>
>  **}

<br><br>
---



