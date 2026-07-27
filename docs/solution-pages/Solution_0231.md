# Solution_0231

```cpp
/**
 * 註解：待補充
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n-1)) == 0;
    }
};
```
