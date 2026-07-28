# Solution_0342

```cpp
/**
 * 註解：待補充
 */
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n-1)) == 0 && (n & 0x55555555) != 0;
    }
};
```
