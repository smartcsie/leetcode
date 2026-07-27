## <a name="math-permutation"></a>🔢 Math Permutation(數學 排列)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0949 | [Largest Time for Given Digits](https://leetcode.com/problems/largest-time-for-given-digits/) | 🟡 Medium | Permutation / Math | [C++](./solution/Solution_949.cpp) | O(1) | O(1) | [Note](#0949-largest-time-for-given-digits)|


### 0949. Largest Time for Given Digits
> [Largest Time for Given Digits](https://leetcode.com/problems/largest-time-for-given-digits/)<br>
> **std::sort(arr.begin(), arr.end());int max_time = -1;** <br>
> **do {** <br>
> &emsp;&emsp;&emsp;&emsp;**int hour = arr[0] * 10 + arr[1];** <br>
> &emsp;&emsp;&emsp;&emsp;**int minute = arr[2] * 10 + arr[3];** <br>
> &emsp;&emsp;&emsp;&emsp;**if (hour < 24 && minute < 60) {** <br>
> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;**max_time = std::max(max_time, hour * 60 + minute);** <br>
> &emsp;&emsp;&emsp;&emsp;**}** <br>
> **} while (std::next_permutation(arr.begin(), arr.end()));** <br>
> **snprintf(buf, sizeof(buf), "%02d:%02d", max_time / 60, max_time % 60);** <br>

<br><br>
---


