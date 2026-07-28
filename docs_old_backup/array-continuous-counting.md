## <a name="array-continuous-counting"></a>🍱 Array - Continuous Counting (陣列 連續計數)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0485 | [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones) | 🟢 Easy | Array | [C++](./solution-pages/Solution_0485.md) | O(N) | O(1) | [Note](#0485-max-consecutive-ones)  |
| 0696 | [Count Binary Substrings](https://leetcode.com/problems/count-binary-substrings/) | 🟢 Easy | String / Greedy | [C++](./solution-pages/Solution_0696.md) | O(N) | O(1) | [Note](#0696-count-binary-substrings) |
| 1446 | [Consecutive Characters](https://leetcode.com/problems/consecutive-characters/) | 🟢 Easy | String | [C++](./solution-pages/Solution_1446.md) | O(N) | O(1) | [Note](#1446-consecutive-characters) |
| **1759** | [Count Number of Homogenous Substrings](https://leetcode.com/problems/count-number-of-homogenous-substrings/) | 🟢 Medium | Math / String | [C++](./solution-pages/Solution_1759.md)  | O(N) | O(1) | |

### 0485. Max Consecutive Ones
> [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones)<br>
>  travsal  nums ， num為1，count +1，否則為0，每次都更新ans值，ans為max<br>
>  **for(const int& num : nums) {** <br>
>  &emsp;&emsp;&emsp;&emsp;**count = (num & 1) ? count + 1 : 0;** <br>
>  &emsp;&emsp;&emsp;&emsp;**ans = max(ans, count);** <br>
>  **}** <br>


### 0696. Count Binary Substrings
> [Count Binary Substrings](https://leetcode.com/problems/count-binary-substrings/)<br>
> 如果前後字元相等，用curEquals計數目前連續個0或1的個數，**if(s[i] == s[i - 1]) curEquals++;** <br>
> 如果前後字元不相等，找出比較短那一半的長度， **min(preEquals, curEquals)** ，0001111 =3 ，111100 = 2<br>
> ans計算總共字串，**ans += min(preEquals, curEquals);**， 因為如果 0011 = 2，字串有 01和0011剛好2種<br>
> **preEquals = curEquals;curEquals = 1;** <br>

### 1446. Consecutive Characters
> [Consecutive Characters](https://leetcode.com/problems/consecutive-characters/)<br>
>  travsal s，s[i] == s[i - 1]，count +1，否則為1，每次都更新ans值，ans為max<br>
>  注意與 [485 Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones)的差異是本題count初始值為1<br>
>  **for(int i = 1; i < s.size(); i++) {** <br>
>  &emsp;&emsp;&emsp;&emsp;**count = (s[i] == s[i - 1]) ? count + 1 : 1;** <br>
>  &emsp;&emsp;&emsp;&emsp;**ans = max(ans, count);** <br>
>  **}** <br>


---

<br><br>
---

