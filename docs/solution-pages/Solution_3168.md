# Solution_3168

```cpp
/**
 * 題目：3168. Minimum Number of Chairs in a Waiting Room
 * 難度：簡單 (Easy)
 * 描述：計算等待室中，為了容納所有客人所需的最小椅子數。
 * 'E' 代表客人進入，'L' 代表客人離開。
 *
 * 時間複雜度：O(N) - 單次遍歷，追蹤最多同時需要的椅子數。
 * 空間複雜度：O(1) - 僅使用常數空間。
 *
 * 解法思路：
 * 1. 維護一個 `count` 變數代表「當前在場人數」。
 * 2. 遍歷字串：
 * - 遇到 'E'：`count` 增加，並與 `ans` 取最大值（因為需要椅子的人數增加了）。
 * - 遇到 'L'：`count` 減少（客人離開，椅子釋放）。
 * 3. `ans` 的最大值即為同一時間內所需椅子的最大容量。
 */

class Solution {
public:
    int minimumChairs(std::string s) {
        int ans = 0;
        int count = 0;
        
        for (const char& c : s) {
            if (c == 'E') {
                count++;
                // 即時更新最大需求
                ans = std::max(ans, count);
            } else {
                count--;
            }
        }
        
        return ans;
    }
};

```
