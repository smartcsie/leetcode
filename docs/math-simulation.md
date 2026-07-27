## <a name="math-simulation"></a>🔢 Math - Simulation (數學模擬)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **0067** | [Add Binary](https://leetcode.com/problems/add-binary) | 🟢 Easy | Math <br> String | [C++](./solution/Solution_0067.cpp.md) | O(max(M, N)) | O(1) | [Note](#0067-add-binary) |
| 0415 | [Add Strings](https://leetcode.com/problems/add-strings) | 🟢 Easy | String / Math | [C++](./solution/Solution_0415.cpp.md) | O(max(N, M)) | O(max(N, M)) | [Note](#0415-add-strings) |
| 0989 | [Add to Array-Form of Integer](https://leetcode.com/problems/add-to-array-form-of-integer/) | 🟢 Easy | Simulation / Carry Propagation | [C++](./solution/Solution_0989.cpp.md) | O(max(N, log K)) | O(max(N, log K)) | |
| 1979 | [Find Greatest Common Divisor of Array](https://leetcode.com/problems/find-greatest-common-divisor-of-array/) | 🟢 Easy | Math / GCD | [C++](./solution/Solution_1979.cpp.md) | O(N) | O(1) | |
| 2293 | [Min Max Game](https://leetcode.com/problems/min-max-game/) | 🟢 Easy | Array / Simulation | [C++](./solution/Solution_2293.cpp.md) | O(N) | O(N) |  |
| 3894 | [Traffic Signal Color](https://leetcode.com/problems/traffic-signal-color/) | 🟢 Easy | Logic Control | [C++](./solution/Solution_3894.cpp.md) | O(1) | O(1) |  |


### 0067. Add Binary
> [Add Binary](https://leetcode.com/problems/add-binary)<br>
> 和 0415[Add Strings](https://leetcode.com/problems/add-strings) 幾乎一樣<br>
> i和j設定為a和b最後的index，i = a.size() - 1，j = b.size() - 1<br>
> **while(i >= 0 || j >= 0 || carry == 1) {** <br>
> &emsp;&emsp;&emsp;&emsp;**if(i >= 0) carry += a[i--] - '0';** <br>
> &emsp;&emsp;&emsp;&emsp;**if(j >= 0) carry += b[j--] - '0';** <br>
> &emsp;&emsp;&emsp;&emsp;**res.push_back((carry % 2) + '0');** <br>
> &emsp;&emsp;&emsp;&emsp;**carry /= 2;** <br>
> **}** <br>
> **reverse(res.begin(), res.end());** <br>
---

### 0415. Add Strings
> [Add Strings](https://leetcode.com/problems/add-strings) <br>
> 和 0067[Add Binary](https://leetcode.com/problems/add-binary) 幾乎一樣<br>
> i和j設定為num1和num2最後的index，i = num1.size() - 1，j = num2.size() - 1 <br>
> **while(i >= 0 || j >= 0 || carry !=0) {** <br>
> &emsp;&emsp;&emsp;&emsp;**f(i >=0) carry += num1[i--] - '0';** <br>
> &emsp;&emsp;&emsp;&emsp;**if(j >=0) carry += num2[j--] - '0';** <br>
> &emsp;&emsp;&emsp;&emsp;**res.push_back((carry % 10) + '0');** <br>
> &emsp;&emsp;&emsp;&emsp;**carry /= 10;** <br>
> **}** <br>
> **reverse(res.begin(), res.end());** <br>

---


<br><br>
---



