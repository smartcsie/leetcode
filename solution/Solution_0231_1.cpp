// 題目：231. Power of Two
// 難度：Easy
// 時間複雜度：O(1)
// 空間複雜度：O(1)
// 分類主題：math
// 技巧：對數判斷（log₂(n) 是整數 ⇔ n 是 2 的冪）

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 2 的冪一定是正數；0 與負數的 log 無意義，先排除
        if(n <= 0) return false;

        // 若 n = 2^k，則 log₂(n) = k，是整數
        // fmod(x, 1) 取小數部分（C++ 的 % 不能用在 double），
        // 小數部分為 0 表示 log₂(n) 是整數，即 n 是 2 的冪
        // 直接用 log2 比 log(n) / log(2) 精確，對 2 的冪通常能算出整數
        return fmod(log2(n), 1) == 0;
    }
};