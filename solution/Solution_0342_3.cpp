// 題目：342. Power of Four
// 難度：Easy
// 時間複雜度：O(1)
// 空間複雜度：O(1)
// 分類主題：math
// 技巧：對數判斷（log₂(n) 是偶數 ⇔ n 是 4 的冪）

class Solution {
public:
    bool isPowerOfFour(int n) {
        // 4 的冪一定是正數；0 與負數的 log 無意義（NaN / -inf），先排除
        if(n <= 0) return false;

        // 換底公式：log₂(n) = ln(n) / ln(2)
        // 若 n = 4^k = 2^(2k)，則 log₂(n) = 2k，一定是偶數
        // fmod(x, 2) 是浮點數取餘數（C++ 的 % 不能用在 double），
        // 餘 0 表示 log₂(n) 是偶數
        // 若 n 不是 2 的冪（如 3、5），log₂(n) 不是整數，餘數不會剛好為 0；
        // 若 n 是 2 的奇數次方（如 2、8、32），log₂(n) 是奇數，餘數為 1
        return (fmod(log(n) / log(2), 2) == 0);
    }
};