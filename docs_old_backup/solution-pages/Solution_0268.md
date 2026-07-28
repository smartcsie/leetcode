# Solution_0268

```cpp
/**
 * 註解：待補充
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        return (1 + n) * n / 2 - accumulate(nums.begin(), nums.end(), 0);
    }
};

```
